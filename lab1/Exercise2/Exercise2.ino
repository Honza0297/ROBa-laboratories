// TODO starting comment

// Pin on which you connect the LED
#define LED_PIN 15

// Set how long will be LED on in miliseconds
#define TIME_ON 1000

// Set how long will be LED off in milisecond
#define TIME_OFF 1000


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin that you defined as an output.
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(TIME_ON);                // wait for a given time
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(TIME_OFF);               // wait for a given time
}
