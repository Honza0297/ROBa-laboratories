



// Arduino cheat sheet for class ROBa 
// Contains all functions used in laboratories
// Taken from official arduino page: https://www.arduino.cc/reference/en/




  void setup() {
    // put your setup code here, to run once:
  
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
  }


  /* Configures the specified pin to behave either as an input or an output
   *    pin: the Arduino pin number to set the mode of.
   *    mode: INPUT, OUTPUT, or INPUT_PULLUP. See the Digital Pins page for a more complete description of the functionality.
   *    Returns: Nothing
  */
  pinMode(pin, mode)

  /*  Write a HIGH or a LOW value to a digital pin.
   *    pin: the Arduino pin number.
   *    value: HIGH or LOW.
   *    Returns: Nothing
   */
  digitalWrite(pin, value)
  
  
  /*  Reads the value from a specified digital pin, either HIGH or LOW.
   *    pin: the Arduino pin number you want to read
   *    Returns: HIGH or LOW
   */
  digitalRead(pin)

  
  /*  Writes an analog value (PWM wave) to a pin.
   *    pin: the Arduino pin to write to. Allowed data types: int.
   *    value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int.
   *    Returns: Nothing
   */
  analogWrite(pin, value)
  
  
  /*  Reads the value from the specified analog pin.
   *    pin: the name of the analog input pin to read from
   *    Returns: The analog reading on the pin (0-1023 for 10 bits or 0-4095 for 12 bits). Data type: int.
   * 
   */
  analogRead(pin)
  
  
  /*   Reads a pulse (either HIGH or LOW) on a pin.
   *    pin: the number of the Arduino pin on which you want to read the pulse. Allowed data types: int.
   *    value: type of pulse to read: either HIGH or LOW. Allowed data types: int.
   *    Returns: The length of the pulse (in microseconds)
   */
  pulseIn(pin, value)
  
  /*  Pauses the program for the amount of time (in milliseconds) specified as parameter
   *    ms: the number of milliseconds to pause. Allowed data types: unsigned long.
   *    Returns: Nothing
   */
  delay(ms)

  
  /*  Pauses the program for the amount of time (in microseconds) specified by the parameter
   *    us: the number of microseconds to pause. Allowed data types: unsigned int.
   *    Returns: Nothing
   */
  delayMicroseconds(us)

  
  /*  Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between, etc.
   *    value: the number to map.
   *    fromLow: the lower bound of the value’s current range.
   *    fromHigh: the upper bound of the value’s current range.
   *    toLow: the lower bound of the value’s target range.
   *    toHigh: the upper bound of the value’s target range
   *    Returns: The mapped value. Data type: long.
   */
  map(value, fromLow, fromHigh, toLow, toHigh)
  
