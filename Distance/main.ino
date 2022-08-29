/*==========================================
Ultrasonic Distance Measurement
Ultrasonic sensor Pins:
VCC: +5VDC
Trig : Trigger (INPUT) - Pin 4
Echo: Echo (OUTPUT) - Pin 2
GND: GND
========================================== */

int trigPin = 4; //Trig - green Jumper
int echoPin = 2; //Echo - yellow Jumper
long duration , cm , inches ;
void setup () {

//Serial Port begin

Serial . begin (9600);

//Define inputs and outputs

pinMode ( trigPin , OUTPUT );
pinMode ( echoPin , INPUT );
}

void loop () {

// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

digitalWrite ( trigPin , LOW );
delayMicroseconds (5);
digitalWrite ( trigPin , HIGH );
delayMicroseconds (10);
digitalWrite ( trigPin , LOW );

// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.

pinMode ( echoPin , INPUT );
duration = pulseIn ( echoPin , HIGH );

// convert the time into a distance

cm = ( duration /2) / 29.1;
inches = ( duration /2) / 74;

Serial.print ("Distance: ");
Serial.print ( inches );
Serial.print ("in, ");
Serial.print ( cm );
Serial.print ("cm");
Serial.println ();
delay (250);

}