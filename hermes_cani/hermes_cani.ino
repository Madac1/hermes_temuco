#include "pines.h"
#include <QTRSensors.h>
#define NUM_SENSORS         6 // Número sensores usados
#define NUM_SAMPLES_PER_SENSOR  4 // Muestras por sensor (DEJAR EN 4)
#define EMITTER_PIN             11    // Pin del emisor

// Se crea la variable que representa al sensor
QTRSensorsAnalog qtra ((unsigned char[]) {
  5, 4, 3, 2, 1, 0
},
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS]; // Lista para guardar las lecturas

#define BOTON 12
 
// VARIABLES Y CONSTANTES PARA CALIBRAR
int Tp = 0; // Target power o velocidad base
float Kp = 0.39; // constante proporcional (+ 0.01 - 0.01)
float Ki = 0.001; // (+-0.0001)
float Kd = 0.1; // (+-0.001)
int ref = 0; // referencia o centro
xz
// variables para el PID
int ultimoError = 0;
long integral = 0;

bool datos = 0;

// Configuración, corre una vez al inicio
void setup() {
  //Se inicia la comunicación serial
  Serial.begin(9600);
  motorSetup();
  
  // probarMotores(100);
    Serial.println("Listo para calibrar... \n");
    esperarBoton();
  moverMotores(40,-40); // se queda moviendo calibrando
    Serial.println("Calibrando... \n");
  calibrar();
    Serial.println("Calibracion lista, esperando inicio... \n");
  moverMotores(0,0); // se detiene despues de calibrar
  esperarBoton();
  
    Serial.println("Siguiendo la linea... \n");
    Serial.flush(); // limpia el monitor serial
      Serial.print("Error Proporcional Derivada Integral Giro\n");
}


void loop() {
  qtra.read(sensorValues);  // lectura de valores de sensores
  int posicion = qtra.readLine(sensorValues, true , false ); // leemos la linea, me guarda un dato de 0 a 5000
  posicion = map(posicion, 0, 5000, -255, 255); // mapeo de valor de posicion para dejarlo en un valoe entre -255 y 255

  leerBluetooth();
 
  int error = posicion - ref;
  integral = integral + error;
  int derivada = error - ultimoError;
  int giro = Kp * error + Ki * integral + Kd * derivada;
  ultimoError = error;
  if(datos){
    imprimirDatos(error, Kp * error, Kd * derivada, Ki * integral, giro);
  }
  // giro diferencial
  int velIzq = Tp + giro;
  int velDer = Tp - giro;
  moverMotores(velIzq,velDer);
}
