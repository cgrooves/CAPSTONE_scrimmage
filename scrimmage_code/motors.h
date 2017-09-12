#ifndef MOTORS_H
#define MOTORS_H

// Sets up the pins on the arduino to be used
// with the motors.
void setup_motors();

// Sends the signal for the motor to drive forward.
void forward();

// Sends the signal for the motor to drive in reverse.
void reverse();

#endif
