/*
Soil Moisture Measurement
*/
//the pins used:

const int analogInPin = A0 ; // Analog input pin that the potentiometer is attached to
int sensorValue = 0; // value read from the pot
int outputValue = 0;

void setup () {
// initialize serial communications at 9600 bps:
Serial . begin (9600);
} 

void loop () {

// read the analog in value:
sensorValue = analogRead ( analogInPin );

// map it to the range of the analog out:
outputValue = map ( sensorValue , 0, 1023, 0, 100); //maps the adc values to 0 to
100%

// print the results to the serial monitor:
Serial . print ("Soil Moisture Level = ");
Serial . print ( outputValue );
Serial . println (" %");

delay (1000);
 }