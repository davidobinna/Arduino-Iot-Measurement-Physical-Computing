
/* Knock Sensor
* We have to basically listen to an analog pin and detect
* if the signal goes over a certain threshold. It writes
* "knock" to the serial port if the Threshold is crossed,
* and toggles the LED on pin 13.
*/

int ledPin = 13;
int knockSensor = 0;
byte val = 0;
int statePin = LOW ;
int THRESHOLD = 100;

void setup () {
pinMode ( ledPin , OUTPUT );

Serial . begin (9600);
}

void loop () {

val = analogRead ( knockSensor );
if ( val >= THRESHOLD ) {
statePin = ! statePin ;
digitalWrite ( ledPin , statePin );

Serial.println ("Knock!");
}

delay (100); // we have to make a delay to avoid overloading the serial port
}