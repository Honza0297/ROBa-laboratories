// todo main comment


// Import built-in library
#include <Servo.h>

// Pin to which servo is connected
#define SERVO_PIN 9 

// Create Servo object to control a servo
Servo myservo;  

void setup() {
  // Attaches the servo on given pin to the servo object
  myservo.attach(9);  
}

void loop() {


  /**********************************************

  Your assignment is to rotate servo from 0 to 180 degrees and back continuously

    1. You need to crate 2 for() loops 
      - First for loop to go from 0 to 180
      - Second one to go from 180 to 0
      - Make increments of 1 degree per step
      - For each step in loops pass the value into  myservo.write() function
      - After each write call function delay(10) to slow down the rotation

  Write your code below this line
  **********************************************/

  int angle = 90;


  // Sets servo angle
  myservo.write(angle);                        
}

