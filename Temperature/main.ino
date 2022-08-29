/*
Temperature Measurement
Reads an analog input on pin 0, converts it to Temperature, and prints the
result to the serial monitor.
Graphical representation is available using serial plotter
(Tools > Serial Plotter menu)
Attach the LM35 Temperature Sensor as shown in Circuit.
*/

// the setup routine runs once when you press reset:
void setup () {

// initialize serial communication at 9600 bits per second:

Serial . begin (9600);

}//
the loop routine runs over and over again forever:

void loop () {

// read the input on analog pin 0, we have connected LM35 Output

int sensorValue = analogRead ( A0 );
// Convert the analog reading (which goes from 0 - 1023) to a Temperature:

float Temperature = sensorValue / 2.048;
// print out the value you read:

Serial . print ("Temperature:");
Serial . println ( Temperature );

delay (1000);

}