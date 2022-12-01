// todo top comment



// Pin to which you connect the LED
#define LED_PIN 2

void setup() {

  // Set pin where LED is connected as output
  pinMode(LED_PIN, OUTPUT);
}



void loop() {
  /**********************************************

  Write code that will brightnen and dim LED

  Start at 0 brightness and progressivly increment number
  When you reach 255 do the opposite - start dimming by decrementing brightness

  Hints - Use for() loop
        - After each analogWrite() use delay(2) to slow down the LED fading
  
  
        MODIFY CODE BELLOW  
  **********************************************/
  

  int brightness = 10;
  
  analogWrite(LED_PIN, brightness);
  delay(2);

}
