// todo top comment

int ledPin = 2;       // LED connected to digital pin 2
int buttonPin = 4;    // Button connected to digital pin 4
int val = 0;          // Variable to store the read value

void setup() {

  // Start serial communication for debugging purposes
  Serial.begin(9600);
  Serial.println("Beginning serial communication");
  
  pinMode(ledPin, OUTPUT);      // Sets the ledPinas output
  pinMode(buttonPin, INPUT);    // Sets the buttonPin as input
}

void loop() {
   // Read digital value from buttonPin
  val = digitalRead(buttonPin);  

  // Send value using serial communication
  Serial.println("Value:" + String(val));
  
  // Sets the LED to the button's value
  digitalWrite(ledPin, val);  

  // To slown down the serial communication
  delay(100); 

}
