// Filename: DC_transistor_solved.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains finished code that controls motor using only transistor

// Pin to which is transistor with motor connected
#define MOTOR_PIN 9

// Number of miliseconds that go to delay between increments in speed
#define SLOW_DELAY 10


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);  // sets the pin as output

}

void loop() {
   /**********************************************

  Implement acceleration and deacceleration of DC motor using PWM


  1. Accelerate the motor
    - Use for loop and function analogWrite(pin,value) 
    - Range for analogWrite is <0, 255>
    - After each call of analogWrite() call function delay(SLOW_DELAY) to slow down the acceleration

  2. Wait for a second at max RPM
    - Use function delay()

  3. Deaccelerate the motor
    - Use for loop and function analogWrite(pin,value) 
    - Range for analogWrite is <0, 255>
    - After each call of analogWrite() call function delay(SLOW_DELAY) to slow down the acceleration
  


  Write your code below this line
  **********************************************/



  // Start rotating smoothly from 0 to Max RPM
  for(int i = 0; i< 255 ; i++){
    analogWrite(MOTOR_PIN, i);      // Write given PWM 
    delay(SLOW_DELAY);              // Slow down the acceleration
  }

  // Delay to hold on at max RPM for a second
  delay(1000);

  // Stop rotating smoothly from Max to 0 RPM
  for(int i = 255; i >0 ; i--){
    analogWrite(MOTOR_PIN, i);      // Write given PWM 
    delay(SLOW_DELAY);              // Slow down the deacceleration
  }
  

}




