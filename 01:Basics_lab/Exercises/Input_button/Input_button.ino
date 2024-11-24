// Filename: Input_button.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains code that reads digital input from pin 4 and outputs its value at pin 2

int ledPin = 2;       // LED connected to digital pin 2
int buttonPin = 4;    // Button connected to digital pin 4
int val = 0;          // Variable to store the read value

void setup() {

  // Start serial communication for debugging purposes
  Serial.begin(9600);
  Serial.println("Beginning serial communication");
  
  pinMode(ledPin, OUTPUT);      // Sets the ledPinas output
  pinMode(buttonPin, INPUT);    // Sets the buttonPin as input
}

void loop() {
   // Read digital value from buttonPin
  val = digitalRead(buttonPin);  

  // Send value using serial communication
  Serial.println("Value:" + String(val));
  
  // Sets the LED to the button's value
  digitalWrite(ledPin, val);  

  // To slown down the serial communication
  delay(100); 

}
