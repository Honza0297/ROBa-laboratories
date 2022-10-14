// TODO starting comment

// Pin on which you connect the LED
#define LED_PIN 15

// Set length of duty cycle in percentages % (So the number should be in range <0,100>)
#define DUTY_CYCLE_PERCENTAGE 10

// Length of PMW cycle of 20 milisecond (2000 is number of microseconds)
#define CYCLE_LENGTH 2000


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin that you defined as an output.
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  /**************************************************************
   *              MODIFY CODE BELOW                             *
   **************************************************************/

  double duty_cycle_double = DUTY_CYCLE_PERCENTAGE/100.0;

  //for cycle for brightening LED
  for(int i = 0; i < 100; i++){
    duty_cycle_double = i/100.0;
    digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(duty_cycle_double * CYCLE_LENGTH);                // wait for a given time

    digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds((1 - duty_cycle_double) * CYCLE_LENGTH);           // wait for a given time
  }

  //for cycle for dimming LED
  for(int i = 100; i > 0; i--){
    duty_cycle_double = i/100.0;
    digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(duty_cycle_double * CYCLE_LENGTH);                // wait for a given time

    digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds((1 - duty_cycle_double) * CYCLE_LENGTH);           // wait for a given time
  }
}
