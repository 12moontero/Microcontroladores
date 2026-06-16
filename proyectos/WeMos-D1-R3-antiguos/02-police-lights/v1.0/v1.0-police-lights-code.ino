//C++
int ledRed = D7;
int ledBlue = D6;

void setup()
{  
  pinMode(ledRed,OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop()
{
// Led Red
digitalWrite(ledRed,HIGH);
delay(100);
digitalWrite(ledRed,LOW);

// Led Blue
digitalWrite(ledBlue,HIGH);
delay(100);
digitalWrite(ledBlue,LOW);
}
