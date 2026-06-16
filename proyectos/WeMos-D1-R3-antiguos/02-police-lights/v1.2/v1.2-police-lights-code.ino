// C++ code

int button = D5;
int ledRed = D7;
int ledBlue = D6;

void setup()
{
  pinMode(button,INPUT_PULLUP);
  pinMode(ledRed,OUTPUT);
  pinMode(ledBlue,OUTPUT);
}

void loop()
{
 if (digitalRead(button) == LOW)
 	{
   		digitalWrite(ledRed, HIGH);
   		delay(100);
   		digitalWrite(ledRed, LOW);
   		digitalWrite(ledBlue, HIGH);
   		delay(100);
   		digitalWrite(ledBlue, LOW);
 	}
  else
  {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
  }
}
