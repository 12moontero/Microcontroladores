// C++ code

int button = D4;
int ledGreen = D7;
int ledOrange = D6;
int ledRed = D5;

void setup()
{
  pinMode(button,INPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledOrange,OUTPUT);
  pinMode(ledRed,OUTPUT);
  
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledRed, LOW);
}

void loop()
{
  if (digitalRead(button)== HIGH)
	{
 		digitalWrite(ledGreen,LOW);
 		digitalWrite(ledOrange,HIGH);
 		delay(3000);
 
 		digitalWrite(ledOrange,LOW);
 		digitalWrite(ledRed,HIGH);
 		delay(6000);
   
 		digitalWrite(ledRed, LOW);  
 		digitalWrite(ledGreen, HIGH);
	}
 
}
