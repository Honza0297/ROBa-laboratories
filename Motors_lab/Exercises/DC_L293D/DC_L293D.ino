// Filename: DC_L293D.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains unfinished code that controls motor using L293D driver

// Enables/Diasables the motor
#define ENABLE_PIN 2 

// Controls pins for the motor
#define CONTROL_PIN_1 4
#define CONTROL_PIN_2 5

// Number of miliseconds that go to delay between increments in speed
#define SLOW_DELAY 10

void setup() {
  // Setup pins as output
  pinMode(ENABLE_PIN, OUTPUT); 
  pinMode(CONTROL_PIN_1, OUTPUT); 
  pinMode(CONTROL_PIN_2, OUTPUT); 

}

void loop() {
     /**********************************************

  Implement acceleration and deacceleration of DC motor for both directions of rotation


  1. Accelerate the motor clockwise 
    - Set rototation by writing correct values to control pins, use function digitalWrite()
    - Use for loop and function analogWrite(pin,value) where pin is enable pin
    - Range for analogWrite is <0, 255>
    - After each call of analogWrite() call function delay(SLOW_DELAY) to slow down the acceleration

  2. Wait for a second at max RPM
    - Use function delay()

  3. Deaccelerate the motor
    - Use for loop and function analogWrite(pin,value) 
    - Range for analogWrite is <0, 255>
    - After each call of analogWrite() call function delay(SLOW_DELAY) to slow down the acceleration

  4. Change the direction and repeat steps 1-3
  


  Write your code below this line
  **********************************************/




}
