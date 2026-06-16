// C++ code
int ledGreen = D7;
int ledOrange = D6;
int ledRed = D5;

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
