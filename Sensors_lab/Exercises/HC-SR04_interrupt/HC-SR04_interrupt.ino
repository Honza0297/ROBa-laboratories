// Filename: HC-SR04_interrupt.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains code that measures distance using sensor HC-SR04 with use of interrupts


#define echoPin 2 // Attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // Attach pin D3 Arduino to pin Trig of HC-SR04


unsigned long start_time; // Start time of the pulse
unsigned long end_time;   // End time of the pulse

unsigned long duration = 0;   // Difference between start and of the pulse - duration 
unsigned long distance = 0;   // Variable for the distance measurement

bool pulse = false;       // Variable that says if whole pulse was detected



void setup() {

  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach interrupt to pin and set callback function
  attachInterrupt(digitalPinToInterrupt(echoPin), change, CHANGE); 

  // Start serial communication
  Serial.begin(9600);

  // make starting pulse
  make_pulse();

}

void loop() {


  // If there was pulse from HC-SR04 (sonar)
  if(pulse){

    // Calculate the distance with given duration using speed of sound
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Make pulse for another reading
    make_pulse();

  }


  /****************/
  /* HERE you can write any code to be executed since the sonar is non blocking */
  /****************/

  // delay can be used to slow down program
  delay(100);
  
}

    // Make pulse of lenght 10 microseconds as per documentation
    // https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
void make_pulse(){
  
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);       
    digitalWrite(trigPin, LOW);


}




// Function that gets called when interrupt is evoked at echoPin
void change(){

  // There cant be 2 interrupts on one pin (FALL and RIS), so workaround is needed 
  if(digitalRead(echoPin) == HIGH){
    // if rising edge is detected, get the time it started
    start_time = micros();
    
  }else{
    // if falling edge is detected, get the time and calculate the difference (which is how long it took the sound to travel)
    end_time = micros();
    duration = end_time - start_time;
    pulse = true; // set helping variable so that in main loop its know that pulse happend
  }
}