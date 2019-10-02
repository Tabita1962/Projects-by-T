/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */

#include "SevSeg.h"
SevSeg sevseg; 

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0

int counter =0;

//Variables
int value;          // Store value from photoresistor (0-1023)

void setup(){
 byte numDigits = 4;
 byte digitPins[] = {2, 3, 4, 5};
 byte segmentPins[] = {6,7,8,9,10,11,12};
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 byte hardwareConfig = COMMON_CATHODE; 
 bool resistorsOnSegments = true; 
 bool updateWithDelaysIn = true;
 sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,updateWithDelaysIn);
 sevseg.setBrightness(90);
 Serial.begin(9600);
}

void loop(){
  value = analogRead(pResistor);
   if (value > 25) {    //You can change value "25"
    Serial.print(value);
   // int count = 0; count<=9999;
   //sevseg.setNumber(count+1,4);
   //sevseg.refreshDisplay();
  }
  else{
    //Serial.print(value);
   sevseg.setNumber(0002,4);  
   sevseg.refreshDisplay(); 
   }
    //input sending the value of counter to the LED

//counter+=1;
 //delay(500); //Small delay
}
  
