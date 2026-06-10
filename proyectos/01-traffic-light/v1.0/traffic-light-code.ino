// C++ code
int ledGreen = 13;
int ledOrange = 12;
int ledRed = 11;

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledOrange,OUTPUT);
  pinMode(ledRed,OUTPUT);
}

void loop()
{
  
// Led Green
digitalWrite(ledGreen,HIGH);
delay(6000);
digitalWrite(ledGreen,LOW);

// Led Orange
digitalWrite(ledOrange,HIGH);
delay(6000);
digitalWrite(ledOrange,LOW);

// led Red
digitalWrite(ledRed,HIGH);
delay(6000);
digitalWrite(ledRed,LOW);
}
