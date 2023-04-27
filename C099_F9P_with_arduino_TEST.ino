#include <Wire.h>                                                 //Include the Wire library for I2C communication
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>                 //Include the SparkFun u-blox GNSS library for easy communication with the C099-F9P

SFE_UBLOX_GNSS myGNSS;                                            //Declare a variable of the SFE_UBLOX_GNSS type, which provides access to the GNSS functions

void setup()
{
  Serial.begin(9600);   //Initialize the serial port at a baud rate of 9600
  Wire.begin();         //Initialize the I2C communication protocol
  myGNSS.begin();       //Initialize the GNSS module
}

void loop()
{
  if (myGNSS.readSensor())                                //Read the GNSS data
  {
    Serial.print("Latitude: ");
    Serial.println(myGNSS.getLatitude());                 //Print the latitude to the serial monitor
    Serial.print("Longitude: ");
    Serial.println(myGNSS.getLongitude());                //Print the longitude to the serial monitor
    Serial.print("Altitude: ");
    Serial.println(myGNSS.getAltitude());                 //Print the altitude to the serial monitor
    Serial.print("Time: ");
    Serial.println(myGNSS.getTime());                     //Print the time to the serial monitor
    Serial.print("Number of satellites: ");
    Serial.println(myGNSS.getNumberOfSatellites());       //Print the number of satellites being tracked to the serial monitor
    Serial.print("Raw data: ");
    Serial.println(myGNSS.getRaw());                      //Print the raw data to the serial monitor
    Serial.println();
   
  }
  else
  {
    Serial.println("Failed to read GNSS data");
  }

  delay(1000);                                            //Wait for 1 second before reading the data again
}
