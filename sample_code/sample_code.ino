/*
 * Outline
 */

#define OBSTACLE_DISTANCE 10

#include "motors.h"
#include "gyro.h"
#include "sensors.h"

// Define global variables for pin numbers

void setup() {
  // initialize ultrasonic sensors
  // attach motors
  // initialize gyro
}


void loop() {

  // check if there's an obstacle
  if (getDistance() < OBSTACLE_DISTANCE) {
    
    stopMotors();
    wait(250);
    
    // check if there's still an obstacle
    if (getDistance() < OBSTACLE_DISTANCE) {
      rotate(180); // turn around
      
      // Note: the rotate function will use the gyro data
      // to figure out when to stop turning.
    }
  }
  // no obstacle 
  else {
    runMotors(10); // go forward at speed 10
  }

}
