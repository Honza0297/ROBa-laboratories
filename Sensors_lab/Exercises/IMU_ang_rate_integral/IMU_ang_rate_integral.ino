// Filename: IMU_ang_rate_itegral.ino
// Author: Adam Fabo
// Last edit: 24.4.2023
// License: Feel free to use this code in any way, shape or form
// University: FIT, BUT, Brno, Czech republic
// This file is a part of authors bachelors thesis
// Description: File contains unfinished code that integrates angular rate of IMU,
//              therefore it gets absolute angle of the sensor


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

// Time data needed for the integration
unsigned long prev_time = 0;
unsigned long now_time = 0;
unsigned long time_diff = 0;


// Variables where intregrated angular rate will be stored
double ang_x_integral = 0;
double ang_y_integral = 0;
double ang_z_integral = 0;

// Do not edit this function
void setup() {
  // Join I2C bus
  Wire.begin();  

  // Startup serial communication              
  Serial.begin(9600);

  // Setup the IMU  
  Wire.beginTransmission(IMU_gyroscope_address); 
  Wire.write(Gyroscope_control_reg);      
  Wire.write(Gyroscope_setup_value);      
  Wire.endTransmission();                        

}


void loop() {


  // Read raw data from IMU, you need to implement this function down below
  ang_x = get_angular_rate(Ang_Rate_X_Low, Ang_Rate_X_High);
  ang_y = get_angular_rate(Ang_Rate_Y_Low, Ang_Rate_Y_High);
  ang_z = get_angular_rate(Ang_Rate_Z_Low, Ang_Rate_Z_High);


  // Converts raw data from IMU into unit of degrees per second
  ang_x = ang_2_dps(ang_x);
  ang_y = ang_2_dps(ang_y);
  ang_z = ang_2_dps(ang_z);

    /**********************************************

  Your assignment is to get Integrate the data read from IMU - which says about change in degrees per second
  and integrate it into relative cumulative angle

  Here are steps how to do it:

  1.  - You need to know time that the measurement was taken
      - You need to know time of previous measurement taken
      - You need to know the difference between those times
      - Scale the difference into seconds
      - Calulate the integral

  Use function millis() to get current time (returns number of millisecond that passed from start of the program)   

  Write your code bellow this line
  **********************************************/





  // Do not edit code under this line
  /******************************************************************/

  // Pretty print the results using Serial communication
  Serial.print("Angle_X:"); Serial.print(ang_x_integral); Serial.print(" , ");
  Serial.print("Angle_Y:"); Serial.print(ang_y_integral); Serial.print(" , ");
  Serial.print("Angle_Z:"); Serial.println(ang_z_integral);

}


// Function that reads 2 bytes of angular rate and returns it as single byte 
int get_angular_rate(byte low_address, byte high_address){

  int lower_value  = 0;
  int higher_value = 0;
  int final_value  = 0;


  Wire.beginTransmission(IMU_gyroscope_address);  // Start transmission to IMU
  Wire.write(low_address);                        // Select register from which to read
  Wire.endTransmission();                         // End transmission to IMU 

  Wire.requestFrom(IMU_gyroscope_address, 2);     // Request 2 bytes from IMU

  if (2 <= Wire.available()){                     // Read 2 bytes from IMU
    lower_value = Wire.read(); 
    higher_value = Wire.read();
  } 

  
  // Combine those two values
  final_value = higher_value * 256;
  final_value += lower_value;

  return final_value;

}



// Converts raw value from MinIMU into degrees per second
double ang_2_dps(int ang_rate){
  
  // Scale down the value that is in range <-32,768, +32,768> into range <-2000, 2000>

  return map(ang_rate, -32768, 32768, -2000, 2000);;

}









