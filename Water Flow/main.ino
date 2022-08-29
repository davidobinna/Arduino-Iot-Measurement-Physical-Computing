
//Water Flow Measurement
volatile int FlowPulse ; //measuring the rising edges of the signal
int Calc ;
int flowsensor = 2; //The pin-2 location of the sensor Always use this pin as we are

using interrupt 0

void setup () {
pinMode ( flowsensor , INPUT ); //initializes digital pin 2 as an input
Serial.begin (9600); //This is the setup function where the serial port is initialised,
attachInterrupt (0, rpm , RISING ); //and the interrupt is attached on Pin 2 (INT 0)
}

void loop () {
FlowPulse = 0; //Set NbTops to 0 ready for calculations

sei (); //Enables interrupts
delay (1000); //Wait 1 second

cli (); //Disable interrupts
Calc = ( FlowPulse * 60 / 7.5); //(Pulse frequency x 60) / 7.5Q, = flow rate in L/hour

Serial . print ( Calc , DEC ); //Prints the number calculated above
Serial . println (" L/hour"); //Prints "L/hour"
}

void rpm () //This is the function that the interupt calls
{

FlowPulse ++; //This function measures the rising and falling edge of the hall effect

sensors signal

}