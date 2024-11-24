// Filename: IMU_magnetometer_solved.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains finished code that reads magnetometer data from IMU


#include <Wire.h>

// Gyroscope address
#define IMU_magnetometer_address 0x1E

// Control register where setup value is written
#define Magnetometer_control_reg 0x22

// Value that says how fast should be the measurements taken and what is the range of gyro
#define Magnetometer_setup_value 0x00

// Addresses of register where output values are stored
#define Mag_X_Low  0x28
#define Mag_X_High 0x29
#define Mag_Y_Low  0x2A
#define Mag_Y_High 0x2B
#define Mag_Z_Low  0x2C
#define Mag_Z_High 0x2D

// Variables where output acceleration values will be stored
int mag_x = 0;
int mag_y = 0;
int mag_z = 0;

void setup() {
  // Join I2C bus
  Wire.begin();  

  // Startup serial communication              
  Serial.begin(9600);

  /**********************************************

  Your assignment is to get the Linear accelarion value from MinIMU sensor

  In order for you to get reading at all, firstly you have to setup the Gyroscope

  Setup instructions
    - Start communication using Wire.beginTransmission(address) function [set address to be IMU gyroscope address]
    - Select register using Wire.write(data) function where data is Gyroscope control register address
    - Send command itself using Wire.write(data)
    - End the communication using Wire.endTransmission()

  After this edit function get_linear_acceleration() where reading of the data is taken

  Write your code bellow this line
  **********************************************/


  Wire.beginTransmission(IMU_magnetometer_address); 
  Wire.write(Magnetometer_control_reg);      
  Wire.write(Magnetometer_setup_value);     
  Wire.endTransmission();      


}

// Do not edit this function
void loop() {


  // Read raw data from IMU, you need to implement this function down below
  mag_x = get_magnetometer_data(Mag_X_Low, Mag_X_High);
  mag_y = get_magnetometer_data(Mag_Y_Low, Mag_Y_High);
  mag_z = get_magnetometer_data(Mag_Z_Low, Mag_Z_High);



  // Pretty print the results using Serial communication
  Serial.print("Mag_field_X:"); Serial.print(mag_x); Serial.print(" , ");
  Serial.print("Mag_field_Y:"); Serial.print(mag_y); Serial.print(" , ");
  Serial.print("Mag_field_Z:"); Serial.println(mag_z);

}


// Function that reads 2 bytes of linear acceleration and returns it as single byte 
int get_magnetometer_data(byte low_address, byte high_address){

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

  Wire.beginTransmission(IMU_magnetometer_address);  // Start transmission to IMU
  Wire.write(low_address);                        // Select register from which to read
  Wire.endTransmission();                         // End transmission to IMU 

  Wire.requestFrom(IMU_magnetometer_address, 2);     // Request 2 bytes from IMU

  if (2 <= Wire.available()){                     // Read 2 bytes from IMU
    lower_value = Wire.read(); 
    higher_value = Wire.read();
  } 

  
  // Combine those two values
  final_value = higher_value * 256;
  final_value += lower_value;

  return final_value;
  


  return final_value;
}



