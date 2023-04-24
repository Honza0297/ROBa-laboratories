// Filename: Blinking_LED.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains code that controls built-in LED on Arduino board


// The setup function runs once when you press reset or power the board
void setup() {
  
  // Initialize digital pin LED_BUILTIN as an output.
  // On Arduino Uno/Mega LED_BUILTIN is wired to pin 13
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED ON  (HIGH is the voltage level [+5 Volts])
  delay(1000);                       // Wait for 1000 miliseconds (1 second)
  digitalWrite(LED_BUILTIN, LOW);    // Turn the LED OFF (LOW is the voltage level [0 Volts])
  delay(1000);                       // Wait for 1000 miliseconds (1 second)
}
