// todo top comment


#define echoPin 2 // Attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // Attach pin D3 Arduino to pin Trig of HC-SR04


unsigned long start_time; // Start time of the pulse
unsigned long end_time;   // End time of the pulse

unsigned long time_of_current_pulse  = 0;   // Needed to calculate speed
unsigned long time_of_previous_pulse = 0;   // Needed to calculate speed
double time_between_pulses    = 0;   // Needed to calculate speed

#define MILL_TO_SEC 10000000.0


unsigned long duration = 0;   // Difference between start and of the pulse - duration 

long current_distance = 0;   // Variable for the current distance measurement
long previous_distance = 0;   // Variable for the previousdistance measurement


double speed = 0;             // Variable for calculated speed

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
    current_distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

    /**********************************************

    Write code that takes read distance, previous distance and time difference and calculates speed from that
    (mathematically derivation)

    Steps:

    1. Calculate time between pulses
      - Time of previous pulse is stored in variable time_of_previous_pulse
      - Time of current pulse is stored in variable time_of_current_pulse
      - Subtract these numbers from eachother and divide the result by MILL_TO_SEC (milliseconds to seconds)
      - Save the result in variable time_between_pulses

    2 Calculate speed itself
      - Formula for calculating speed = distance/time
      - Where distance is difference between current distance and previous distance
        and time is time between pulses
      - Save the result into Speed variable

    3. In order to get result in meters per second, you need to divide the speed by 100.0
      

    Write your code below this line
    **********************************************/
    time_between_pulses = (time_of_current_pulse - time_of_previous_pulse)/MILL_TO_SEC;

    speed = ( current_distance - previous_distance)/ time_between_pulses;
    speed = speed / 100.0;






    // Do not edit code under this line
    /******************************************************************/
      
    Serial.print("Distance:"); Serial.print(current_distance); Serial.print(" , ");
    Serial.print("Speed:"); Serial.println(speed);

    // Save the values for next measurement
    previous_distance = current_distance;
    time_of_previous_pulse = time_of_current_pulse;

    // Make pulse for another reading
    make_pulse();

  }

  // delay used to slow down program
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
    time_of_current_pulse = end_time;
    duration = end_time - start_time;
    pulse = true; // set helping variable so that in main loop its know that pulse happend
  }
}