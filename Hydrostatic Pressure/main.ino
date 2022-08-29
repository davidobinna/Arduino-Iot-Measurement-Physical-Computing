/*=================================================
Precision Liquid Level measurement using arduino
=================================================*/

#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 10, 5, 4, 3, 2);
int Level ;

void setup () {
lcd.begin (16,1);
Serial.begin (9600);
}

void loop () {

Level = analogRead ( A0 )-45; //Sensor is having some offset so do some

//calibration here
lcd.setCursor (0 , 0);
lcd.print ("Liquid Level:");
lcd.print ( Level );
lcd.print (" Ltr");
Serial.print ("Liquid Level:");
Serial.print ( Level );
Serial.println (" Ltr");

delay (1000);

}