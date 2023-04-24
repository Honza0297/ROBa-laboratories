// Filename: PWM_custom_method.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains code that controls LED using custom PWM implementation

// Pin to which you connect the LED
#define LED_PIN 2


/**********************************************

  Length of duty cycle in percentages % (So the number should be in range <0,100>)
  
  Your assignment is to change value of DUTY_CYCLE_PERCENTAGE

  Set its value to 1, 2, 5, 10, 100 and observe behaviour of LED

  Also try your own values

    +--------+                         +-------
    |        |                         |
    |        |                         |
    |        |                         |  
 ---+        +-------------------------+
    <-------->
    DUTY_CYCLE_PERCENTAGE

    <---------------------------------->
    CYCLE_LENGTH
    
**********************************************/
#define DUTY_CYCLE_PERCENTAGE 10


// Length of PMW cycle of 20 milisecond (2000 is number of microseconds)
#define CYCLE_LENGTH 2000


// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin that you defined as an output.
  pinMode(LED_PIN, OUTPUT);
}



// The loop function runs over and over again forever
void loop() {


  // Transforms integer from range <0,100> into double with range <0,1>
  double duty_cycle_double = DUTY_CYCLE_PERCENTAGE/100.0;


  digitalWrite(LED_PIN, HIGH);   // Turn the LED on (HIGH is the voltage level)

  // Using delayMicroseconds() and not delay() because delay() works with miliseconds and takes only integer as argument
  // which would not allow to control PWM precisely
  delayMicroseconds(duty_cycle_double * CYCLE_LENGTH);                // Wait for a given time, uses active waiting


  digitalWrite(LED_PIN, LOW);    // Turn the LED off by making the voltage LOW
  delayMicroseconds((1 - duty_cycle_double) * CYCLE_LENGTH);          // Wait for a given time, uses active waiting
}
