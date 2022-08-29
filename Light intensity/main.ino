//Light Intensity Measurement

double Light (int RawADC0 ) {
double Vout = RawADC0 *0.0048828125;

//int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
int lux =(2500/ Vout -500)/10;

return lux ;
} 
void setup () {
Serial . begin (9600);

}

void loop () {
Serial . print ("Light Intensity:");
Serial . print (int( Light ( analogRead (0))));
Serial . println (" Lux");
delay (1000);

}