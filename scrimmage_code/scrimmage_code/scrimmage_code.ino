#include "sensor.h"
#include "motors.h"
#include "switch.h"
#include "other_functions.h"

enum ROBOT_STATE {OFF, DELIVERING, RETURNING};

enum ROBOT_STATE state;

// Set timer count to make sure the first time the
// line is crossed, the sensor doesn't trip
int timer_count = 0;
bool timer_go = false;
const int timer_threshold = 3000;

void setup() {
  state = OFF;
  power_down();
  setup_switch();
  setup_motors();
  Serial.begin(9600);
}

void loop() {
  Serial.print(state);
  print_sensor();
  Serial.println();
  // Cycle through state machine
  switch(state) {

    case OFF:
      if (go_switch()) {
        timer_go = true; // start timer
        forward(); // start moving forward
        setup_sensor(); // initialize sensor
        state = DELIVERING;
      }
    break;

    case DELIVERING:
      if (sensor_detected() && timer_count > timer_threshold) { // make sure that the sensor has had time to pass start line
        reverse(); // if another black line is detected, go backwards
        state = RETURNING; // change state
      }
    break;

    case RETURNING:
      /*if (sensor_detected()) {
        power_down();
        state = OFF;
      }*/
    break;

  }

  timer_count++;

}
