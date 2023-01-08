// todo top comment


// Pins for the stepper motor IN1-4 is for ULN2003 Stepper Motor Driver
#define STEPPER_1 11      // IN1  
#define STEPPER_2 10      // IN2
#define STEPPER_3 9       // IN3
#define STEPPER_4 8       // IN4

// Delay between every step
// After implementation change this number to ~200 to see blinkind leds at the motor driver
#define STEPPER_DELAY 2


// Sets output pins for desired value
//                   coil 1       coil 2       coil 3       coil 4 
void stepper_set(int value_1, int value_2, int value_3, int value_4) {
  /**********************************************

  Implement setting values to the output pins of Arduino

  1. Set given values to the coils of the stepper motor
      - Set all 4 values
      - Use digitalWrite(pin,value) function
        
  Write your code below this line
  **********************************************/
  digitalWrite(STEPPER_1, value_1);
  digitalWrite(STEPPER_2, value_2);
  digitalWrite(STEPPER_3, value_3);
  digitalWrite(STEPPER_4, value_4);
}


// Make one iteration to the right
// Iteration means magnetizing all 4 motor coils in given order
void iteration_right(){

  /**********************************************

  Implement rotation of of stepper motor clockwise

  1. Cycle trough one iteration of magnetizing motor coils
      - Set all 4 values in following order using function stepper_set()
        1.  1 0 0 0
        2.  0 1 0 0 
        3.  0 0 1 0 
        4.  0 0 0 1
      
      - After each function stepper_set() call function delay() with parameter STEPPER_DELAY
        
  Write your code below this line
  **********************************************/

    stepper_set(1, 0, 0, 0);
    delay(STEPPER_DELAY);

    stepper_set(0, 1, 0, 0);
    delay(STEPPER_DELAY);

    stepper_set(0, 0, 1, 0);
    delay(STEPPER_DELAY);
    
    stepper_set(0, 0, 0, 1);
    delay(STEPPER_DELAY);

}

// Make one iteration to the left
// Iteration means magnetizing all 4 motor coils in given order
void iteration_left(){

  /**********************************************

  Implement rotation of of stepper motor counter - clockwise

  1. Cycle trough one iteration of magnetizing motor coils
      - Set all 4 values in following order using function stepper_set()
        1.  0 0 0 1
        2.  0 0 1 0 
        3.  0 1 0 0 
        4.  1 0 0 0
      
      - After each function stepper_set() call function delay() with parameter STEPPER_DELAY
        
  Write your code below this line
  **********************************************/

    stepper_set(0, 0, 0, 1);
    delay(STEPPER_DELAY);

    stepper_set(0, 0, 1, 0);
    delay(STEPPER_DELAY);

    stepper_set(0, 1, 0, 0);
    delay(STEPPER_DELAY);

    stepper_set(1, 0, 0, 0);
    delay(STEPPER_DELAY);

}

  // Do not edit code under this line
  /******************************************************************/


void rotate_left(int loops){
  // Iterate 500 times to the left
  for (int i = 0; i < loops; i++) 
    iteration_left();
  
}

void rotate_right(int loops){
  // Iterate 500 times to the left
  for (int i = 0; i < loops; i++) 
    iteration_right();
  
}

void setup() {
  // Set up pins as outputs
  pinMode(STEPPER_1, OUTPUT);
  pinMode(STEPPER_2, OUTPUT);
  pinMode(STEPPER_3, OUTPUT);
  pinMode(STEPPER_4, OUTPUT);

}

void loop() {

  rotate_left(500);   // Rotate left 500 * 4 steps
  delay(1000);        // Small delay to see the motor stop

  rotate_right(500);  // Rotate right 500 * 4 steps
  delay(1000);        // Small delay to see the motor stop

}












