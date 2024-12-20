// Filename: HC-SR04_ranging.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains unfinished code that measures distance using sensor HC-SR04 with use of active waiting

#define echoPin 2 // Attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // Attach pin D3 Arduino to pin Trig of HC-SR04

long duration;   // Variable for the duration of sound wave travel
double distance; // Variable for the distance measurement

double speed_of_sound = 0.034;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  
  Serial.begin(9600);       // Start serial communication 
  Serial.println("Started serial communication"); 
}


void loop() {

  // Make pulse of lenght 10 microseconds as per documentation
  // https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

  /**********************************************

  Your assignment is to get measure distance using HC-SR04 ultrasonic distance sensor

  1. Start ranging
    - Make pulse of length 10 microseconds using functions digitalWrite() and delayMicroseconds()

  2. Get the response
    - Use function pulseIn(echoPin, HIGH) and store the result in durtation variable

  Now you have stored the time it took to travel sound from sonar to obstacle and back.
  In order to get result in meaningfull units (like centimeters) you neeed to transform duration into distance

  3. Calculate distance
    - Multiply the duration with speed_of_sound variable. Dont forget to divide the result by 2 (soundwave travels twice the distance)
    - Result will be in cm
  
  See the Serial monitor/plotter for results.


  Write your code bellow this line
  **********************************************/
  







  // Do not edit code under this line
  /******************************************************************/

  // slow down the code little bit
  delay(100);

  // Pretty print the results using Serial communication
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
}
