// todo top comment


#include <Wire.h>

// Gyroscope address
#define IMU_gyroscope_address 0x6B

// Control register where setup value is written
#define Gyroscope_control_reg 0x10

// Value that says how fast should be the measurements taken and what is the range of gyro
#define Gyroscope_setup_value 0x74

// Addresses of register where output values are stored
#define Lin_Acc_X_Low  0x28
#define Lin_Acc_X_High 0x29
#define Lin_Acc_Y_Low  0x2A
#define Lin_Acc_Y_High 0x2B
#define Lin_Acc_Z_Low  0x2C
#define Lin_Acc_Z_High 0x2D

// Variables where output acceleration values will be stored
int acc_x = 0;
int acc_y = 0;
int acc_z = 0;

// Variables where output acceleration values will be stored
double acc_x_double = 0;
double acc_y_double = 0;
double acc_z_double = 0;



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





}

// Do not edit this function
void loop() {


  // Read raw data from IMU, you need to implement this function down below
  acc_x = get_linear_acceleration(Lin_Acc_X_Low, Lin_Acc_X_High);
  acc_y = get_linear_acceleration(Lin_Acc_Y_Low, Lin_Acc_Y_High);
  acc_z = get_linear_acceleration(Lin_Acc_Z_Low, Lin_Acc_Z_High);


  // Converts raw data from IMU into unit of G
  // acc_x_double = acc_2_G(acc_x);                                 
  // acc_y_double = acc_2_G(acc_y);
  // acc_z_double = acc_2_G(acc_z);

  // Converts raw data from IMU into unit of meters per second^2
  acc_x_double = acc_2_ms(acc_x);
  acc_y_double = acc_2_ms(acc_y);
  acc_z_double = acc_2_ms(acc_z);

  // Pretty print the results using Serial communication
  Serial.print("Acceleration_X:"); Serial.print(acc_x_double); Serial.print(" , ");
  Serial.print("Acceleration_Y:"); Serial.print(acc_y_double); Serial.print(" , ");
  Serial.print("Acceleration_Z:"); Serial.println(acc_z_double);

}


// Function that reads 2 bytes of linear acceleration and returns it as single byte 
int get_linear_acceleration(byte low_address, byte high_address){

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



// Converts value from IMU into multiplication of Earths gravity - G
double acc_2_G(int acceleration){
  
  /**********************************************

  By observing behaviour of gyroscope try and find constant with which raw data needs to be divided 
  in order to get result in unit of G

  **********************************************/

  int constant = 1.0;
  return acceleration/constant;

}

// Converts value from IMU into meters per second^2
double acc_2_ms(int acceleration){

    /**********************************************

  By observing behaviour of gyroscope try and find constant with which raw data needs to be divided 
  in order to get result in unit of meters per second^2

  **********************************************/

  int constant = 1.0;
  return acceleration/constant;

}
