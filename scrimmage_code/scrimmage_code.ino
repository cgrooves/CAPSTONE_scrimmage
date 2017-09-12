#include "sensor.h"
#include "motors.h"
#include "switch.h"
#include "other_functions.h"

enum ROBOT_STATE {OFF, DELIVERING, RETURNING};

enum ROBOT_STATE state;

void setup() {
  state = OFF;
  setup_sensor();
  setup_switch();
  Serial.begin(9600);
}

void loop() {
  Serial.print(state);
  //print_switch();
  Serial.println();
  // Cycle through state machine
  switch(state) {

    case OFF:
      power_down();
      if (go_switch()) {
        forward();
        state = DELIVERING;
      }
    break;

    case DELIVERING:
      if (sensor_detected()) {
        reverse();
        state = RETURNING;
      }
    break;

    case RETURNING:
      /*if (sensor_detected()) {
        power_down();
        state = OFF;
      }*/
    break;

  }

}
