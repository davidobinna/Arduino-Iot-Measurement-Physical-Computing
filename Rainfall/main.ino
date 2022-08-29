//Rain Sensor Detection of Rain

int nRainDigitalIn = 2;
int nRainVal ;

boolean bIsRaining = false;
String strRaining ;

void setup () {
Serial . begin (9600);
pinMode (2, INPUT );
}

void loop () {
nRainVal = analogRead ( A1 );
bIsRaining = !( digitalRead ( nRainDigitalIn )); //Cheks Digital Pin 2, Output D0

if( bIsRaining ){ //Checks Digital Pin 2, Output D0
strRaining = "YES";
} else {
strRaining = "NO";
}

Serial . print ("Raining: ");
Serial . print ( strRaining );
Serial . print (" Moisture Level: ");
Serial . println ( nRainVal );

delay (1000);
}