#include <math.h>
#include <Intel_Edison_BT_SPP.h>
#include "pid.h"

/* Motors defines */
#define MOTOR_OUT1      (5)
#define MOTOR_OUT2      (6)

/* Temperature defines */
#define TEMP_INPUT      (A0)
#define TEMP_OUT_PID    (9)
#define TEMP_SET_POINT  (32) 

/* PH defines */
#define PH_INPUT         (A1)

/* Light defines */
#define LIGHT_INPUT      (A2)
#define LIGHT_OUT_PID    (9)
#define LIGHT_SET_POINT  (32) 

/* Define the number of samples */
int numberOfSamples = 500;

/* Temperature sensor */
const int b = 4275;   // thermistor b value
const int R0 = 100000; // R0 = 100k
float temperature;
int readTemp;

/* Bluetooth instance */
Intel_Edison_BT_SPP spp = Intel_Edison_BT_SPP();
int validData = -1;

/* Control temp */
PID tempPID(1.1, 0, 0, 31);

int velocity = 0;

/* Control light */
PID lightPID(1.5, 0, 0, 730);
int light = 50;
int controlLight = 0;

/* PH sensor */
int PH;

void setup() 
{
  int i = 200;
  Serial.begin(9600);
  Serial1.begin(115200);
  setupBluetooth();
  setupRungeKutta();
  calcRungeKutta();
  //temperature = getTemperature();
}

void loop() 
{  
//  /* Control temperature */
//  temperature = getTemperature();
//  Serial.print("Temperature: ");
//  Serial.println(temperature);
//  tempPID.addNewSample(temperature);
//  velocity = (tempPID.process());
//  if(temperature < 31) {
//    setVelocity(MOTOR_OUT1, velocity);
//    setVelocity(MOTOR_OUT2, 0);
//  }
//  else {
//    setVelocity(MOTOR_OUT1, 0);
//    setVelocity(MOTOR_OUT2, velocity);
//  }
//  Serial.print("Speed fan: ");
//  Serial.println(velocity);
//
//  /* Control light */
//  light = getLight();
//  Serial.print("Light: ");
//  Serial.println(light);
//  lightPID.addNewSample(light);
//  controlLight = (lightPID.process());
//  setVelocity(LIGHT_INPUT, controlLight);
//  Serial.print("Controlled light: ");
//  Serial.println(controlLight);
//
//  /* PH notification, range between 1 and 14, 7 is normal */
//  PH = getPH();
//  Serial.print("PH measured is: ");
//  Serial.println(PH);
  /*
  if(Serial1.available() > 0) {
    data = Serial1.read();
  }
  else {
    //Serial.println("NO");
  }
  Serial.println(data);*/
}

 void setupBluetooth() {
  spp.open();
}

