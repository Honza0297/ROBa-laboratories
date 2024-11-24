// Filename: IMU_ang_rate.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains unfinished code that measures angular rate of IMU

#include <Wire.h>

// Gyroscope address
#define IMU_gyroscope_address 0x6B

// Control register where setup value is written
#define Gyroscope_control_reg 0x11

// Value that says how fast should be the measurements taken and what is the range of gyro
#define Gyroscope_setup_value 0x7C

// Addresses of register where output values are stored
#define Ang_Rate_X_Low  0x22
#define Ang_Rate_X_High 0x23
#define Ang_Rate_Y_Low  0x24
#define Ang_Rate_Y_High 0x25
#define Ang_Rate_Z_Low  0x26
#define Ang_Rate_Z_High 0x27


// Variables where output acceleration values will be stored
int ang_x = 0;
int ang_y = 0;
int ang_z = 0;


void setup() {
  // Join I2C bus
  Wire.begin();  

  // Startup serial communication              
  Serial.begin(9600);

  /**********************************************

  Your assignment is to get the Angular rate value from MinIMU sensor

  In order for you to get reading at all, firstly you have to setup the Gyroscope

  Setup instructions
    - Start communication using Wire.beginTransmission(address) function [set address to be IMU gyroscope address]
    - Select register using Wire.write(data) function where data is Gyroscope control register address
    - Send command itself using Wire.write(data)
    - End the communication using Wire.endTransmission()

  After this edit function get_angular_rate() where reading of the data is taken

  Write your code bellow this line
  **********************************************/





}

// Do not edit this function
void loop() {


  // Read raw data from IMU, you need to implement this function down below
  ang_x = get_angular_rate(Ang_Rate_X_Low, Ang_Rate_X_High);
  ang_y = get_angular_rate(Ang_Rate_Y_Low, Ang_Rate_Y_High);
  ang_z = get_angular_rate(Ang_Rate_Z_Low, Ang_Rate_Z_High);


  // Converts raw data from IMU into unit of degrees per second
  ang_x = ang_2_dps(ang_x);
  ang_y = ang_2_dps(ang_y);
  ang_z = ang_2_dps(ang_z);

  // Pretty print the results using Serial communication
  Serial.print("Acceleration_X:"); Serial.print(ang_x); Serial.print(" , ");
  Serial.print("Acceleration_Y:"); Serial.print(ang_y); Serial.print(" , ");
  Serial.print("Acceleration_Z:"); Serial.println(ang_z);

}


// Function that reads 2 bytes of angular rate and returns it as single byte 
int get_angular_rate(byte low_address, byte high_address){

  int lower_value  = 0;
  int higher_value = 0;
  int final_value  = 0;

  /**********************************************

  Write code that will read 2 bytes of data from IMU and returns it as one integer

  Reading data from MinIMU
    - Start communication using Wire.beginTransmission(address) function [set address to be IMU gyroscope address]
    - Select register they you want to read from using Wire.write(data) function where data is register address
    - End the communication using Wire.endTransmission()

    - Request data from gyroscope using Wire.requestFrom(address, bytes) function where address is gyroscope addres and bytes is number
      of bytes that you want to read 
    - Use function Wire.available() if requested byte arrived and if yes, read it using function Wire.read()
    - value from low_address write to lower_value and value from high_address write to higher_value

  Combine this two values together into one final_value
    - Higher value represents upper 8 bytes so it needs to be shifted by 8 (or multiplicated by 256)

  Write your code bellow this line
  **********************************************/
  


  return final_value;
}



// Converts raw value from MinIMU into degrees per second
double ang_2_dps(int ang_rate){
  
  /**********************************************

  Scale down the value that is in range <-32,768, +32,768> into range <-2000, 2000>

  Hint: use function map()

  https://www.arduino.cc/reference/en/language/functions/math/map/

  Write your code below
  **********************************************/

  return ang_rate;

}









