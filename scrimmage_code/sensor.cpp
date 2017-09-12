#include "sensor.h"
#import <Arduino.h>

int digital_pin_pd = 2;
int analog_pin_sensor = 0;
int limit = 900;

void setup_sensor()
{
  pinMode(digital_pin_pd, OUTPUT);
  digitalWrite(digital_pin_pd, HIGH);
}

bool sensor_detected()
{
  int val = analogRead(analog_pin_sensor);
  //Serial.print(val);
  //Serial.println();
  if(val >= limit)
  {
    return true;
  }
  else
  {
    return false;
  }
}

