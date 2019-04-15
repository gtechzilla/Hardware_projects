#include <LiquidCrystal.h> //Load Liquid Crystal Library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Create Liquid Crystal Object called LCD

int trigPin=9; //Sensor Trip pin connected to Arduino pin 9
int echoPin=10;  //Sensor Echo pin connected to Arduino pin 10
int myCounter=0;  //declare your variable myCounter and set to 0
//int servoControlPin=6; //Servo control line is connected to pin 6
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.

void setup() {
  
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 
lcd.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
lcd.print("Target Distance:");  //Print Message on First Row
}

void loop() {
  
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per hour
  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance= targetDistance*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)
  targetDistance= targetDistance*2.54;  //inches to centimeters
  
  lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0,1);   //Set Cursor again to first column of second row
  lcd.print(targetDistance); //Print measured distance
  lcd.print(" cm");  //Print your units.
  delay(250); //pause to let things settle
  
  
  }  