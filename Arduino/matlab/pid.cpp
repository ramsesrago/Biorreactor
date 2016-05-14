#include "pid.h"
#include <Arduino.h>

PID::PID(double _kP, double _kI, double _kD, double _setPoint){
    kP = _kP;
    kI = _kI;
    kD = _kD;
    setPoint = _setPoint;
  }

   void PID::addNewSample(double _sample){
    sample = _sample;
  }

  double PID::process(){
    error = setPoint - sample;
    float deltaTime = (millis() - lastProcess) / 1000.0;
    lastProcess = millis();
    
    //P
    P = error * kP;
    
    //I
    I = I + (error * kI) * deltaTime;
    
    //D
    D = (lastSample - sample) * kD / deltaTime;
    lastSample = sample;
    
    // Soma tudo
    pid = P + I + D;
    
    return pid;
  }
