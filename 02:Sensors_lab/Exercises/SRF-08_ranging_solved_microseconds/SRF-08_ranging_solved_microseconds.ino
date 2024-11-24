// Filename: SRF-08_ranging_solved_microseconds.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains finished code that measures distance using SRF-08 sensor and output is in microseconds


#include <Wire.h>

// Address of the sonar on I2C bus
int sonar_address = 0x70;

// Address of the command register inside of the sonar
int command_register_address = 0x00;

// List values that can be written to command register
int command_inches      = 0x50;
int command_centimeters = 0x51;
int command_miliseconds = 0x52;

// Address of register where distance is stored
int distance_register_address = 0x03;

// Variable where distance will be stored
int distance;
int reading;

void setup() {
  // Join I2C bus
  Wire.begin();                
  
  // Setup serial communication
  Serial.begin(9600);         
}



void loop() {

  /**********************************************

  Your assignment is to get the distance measurement from the SRF-08 sensor

  Here are steps how to do it:

  1. You need to write to sonar that you want to measure distance in centimeters
      - Start communication using Wire.beginTransmission(address) function [set address to be sonar address]
      - Select register using Wire.write(data) function where data is register address
      - Send command itself using Wire.write(data)
      - End the communication using Wire.endTransmission()
  
  2. You need to wait for atleast 65ms 
      - Use function delay(time) [set your own time]
  
  3. You need to read data from the sonar when measurement is finished
      - Start communication using Wire.beginTransmission(address) function [set address to be sonar address]
      - Select register they you want to read from using Wire.write(data) function where data is register address
      - End the communication using Wire.endTransmission()

      - Request data from sonar using Wire.requestFrom(address, bytes) function where address is sonar addres and bytes is number
        of bytes that you want to read [now it is only 1]
      - Use function Wire.available() if requested byte arrived and if yes, read it using function Wire.read()
      - set the result of Wire.read() to variable distance
   

  Write your code bellow this line
  **********************************************/
  

  // Tell the sonar to measure distance 
  Wire.beginTransmission(sonar_address);        // Start sending data to sonar
  Wire.write(command_register_address);         // Specify register to which write data
  Wire.write(command_miliseconds);              // Write commad to measure in centimeters
  Wire.endTransmission();                       // Stop sending data to sonar

  delay(70); // Wait for sonar to make the measurement 


  // Recive data from sonar
  Wire.beginTransmission(sonar_address);        // Start sending data to sonar
  Wire.write(distance_register_address - 1);        // Specify from which register we would like to read, need to read 2 bytes
  Wire.endTransmission();                       // Stop sending data to sonar
  
  // request two bytes from sonar
  Wire.requestFrom(sonar_address, 2);  

  // Check if the bytes requested are availible
  if (2 <= Wire.available()){

    // As I2C uses 8 bit communication in order to read 16 bit value it has to be read twice and bytes need to be shifted
    distance = Wire.read();    // Receive high byte 
    distance = distance << 8;  // Shift high byte to be high 8 bits
    distance |= Wire.read();   // Receive low byte as lower 8 bits

  }



  // Do not edit code under this line
  /******************************************************************/

  // Print the distance
  // *** Note - use plotter in arduino IDE to visualise the values as graph
  Serial.print("Miliseconds:"); 
  Serial.print(distance);
  Serial.println(" ms");

}
