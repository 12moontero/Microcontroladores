// C++ code

int button = 2;
int ledGreen = 13;
int ledOrange = 12;
int ledRed = 11;

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
