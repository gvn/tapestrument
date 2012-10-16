/*Receive MIDI and check if note = 60
By Amanda Ghassaei
July 2012
http://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

*/

#include <SoftwareSerial.h>

byte commandByte;
byte noteByte;
byte velocityByte;

byte noteOn = 144;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup(){
  Serial.begin(57600);
  mySerial.begin(31250);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void checkMIDI(){
  do{
    if (mySerial.available()){
      commandByte = mySerial.read();
      noteByte = mySerial.read();
      velocityByte = mySerial.read();

      if (commandByte == noteOn){
          digitalWrite(13,HIGH);
          Serial.println(noteByte);
      }
    }
  }
  while (mySerial.available() > 24);//when three bytes available
}
    

void loop(){
  checkMIDI();
  delay(10);
  digitalWrite(13,LOW);//turn led off
}


