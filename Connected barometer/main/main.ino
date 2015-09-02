/*
 * main.ino
 *
 * Created: 9/2/2015 3:48:41 PM
 * Author: amate_000
 */ 
// Loading required libraries
#include "DHT.h"
#include <SFE_BMP180.h>
#include <Wire.h>
#include <SoftwareSerial.h>

// Defining pins for our sensors.
// BMP180 uses a specific protocol so no need to worry about it.
#define DHTPIN 5
#define LUXPIN A0
#define DHTTYPE DHT11

#define ALTITUDE 147 // altitude used to compute pressure. 147 for Montreal

// Defining connection settings
#define SSID ""
#define PASS ""
#define IP "api.thingspeak.com"
#define API_KEY = ""

// Instantiating sensors
DHT dht(DHTPIN, DHTTYPE);
SFE_BMP180 pressure;

SoftwareSerial esp8266(8,9);


void setup()
{

	  /* add setup code here, setup code runs once when the processor starts */

}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */

}

double readBMPTemp() {
	
	char status;
	double T;
	
	// Start a temperature measurement:
	// If request is successful, the number of ms to wait is returned.
	// If request is unsuccessful, 0 is returned.

	status = pressure.startTemperature();
	if (status != 0)
	{
		// Wait for the measurement to complete:
		delay(status);

		// Retrieve the completed temperature measurement:
		// Note that the measurement is stored in the variable T.
		// Function returns 1 if successful, 0 if failure.

		status = pressure.getTemperature(T);
		
		return (status!=0 ? T : 0);
		
	}
}

double readBMPPressure(double temp) {
	
	char status;
	double P;
	
	// Start a pressure measurement:
	// The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
	// If request is successful, the number of ms to wait is returned.
	// If request is unsuccessful, 0 is returned.
	
	status = pressure.startPressure(3);
	if (status != 0)
	{
		// Wait for the measurement to complete:
		delay(status);
		
		// Retrieve the completed pressure measurement:
		// Note that the measurement is stored in the variable P.
		// Note also that the function requires the previous temperature measurement (T).
		// (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
		// Function returns 1 if successful, 0 if failure.
		
		status = pressure.getPressure(P,temp);
		return (status!=0 ? P : 0);
	}
}

int getLuminosity()
{
	int reading = analogRead(LIGHTPIN);
	int value = map(reading, 0, 1023, 0, 100);
	return value;
}