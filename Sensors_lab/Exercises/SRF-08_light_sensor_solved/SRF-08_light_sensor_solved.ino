// todo main comment


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
int light_sensor_address = 0x01;

// Variable where distance will be stored
int light_sensor;
int reading;

void setup() {
  // Join I2C bus
  Wire.begin();                
  
  // Setup serial communication
  Serial.begin(9600);         
}



void loop() {

    /**********************************************

  Your assignment is to get the LIGHT measurement from the SRF-08 sensor

  In order to get updated value of the sensor you need to send command to sonar (same as when measuring distance)

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



  // In order to read from light sensor there must be command to update its value (does not matter which)
  Wire.beginTransmission(sonar_address);        // Start sending data to sonar
  Wire.write(command_register_address);         // Specify register to which write data
  Wire.write(command_centimeters);              // Write commad to measure in centimeters
  Wire.endTransmission();                       // Stop sending data to sonar

  delay(70); // Wait for sonar to make the measurement 


  // Recive data from light sensor
  Wire.beginTransmission(sonar_address);        // Start sending data to sonar
  Wire.write(light_sensor_address);             // Specify from which register we would like to read
  Wire.endTransmission();                       // Stop sending data to sonar
  
  // request one byte from sonar
  Wire.requestFrom(sonar_address, 1);  

  // Check if the byte requested is availible
  if (1 <= Wire.available()){
    light_sensor = Wire.read(); // read one byte
  }


    
  // Do not edit code under this line
  /******************************************************************/
  
  // Print the distance
  // *** Note - use plotter in arduino IDE to visualise the values as graph
  Serial.print("Light sensor:"); 
  Serial.println(light_sensor);

}
