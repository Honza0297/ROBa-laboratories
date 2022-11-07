// todo top comment


#include <Wire.h>

// Gyroscope address
#define IMU_gyroscope_address 0x6B

#define Temperature_Low_Address  0x20
#define Temperature_High_Address 0x21

int temperature = 0;

void setup() {
  // Join I2C bus
  Wire.begin();  

  // Startup serial communication              
  Serial.begin(9600);

  // For temperature sensor there is no need to setup anything               

}

// Do not edit this function
void loop() {

  temperature = get_temperature(Temperature_Low_Address, Temperature_High_Address);

  // If you wish you can uncomment this line and implement temp_2_deg()
  //temperature = temp_2_deg(temperature)

  // Pretty print the results using Serial communication
  Serial.print("Temperature:"); Serial.println(temperature);

  // Delay for slower printing
  delay(100);

}


// Function that reads 2 bytes of angular rate and returns it as single byte 
int get_temperature(byte low_address, byte high_address){

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




int temp_2_deg(int temp){

  /**********************************************

  Scale output value from the sensor to degrees.
  You need to calibrate the sensor ~somehow~ - even I dont know how to do it.
  
  If you wish to embark on this journey here is documentation for you 
  https://www.pololu.com/file/0J1087/LSM6DS33.pdf#page=18
 
  Good luck.

  Hint: use function map()

  https://www.arduino.cc/reference/en/language/functions/math/map/

  Write your code below
  **********************************************/

  return temp;
}









