/*
Resistance Measurement
Reads an analog input on pin 0, converts it to resistance, and prints the result to the
serial monitor.
*/
// the setup routine runs once when you press reset:

void setup () {
 
 // initialize serial communication at 9600 bits per second:

Serial . begin (9600);

}//

the loop routine runs over and over again forever:


void loop () {


// read the input on analog pin 0:

int sensorValue = analogRead ( A0 );
// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

float voltage = sensorValue * (5.0 / 1024.0);
float I = voltage / 1000;
float VRx = 5 - voltage ;
float Rx = VRx / I ;

 Rx = (5 - voltage ) / I ;
 
 // print out the value you read:

Serial . print ("Resistance:");
Serial . print ( Rx );
Serial . println (" Ohms");

delay (1000);
 }