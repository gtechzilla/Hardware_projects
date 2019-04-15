#include <Servo.h>

#define trigpin 12//set trigpin
#define echopin 13//set echopin}

Servo myservo;// declare servo name type servo

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
int duration;//declare variable for unltrasonic sensor

  
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
 
  pinMode(echopin, INPUT);

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  myservo.attach(9);// attach your servo
myservo.writeMicroseconds(1500);
  // put your setup code here, to run once:
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
   myservo.write(90);// always set servo to 90 to position it to the middle
   //ultrasonic code 
   digitalWrite(trigpin,HIGH);
   _delay_ms(500);
   digitalWrite(trigpin, LOW);
  
  duration=pulseIn(echopin,HIGH); 
  distance=(duration/2)/29.1;
if(distance <=20)// if ultrasonic sensor detects an obstacle less than 20cm in 90 degree angle.
  {
    moveStop();
  delay(300);
 myservo.write(0); //servo rotates at full speed to the right
 delay(600);
 }

else
{
  myservo.write(90);// else servo stays at 90 degree angle.
  delay(600);
  }

Serial.println(distance);//distance
Serial.print("cm"); //print distance unit cm
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
