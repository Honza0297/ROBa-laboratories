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
  double duty_cycle_double = DUTY_CYCLE_PERCENTAGE/100.0;


  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  // using delayMicroseconds() and not delay() because delay() works with miliseconds and takes only integer as argument
  // which would not allow to control PWM precisely
  delayMicroseconds(duty_cycle_double * CYCLE_LENGTH);                // wait for a given time

  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds((1 - duty_cycle_double) * CYCLE_LENGTH);          // wait for a given time
}
