#include "switch.h"
#import <Arduino.h>

int digital_pin_switch_left = 3;
int digital_pin_switch_right = 4;


void setup_switch()
{
  pinMode(digital_pin_switch_left, OUTPUT);
  pinMode(digital_pin_switch_right, INPUT);
  digitalWrite(digital_pin_switch_left, HIGH);
}

bool go_switch()
{
  return digitalRead(digital_pin_switch_right);
}

void print_switch()
{
  Serial.print(digitalRead(digital_pin_switch_right));
}

