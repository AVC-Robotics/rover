/*
 * AVC ROBOTICS CLUB
 * Spring 2020 Rover Project
 * 
 * Author:  Christian Baker
 * Version: 1.0
 * 
 * Last Modified: 18 March 2020
 */

#ifndef WHEELS_H
#define WHEELS_H

#include "Arduino.h"
#include <Servo.h>


class Wheels {
  public:
    Wheels();

    void Init(int pinFL, int pinFR,
              int pinBL, int pinBR,
              int startSpeed);

    int GetSpeed();                 // Return current speed
    int SetSpeed(int newSpeed);     // Set a new speed

    void Drive();                   // Make wheels go forward
    void Reverse();                 // Make wheels go backward
    void Stop();                    // Make wheels halt
    void RotateRight();             // Make wheels rotate right
    void RotateLeft();              // Make wheels rotate left
  private:
    Servo wheelFL;                  // Front left wheel servo object
    Servo wheelFR;                  // Front right wheel servo object
    Servo wheelBL;                  // Back left wheel servo object
    Servo wheelBR;                  // Back right wheel servo object

    int currSpeed  =  0;            // Current speed of rover (0-90)

    // Sets the given rotation direction for left and right side
    void SetWheelDirection(int leftSpeed, int rightSpeed);
};

#endif
