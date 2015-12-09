
 /* 
  RF Blink - Transmit sketch 
     Written by ScottC 17 Jun 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Transmitter: FS1000A/XY-FST
     Description: A simple sketch used to test RF transmission.          
 ------------------------------------------------------------- */

 #define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
 #define ledPin 10        //Onboard LED = digital pin 13
 #define ledPin1 9
#define rfReceivePin A0
const unsigned long przerwanie=1000;
unsigned long czas;
unsigned long prevczas;
unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value
 void setup()
 {
   Serial.begin(9600);
   pinMode(rfTransmitPin, OUTPUT);     
   pinMode(ledPin, OUTPUT); 
   pinMode(rfReceivePin, INPUT);   
 }

 void loop()
 {
  
  czas = millis();
  if (czas-prevczas>=przerwanie)
     {
      prevczas=czas;
      digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
      digitalWrite(ledPin1, HIGH);            //Turn the LED on)
     }
     
     else
     {
      digitalWrite(rfTransmitPin, LOW);     //Transmit a HIGH signal
      digitalWrite(ledPin1, LOW);            //Turn the LED on)
     }
     
  
     data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
     Serial.println(data);
//     
//     if(data>0)
//     {
//    digitalWrite(ledPin, HIGH);     //Transmit a HIGH signal
//    delay(2000);   
//     digitalWrite(ledPin, LOW);     
//     delay(2000);
//     }         
    
      //if(data>0)
      {
     //digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
     //Serial.println(data);
      }
  // if(data<lowerThreshold)
   {
     //digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
     //Serial.println(data);
   }
   }
