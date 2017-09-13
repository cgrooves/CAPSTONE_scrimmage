#include "motors.h"
#include <Arduino.h>

int motor_step_pin = 9;
int motor_dir_pin = 8;
float base_frequency = 31250; // base PWM frequency for pin 9

void setup_motors() {
  // set both the step and the dir pins to OUTPUT
  pinMode(motor_step_pin,OUTPUT);
  pinMode(motor_dir_pin,OUTPUT);

  // Set the frequency for the pwm to be used on the
  // step pin
  setPwmFrequency(motor_step_pin, 64);

  // Set the step and dir pin to LOW initially
  digitalWrite(motor_step_pin,LOW);
  digitalWrite(motor_dir_pin,LOW);
}

void forward() {
  // Set the direction to forward and the
  // step signal
  analogWrite(motor_step_pin,150);
  digitalWrite(motor_dir_pin,FORWARD);
  
}

void reverse() {
  // Set the direction to backwards and
  // set the step signal
  analogWrite(motor_step_pin,150);
  digitalWrite(motor_dir_pin,BACKWARD);

}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
