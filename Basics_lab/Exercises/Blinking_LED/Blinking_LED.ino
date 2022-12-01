// TODO starting comment


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
