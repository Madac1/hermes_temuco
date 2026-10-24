void calibrar(){
  moverMotores(40, -40);
  //Se calibra el sensor
  for (int i = 0; i < 400; i++) {
    qtra.calibrate();
  }
  
  moverMotores(0, 0);
}

void esperarBoton(){
// espera a que se pulse el boton para hacer cosas
  while(true){
    if(digitalRead(BOTON) == 1){
      break; // break nos saca del while
    }
  }
  
}

void probarMotores(int vel){
  // mueve de forma secuencial los motores
  moverMotores(vel, 0);
  delay(1000);
  moverMotores(0, vel);
  delay(1000);
  moverMotores(-vel, 0);
  delay(1000);
  moverMotores(0, -vel);
  delay(1000);
  moverMotores(0, 0);
  delay(1000);
  }

void imprimirDatos(int err, int prop, int derivada, int integral, int giro){
  Serial.print(err);
  Serial.print("\t");
  Serial.print(prop);
  Serial.print("\t");
  Serial.print(derivada);
  Serial.print("\t");
  Serial.print(integral);
  Serial.print("\t");
  Serial.print(giro);
  Serial.print("\n");
}


void leerBluetooth(){
    // Revisar si hay algo escrito en el monitor serial
  if (Serial.available() > 0) {
    char letra = Serial.read();  // Leer una letra
    // se toma la decicion de que variable cambiar
    switch (letra){
      case '1':
        Kp += 0.01;
        Serial.print("Kp:");
        Serial.println(Kp);
        break;
      case '2':
        Kp -= 0.01;
        Serial.print("Kp:");
        Serial.println(Kp);
        break;
      case '3':
        Ki += 0.001;
        Serial.print("Ki:");
        Serial.println(Ki);
        break;
      case '4':
        Ki -= 0.001;
        Serial.print("Ki:");
        Serial.println(Ki);
        break;
      case '5':
        Kd += 0.01;
        Serial.print("Kd:");
        Serial.println(Kd);
        break;
      case '6':
        Kd -= 0.01;
        Serial.print("Kd:");
        Serial.println(Kd);
        break;
      case '7':
        Tp += 1;
        Serial.print("Tp:");
        Serial.println(Tp);
        break;
      case '8':
        Tp -= 1;
        Serial.print("Tp:");
        Serial.println(Tp);
        break;
        /*
      case '9':
        datos = !datos;
        Serial.print("Se alterno la impresion de datos\n");
        Serial.flush();
      Serial.print("Error Proporcional Derivada Integral Giro\n");
        break;
        */
    }
  }
  
}
