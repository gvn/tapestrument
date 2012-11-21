#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

byte commandByte;
byte noteByte;
byte velocityByte;

byte noteOn = 144;

int motorPin = 9;
int speed = 148;

void setup() {
    Serial.begin(57600);
    mySerial.begin(31250);
    pinMode(motorPin, OUTPUT);  
}

void checkMIDI() {
    do {
        if (mySerial.available()) {
            commandByte = mySerial.read();
            noteByte = mySerial.read();
            velocityByte = mySerial.read();

            if (commandByte == noteOn) {
                speed = map(noteByte, 48, 72, 148, 255);
                Serial.println(speed);
            }
        }
    } while (mySerial.available() > 24); // When three bytes are available
}

void loop() {
    checkMIDI();
    analogWrite(motorPin, speed);
    delay(1);
}
