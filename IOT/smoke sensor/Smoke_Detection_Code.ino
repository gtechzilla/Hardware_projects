#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int redLed = 12;
int greenLed = 9;
int buzzer = 11;
int smokeA0 = A0;
int sensorThres = 200; // Threshold value for the MQ2 sensor

void setup() 
{
  pinMode (redLed, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2); 

}

void loop()
{
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.print("Smoke level: ");
  lcd.print(analogSensor-50);
  
  if (analogSensor-50> sensorThres)
  {
    digitalWrite (redLed, HIGH);
    lcd.setCursor (0, 2);
    lcd.print ("Fire Alert!!!");
    digitalWrite (9, LOW);
    digitalWrite (12, LOW);
    tone(buzzer, 1000, 200);
  }

  else 
  {
    digitalWrite (redLed, LOW);
    lcd.setCursor (0, 2);
    lcd.print (".....Normal.....");
    digitalWrite (9, LOW);
    digitalWrite (12, LOW);
    noTone (buzzer);
  }

  delay (500);
  lcd.clear();
}
