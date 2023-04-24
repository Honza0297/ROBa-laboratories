// Filename: PWM_fading_LED_solved.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains finished code that controls brightness of LED



// Pin to which you connect the LED
#define LED_PIN 2

void setup() {

  // Set pin where LED is connected as output
  pinMode(LED_PIN, OUTPUT);
}



void loop() {
  /**********************************************

  Write code that will brightnen and dim LED

  Start at 0 brightness and progressivly increment number
  When you reach 255 do the opposite - start dimming by decrementing brightness

  Hints - Use for() loop
        - After each analogWrite() use delay(2) to slow down the LED fading
  
  
        MODIFY CODE BELLOW  
  **********************************************/
  

  int brightness = 0;

  // Fade the LED from off to brightest:
  for (brightness = 0; brightness < 255; brightness++) {
    analogWrite(LED_PIN, brightness);
    delay(2);
  }
  
  
  // Fade the LED from brightest to off:
  for (brightness = 255; brightness >= 0; brightness--) {
    analogWrite(LED_PIN, brightness);
    delay(2);
  }

}
