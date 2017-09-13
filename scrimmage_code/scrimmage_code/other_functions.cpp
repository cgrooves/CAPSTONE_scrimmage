#include "other_functions.h"
#include "sensor.h"
#include "motors.h"
#include "switch.h"
#include <Arduino.h>

void power_down() {
  for (int i=0; i<13; i++)
  {
    digitalWrite(i,LOW);
  }
}

