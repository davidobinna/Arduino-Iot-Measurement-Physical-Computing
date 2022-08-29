   
/*
Measuring Current Using ACS712
*/
const int analogIn = A0 ;

double mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module

double RawValue = 0;

double ACSoffset = 2500;

double Voltage = 0;

double Amps = 0;

void setup (){

Serial . begin (9600);
 } 

void loop (){

RawValue = analogRead ( analogIn );
Voltage = ( RawValue / 1024.0) * 5000; // Gets you mV
Amps = (( Voltage - ACSoffset ) / mVperAmp );

Serial . print ("Amps = "); // shows the voltage measured
Serial . println ( Amps ,2); // the '2' after voltage allows you to display 2 digits after

decimal point
delay (1000);

 }
