#include "switch.h"
#import <Arduino.h>

int digital_pin_switch_out = 10;
int digital_pin_switch_in = 11;


void setup_switch()
{
  pinMode(digital_pin_switch_out, OUTPUT);
  pinMode(digital_pin_switch_in, INPUT);
  digitalWrite(digital_pin_switch_out, HIGH);
}

bool go_switch()
{
  return digitalRead(digital_pin_switch_in);
}

void print_switch()
{
  Serial.print(digitalRead(digital_pin_switch_in));
}

