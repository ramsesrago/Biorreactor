
int pwmMotor1;
int pwmMotor2;
int pwmLight;

void setVelocity(int selMotor, int velocity) {
  //if((velocity >= 0) && (velocity <= 100))
  {
    switch(selMotor){
      case MOTOR_OUT1:  pwmMotor1 = map(velocity, -5, 5, 255, 0);
                        analogWrite(MOTOR_OUT1, pwmMotor1);
                        Serial.println(pwmMotor1);
                        break;
      case MOTOR_OUT2:  pwmMotor2 = map(velocity, -5, 5, 255, 0);
                        analogWrite(MOTOR_OUT2, pwmMotor2);
                        break;
      case LIGHT_INPUT: pwmLight = map(controlLight, -20, 770, 255, 0);
                        analogWrite(LIGHT_OUT_PID, pwmLight);
                        break;
      default: break;
    }
  }
}
