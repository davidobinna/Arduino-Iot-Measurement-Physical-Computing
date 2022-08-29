/*
Hardware connections:
- (GND) to GND
+ (VDD) to 3.3V
(WARNING: do not connect + to 5V or the sensor will be damaged!)
You will also need to connect the I2C pins (SCL and SDA) to your
Arduino. The pins are different on different Arduinos:
Any Arduino pins labeled: SDA SCL
Uno, Redboard, Pro: A4 A5
Mega2560, Due: 20 21
Leonardo: 2 3
Leave the IO (VDDIO) pin unconnected. This pin is for connecting
the BMP180 to systems with lower logic levels such as 1.8V
*/

#include <SFE_BMP180.h>
#include <Wire.h>

// You will need to create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure ;
#define ALTITUDE 1655.0 // Altitude in meters

void setup (){
Serial . begin (9600);
Serial . println ("REBOOT");

// Initialize the sensor (it is important to get calibration values stored on the device).
if ( pressure . begin ())
Serial . println ("BMP180 init success");
else {

// Oops, something went wrong, this is usually a connection problem,

// see the comments at the top of this sketch for the proper connections.
Serial . println ("BMP180 init fail\n\n");

while(1); // Pause forever.

 }
}
void loop () {
char status ;
double T , P , p0 , a ;

// Loop here getting pressure readings every 10 seconds.

// If you want sea-level-compensated pressure, as used in weather reports,
// you will need to know the altitude at which your measurements are taken.
// We're using a constant called ALTITUDE in this sketch:

Serial . println ();
Serial . print ("provided altitude: ");
Serial . print ( ALTITUDE ,0);
Serial . print (" meters, ");
Serial . print ( ALTITUDE *3.28084,0);
Serial . println (" feet");
status = pressure . startTemperature ();

if ( status != 0) {
// Wait for the measurement to complete:
delay ( status );

// Retrieve the completed temperature measurement:
status = pressure . getTemperature ( T );

if ( status != 0) {

// Print out the measurement:
Serial . print ("temperature: ");
Serial . print ( T ,2);
Serial . print (" deg C, ");
Serial . print ((9.0/5.0)* T +32.0,2);
Serial . println (" deg F");
// Start a pressure measurement:
status = pressure . startPressure (3);
if ( status != 0) {
    
// Wait for the measurement to complete:

delay ( status );
status = pressure . getPressure ( P , T );

if ( status != 0) {

// Print out the measurement:
Serial . print ("absolute pressure: ");
Serial . print ( P ,2);
Serial . print (" mb, ");
Serial . print ( P *0.0295333727,2);
Serial . println (" inHg");

p0 = pressure . sealevel ( P , ALTITUDE );

Serial . print ("relative (sea-level) pressure: ");
Serial . print ( p0 ,2);
Serial . print (" mb, ");
Serial . print ( p0 *0.0295333727,2);
Serial . println (" inHg");

a = pressure . altitude ( P , p0 );

Serial . print ("computed altitude: ");
Serial . print ( a ,0);
Serial . print (" meters, ");
Serial . print ( a *3.28084,0);
Serial . println (" feet");

} else Serial . println ("error retrieving pressure measurement\n");

} else Serial . println ("error starting pressure measurement\n");
} else Serial . println ("error retrieving temperature measurement\n");
} else Serial . println ("error starting temperature measurement\n");

delay (5000); // Pause for 5 seconds.

}
