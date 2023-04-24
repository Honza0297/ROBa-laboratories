// Filename: Stepper_library_solved.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains finished code that controls stepper motor using library Stepper.h

//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);


void setup() {
	// Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {

  /**********************************************

  Implement next set of steps 

  For this use functions myStepper.setSpeed(RPM) and myStepper.step(steps)

  1. Rotate motor 90° clockwise with speed of 5RPM
  2. Wait 1 second
  3. Rotate motor 270° counter-clockwise with speed of 15RPM
  4. Wait 1 second
  5. Return motor to starting position
   

  Write your code below this line
  **********************************************/

	// Rotate motor 90° clockwise with speed of 5RPM
  myStepper.setSpeed(5);
  myStepper.step(stepsPerRevolution/4);
  delay(1000);
	
	// Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(15);
	myStepper.step(-stepsPerRevolution*3/4);
	delay(1000);

  	// Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(15);
	myStepper.step(stepsPerRevolution/2);
	delay(1000);

}



