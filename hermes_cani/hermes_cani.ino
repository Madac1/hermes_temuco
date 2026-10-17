#include <QTRSensors.h>
#include "pines.h"

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


void setup() {
  Serial.begin(9600); // inicializar comunicacion serial
  motorSetup(); // configuramos los motores
  Serial.println("");
  // probarMotores();
  esperarBoton();
  calibrar();
  esperarBoton();
}

void loop() {

}
