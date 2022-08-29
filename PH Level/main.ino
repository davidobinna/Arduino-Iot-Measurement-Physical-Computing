//pH Measurement using Atlas Scientific pH Sensor
#include <SoftwareSerial.h> //We are using Software serial to free the hardware serial port
#define rx 2 //define what pin rx is going to be
#define tx 3 //define what pin tx is going to be

SoftwareSerial myserial ( rx , tx ); //define how the software serial port is going to work
char ph_data [20]; //20 byte char array to hold incoming data from pH
char computerdata [20]; //20 byte char array to hold incoming data from PC

byte received_from_computer =0; //how many characters received
byte received_from_sensor =0;
byte arduino_only =0; //if you would like to operate the pH Circuit with the Arduino only and

//not use the serial monitor to send it commands set this to 1.

byte startup =0; //Used to make sure the Arduino rakes over control of the pH Circuit
properly

float ph =0; //used to hold a floating point number that is the pH
byte string_received =0; //used to identify when we have received a string from the pH circuit

void setup () {
Serial . begin (38400); //enable the hardware serial at BAUD: 38400
myserial . begin (38400); //enalble the software serial
} 

void serialEvent (){ //this interrupt will trigger when the data coming from

//the serial monitor(pc/mac/other) is received.
if( arduino_only !=1){ //if Arduino_only does not equal 1 this function will be bypassed.
received_from_computer = Serial . readBytesUntil (13, computerdata ,20); //we read the data sent from the serial monitor
//(pc/mac/other) until we see a <CR>. We also count
//how many characters have been received.

computerdata [ received_from_computer ]=0; //we add a 0 to the spot in the array

just after the last
//character we received.. This will stop us from
//transmitting incorrect data that may have been left
//in the buffer.

myserial.print ( computerdata ); //we transmit the data received from the serial monitor
//(pc/mac/other) through the soft serial port to the
//pH Circuit.

myserial.print ('\r'); //all data sent to the pH Circuit must end with a <CR>.

  }
} 

void loop () { //if we see that the pH Circuit has sent a character.

if( myserial.available () > 0){

//we read the data sent from pH Circuit until we see a <CR>. We also count how many character have
//been received.

received_from_sensor = myserial.readBytesUntil (13, ph_data ,20);

//we add a 0 to the spot in the array just after the last character we received. This will stop us from
//transmitting incorrect data that may have been left in the buffer.

ph_data [ received_from_sensor ]=0;

//a flag used when the Arduino is controlling the pH Circuit to let us know that a complete string has been received .
string_received =1;

//lets transmit that data received from the pH Circuit to the serial monitor.

Serial.println ( ph_data );
 } 
 if( arduino_only ==1){ Arduino_Control ();} //If the var arduino_only is set to one we will call this
//function. Letting the Arduino take over control of the pH Circuit
 
 }

void Arduino_Control (){
if( startup ==0){ //if the Arduino just booted up, we need to set some things up first.
myserial . print ("e\r"); //take the pH Circuit out of continues mode.

delay (50); //on start up sometimes the first command is missed.
myserial.print ("e\r"); //so, let's send it twice.

delay (50); //a short delay after the pH Circuit was taken out of continues mode is used to make
//sure we don't over load it with commands.
startup =1; //startup is completed, let's not do this again during normal operation.
}

delay (800); //we will take a reading ever 800ms.
myserial.print ("R\r"); //send it the command to take a single reading.

if( string_received ==1){ //did we get data back from the ph Circuit?
ph = atof ( ph_data ); //many people ask us "how do I convert a sting into a float?" This is how...
if( ph >=7.5){ Serial.println ("high\r");} //This is the proof that it has been converted into a float.

if( ph <7.5){ Serial.println ("low\r");} //This is the proof that it has been converted into a float.

string_received =0; //reset the string received flag.
 }
}