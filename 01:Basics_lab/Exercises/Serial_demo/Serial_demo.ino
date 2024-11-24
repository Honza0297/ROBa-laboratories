// Filename: Serial_demo.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains code that demonstrated possibilities of serial communication



/**********************************************

  - Send number in range <0, 255> to control brightness of LED
  - Use Serial Monitor or Serial Plotter

  IMPORTANT: When sending data select "No Line Ending" option  
**********************************************/

// Pin to which you connect the LED
#define LED_PIN 2

int brightness = 0;


// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin that you defined as an output.
  pinMode(LED_PIN, OUTPUT);

  // Start serial communication with baud rate of 9600
  Serial.begin(9600);
}



// The loop function runs over and over again forever
void loop() {

  // Check if there are data availible for reading
  if (Serial.available() > 0){
    brightness = Serial.parseInt(); // Read and parse integer

    // Adjust brightness of LED by value that was read from serial
    analogWrite(LED_PIN, brightness);

  }

  // Write data to serial
  Serial.println(brightness);

  // Delay to slow down sending data trough serial
  delay(100);
  
}



