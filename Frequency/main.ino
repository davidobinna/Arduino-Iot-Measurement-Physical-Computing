/*
* Frequency Measurement Using Arduino
* Input is given to Pin 2
* Uses Interrupt to get pulse duration
* F = 1 / pulse duration
*/

#define MainPeriod 100

long previousMillis = 0; // will store last time of the cycle end

volatile unsigned long duration =0; // accumulates pulse width

volatile unsigned int pulsecount =0;

volatile unsigned long previousMicros =0;
void setup () {
Serial . begin (9600);
attachInterrupt (0, myinthandler , RISING );
} 
void loop () {

unsigned long currentMillis = millis ();

if ( currentMillis - previousMillis >= MainPeriod ) {
previousMillis = currentMillis ;

// need to bufferize to avoid glitches

unsigned long _duration = duration ;
unsigned long _pulsecount = pulsecount ;
duration = 0; // clear counters
pulsecount = 0;

float Freq = 1e6 / float( _duration ); //Duration is in uSecond so it is 1e6 / T

Freq *= _pulsecount ; // calculate F

// output time and frequency data to RS232

Serial . print ("Frequency: ");
Serial . print ( Freq );
Serial . println ("Hz");

 }

 } 

 void myinthandler () // interrupt handler
{

unsigned long currentMicros = micros ();


duration += currentMicros - previousMicros ;
previousMicros = currentMicros ;
pulsecount ++;

}
