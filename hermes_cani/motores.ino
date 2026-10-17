void motorSetup(){
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
}

void motor(int i1, int i2, int pwm, int vel)
{
  if (vel > 0 ){
    // enviar un par de señales para indicar la direccion
      digitalWrite(i1,HIGH);
      digitalWrite(i2,LOW);
  
  }
  else if(vel < 0 ){
      digitalWrite(i1,LOW);
      digitalWrite(i2,HIGH);
  }
  else if (vel  == 0){
      digitalWrite(i1,LOW);
      digitalWrite(i2,LOW);
  }
  analogWrite(pwm, abs(vel));
}

void moverMotores(int velIzq, int velDer)
{
  motor(AI1, AI2, PWMA, velIzq); // motor izquierdo (canal A)
  motor(BI1, BI2, PWMB, velDer); // motor derecho (canal B)
}
