#include <Arduino.h>
#include "State.h"
#include "test.h"

enum blinks {
  PROGRAM_MODE = 300,
  DEPLOYMENT = 500
};

int led = 13;

blinks b;
State s;
IMU* i = NULL;
Altimeter* a = NULL;
Telemetry* t = NULL;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  delay(2000);
  i = s.getIMU();
  a = s.getAlt();
  t = s.getTrans();
}

void loop() {
  // edit
  // testing branch right now just for you guys
  // put your main code here, to run repeatedly:
  b = PROGRAM_MODE;
  digitalWrite(led, HIGH);
  delay(b);
  digitalWrite(led, LOW);
  delay(b);
  i->readAllData(true);
  a->readAllData();
  t->transmit(10.0);
  delay(1000);
  
}