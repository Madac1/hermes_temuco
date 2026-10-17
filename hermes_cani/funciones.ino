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

void imprimirDatos(int pos, int err, int derivada, int integral, int giro, int tp){
  Serial.print(pos);
  Serial.print("\t");
  Serial.print(err);
  Serial.print("\t");
  Serial.print(derivada);
  Serial.print("\t");
  Serial.print(integral);
  Serial.print("\t");
  Serial.print(giro);
  Serial.print("\t");
  Serial.println(tp);
}
