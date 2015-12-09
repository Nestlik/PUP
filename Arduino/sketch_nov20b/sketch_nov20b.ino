
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
#define rfReceivePin A0
unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value
 void setup()
 {
   pinMode(rfTransmitPin, OUTPUT);     
   pinMode(ledPin, OUTPUT); 
   pinMode(rfReceivePin, INPUT);   
 }

 void loop()
 {
     digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
     delay(2000);                           //Wait for 1 second
     //digitalWrite(rfTransmitPin,LOW);      //Transmit a LOW signal
     //delay(2000); 
      data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
      if(data>upperThreshold)
      {
     digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
     Serial.println(data);
      }
   if(data<lowerThreshold)
   {
     digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
     Serial.println(data);
   }
   }
