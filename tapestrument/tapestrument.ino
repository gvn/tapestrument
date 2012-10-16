// PIN
int motorPin = 9;

int speed;

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  speed = map(analogRead(A0), 0, 1023, 148, 255);
  Serial.println(speed);
  
  analogWrite(motorPin, speed);
  
  delay(1); //Hold it!
}
