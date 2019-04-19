#include <Servo.h>


// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

// defines pins numbers
const int trigPin = 13;
const int echoPin = 12;
  
// defines variables
long duration;
int distance;

// Declare the Servo pin 
int servoPin = 10;

// Create a servo object 
Servo Servo1;

void setup()
{
  
  Serial.begin(9600); // Starts the serial communication
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // We need to attach the servo to the used pin number 
  Servo1.attach(servoPin); 

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  
}

void loop()
{
   // Clears the trigPin
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   // Sets the trigPin on HIGH state for 10 micro seconds
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);
   // Calculating the distance
   distance= duration*0.034/2;

   if(distance<20){
        // Now turn off motors
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

       // Make servo go to 0 degrees 
       Servo1.write(0); 
       delay(1000); 
       // Make servo go to 90 degrees 
       Servo1.write(90); 
   }
   

}
