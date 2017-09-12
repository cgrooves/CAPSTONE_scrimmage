#ifndef SENSOR_H
#define SENSOR_H

// Assigns and sets up pins appropriately for QRD
// sensor looking for a black tape on the Arduino.
void setup_sensor();

// Returns a true if black is detected; Otherwise
// returns a false.
bool sensor_detected();

void print_sensor();

#endif
