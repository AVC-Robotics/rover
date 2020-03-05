// define motor functions

// set speed of four motors in the appropriate directions
void runMotors(int speed) {
	// speed should be between -90 (backwards full speed) and +90 (forwards full speed)
  // Note that the servos take values between 0 and 180. 
  // Also note that two motors will have to run in "reverse" due to they way they will be attached.
}

// stop all four motors
void stopMotors() {
	
}

// rotate in place for the specified number of degrees
void rotate(int angle) {
	// should be able to handle any angle between -360 and +360
  // 0 degress is straight ahead, positive values to the right

  // Note: the gyro should return an ABSOLUTE angle, but this 
  // function should work with RELATIVE angles. In other words,
  // if the angle argument to this function is +90 degrees, it 
  // means "turn to 90 degrees to the right", not "turn to the
  // 90 degree position".
  
	// Note: don't write return statement until turn is complete
}
	
