// todo top comment

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

  // Set one direction
  digitalWrite(CONTROL_PIN_1, HIGH);
  digitalWrite(CONTROL_PIN_2, LOW);

  // Accelerate smoothly
  for(int i = 0; i < 255; i++ ){
    analogWrite(ENABLE_PIN,i);
    delay(SLOW_DELAY);
  }
  // Hold max speed for 1 second
  delay(1000);
   // Deccelerate smoothly
  for(int i = 255; i >= 0; i-- ){
    analogWrite(ENABLE_PIN,i);
    delay(SLOW_DELAY);
  }


  // Change direction
  digitalWrite(CONTROL_PIN_1, LOW);
  digitalWrite(CONTROL_PIN_2, HIGH);

  // Accelerate smoothly
  for(int i = 0; i < 255; i++ ){
    analogWrite(ENABLE_PIN,i);
    delay(SLOW_DELAY);
  }
  // Hold max speed for 1 second
  delay(1000);
   // Deccelerate smoothly
  for(int i = 255; i >= 0; i-- ){
    analogWrite(ENABLE_PIN,i);
    delay(SLOW_DELAY);
  }


}
