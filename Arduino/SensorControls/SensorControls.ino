/* 
This sketch will be used for controlling/Collecting all of the sensors/data on a rover. 
It will be controlled by a Raspberry Pi. 

By John Hale, Santiago Estens
e
Controlling a servo position using a Raspberry Pi
*/
/*
Contributing Authors:
- Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
- 
*/
#include <Servo.h> 

//Ultrasonic Sensor 
#define echoPin 6
#define trigPin 7
//Servo
#define servoRightPin 8  // Digital pin used to read input control from Raspberry Pi
#define servoOnPin 9
#define servoPin 10
 
 
 
   //Defining Variables
  Servo myservo;  // create servo object to control a servo 
  int angle = 90;
  long duration;
  long distance;
  boolean servoRight;
  boolean servoOn;
  int rangeFinderLimit = 3000; 
 
 
 
void setup()
{ 
  //Setting up Pins
  Serial.begin (9600);
   myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoRightPin, INPUT);
  pinMode(servoOnPin, INPUT);

} 


 
void loop() 
{ 
  //ULTRASONIC SENSOR
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) /29.1;
  if (distance > rangeFinderLimit || distance <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  //CONTROL OF SERVO
    servoOn = digitalRead(servoOnPin);            // reads the value of the controlPin (HIGH or LOW) 
    if (servoOn) {
       servoRight = digitalRead(servoRightPin);
      if (servoRight) {
        if (angle < 150) {
          angle=angle+5;
          myservo.write(angle);
        }
      }
      else { //Go Left
        if (angle > 0 ) {
          angle=angle-5;
          myservo.write(angle);      
        }
      }
    }
    delay(50);                           // waits for the servo to get there 
} 
