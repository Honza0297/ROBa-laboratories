// todo top comment



// Pins to which given transistors should be connected
// !! Make sure that your circuit is connected as showed
#define TRANSISTOR_1 2
#define TRANSISTOR_2 4
#define TRANSISTOR_3 6
#define TRANSISTOR_4 8

// Pin of led that indicates shorted powersupply
#define LED_ERROR 10


// Opens/Closes transistors at H-bridge
// true/1  means that transistor is open
// false/0 means that transistor is closed
void set_H_Bridge(bool t1, bool t2, bool t3, bool t4){


  // Handle situations that would lead to shorted power supply
  if( t1 && t2){
    digitalWrite(LED_ERROR, HIGH);
    return;
  }
  else if (t3 && t4){
    digitalWrite(LED_ERROR, HIGH);
    return;
  }
  else{
    digitalWrite(LED_ERROR, LOW);
  }

  digitalWrite(TRANSISTOR_1, !t1);
  digitalWrite(TRANSISTOR_2, t2);
  digitalWrite(TRANSISTOR_3, !t3);
  digitalWrite(TRANSISTOR_4, t4);


}



void setup() {

  // Set transisor pins as output
  pinMode(TRANSISTOR_1, OUTPUT);  // sets the pin as output
  pinMode(TRANSISTOR_2, OUTPUT);  // sets the pin as output
  pinMode(TRANSISTOR_3, OUTPUT);  // sets the pin as output
  pinMode(TRANSISTOR_4, OUTPUT);  // sets the pin as output

  pinMode(LED_ERROR, OUTPUT);  // sets the pin as output

}


/*
    H-Bridge 

    VCC              VCC
    |                |
    T1               T3
    |                | 
    +--- DC MOTOR ---+
    |                |
    T2               T4
    |                |
    GND              GND

    In order to spin motor you need to open transistors in pairs
     - T1-T4
     - T2-T3

    If you open T1-T2 or T3-T4 it will short power supply and something will burn


*/

void loop() {
  /**********************************************
  
  If LED in the middle of PCB lights on, that means that you shorted the H-Bridge and did something wrong
  (but don't worry, nothing burned, this state is handled, just change your code)


    Implement rotation of DC motor in both directions

    1. Start spinning DC motor by opening one pair of transistors
      - Use function set_H_Bridge(T1, T2, T3, T4) to set the transistor values
      - true/1  means that transistor is open
      - false/0 means that transistor is closed

    2. Hold the speed for 3 seconds
      - Use function delay()

    3. Start spinning DC motor to another direction by opening the other pair of transistors
      - Use function set_H_Bridge(T1, T2, T3, T4) to set the transistor values
      - true/1  means that transistor is open
      - false/0 means that transistor is closed
    
    4. Hold the speed for 3 seconds
      - Use function delay()



  Write your code below this line
  **********************************************/


  
}






