/*
 * AVC ROBOTICS CLUB
 * Spring 2020 Rover Project
 * 
 * This class defines the instructions for the servos of the rover's
 * wheels. It receives and records a speed value from 0 - 90 and then
 * provides functions to control the rover's position by converting
 * the speed to an angle readable by the continuous servos and setting
 * the correct left and right wheel rotation direction for the desired
 * motion.
 * 
 * 0  - Rover is stopped
 * 90 - Rover is at max speed
 * 
 * Author:  Christian Baker
 * Version: 1.0
 * 
 * Last Modified: 18 March 2020
 */

#include "Wheels.h"

Wheels::Wheels() { }

void Wheels::Init(int pinFL, int pinFR,
                        int pinBL, int pinBR,
                        int startSpeed) {
  wheelFL.attach(pinFL);
  wheelFR.attach(pinFR);
  wheelBL.attach(pinBL);
  wheelBR.attach(pinBR);

  currSpeed = startSpeed;
}

int Wheels::GetSpeed() { return currSpeed; }

int Wheels::SetSpeed(int newSpeed) {
  if (newSpeed >= 0 && newSpeed <= 90) {
    currSpeed = newSpeed;
    return 0;
  } else {
    return -1;
  }
}

void Wheels::SetWheelDirection(int leftSpeed, int rightSpeed) {
  wheelFL.write(leftSpeed);
  wheelFR.write(rightSpeed);
  wheelBL.write(leftSpeed);
  wheelBR.write(rightSpeed);
}

void Wheels::Drive() {
  SetWheelDirection(90 + currSpeed, 90 - currSpeed);

  Serial.print("Drive: FL - ");
  Serial.print(wheelFL.read());
  Serial.print("    FR - ");
  Serial.print(wheelFR.read());
  Serial.print("    BL - ");
  Serial.print(wheelBL.read());
  Serial.print("    BR - ");
  Serial.println(wheelBR.read());
  Serial.println();
}

void Wheels::Reverse() {
SetWheelDirection(90 - currSpeed, 90 + currSpeed);
}

void Wheels::Stop() {
  SetWheelDirection(90, 90);

  Serial.print("Stop:  FL - ");
  Serial.print(wheelFL.read());
  Serial.print("    FR - ");
  Serial.print(wheelFR.read());
  Serial.print("    BL - ");
  Serial.print(wheelBL.read());
  Serial.print("    BR - ");
  Serial.println(wheelBR.read());
  Serial.println();
}

void Wheels::RotateRight() {  
  SetWheelDirection(90 + currSpeed, 90 + currSpeed);
}

void Wheels::RotateLeft() {
  SetWheelDirection(90 - currSpeed, 90 - currSpeed);
}

// TODO: Add functionality to turn a given degree given by the gyro
//         (Currently paused pending meeting on implementation)
