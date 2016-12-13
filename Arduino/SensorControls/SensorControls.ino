/* 
This sketch will be used for controlling/Collecting all of the sensors/data on a rover. 
It will be controlled by a Raspberry Pi. It will also emit a warning sound when the 
ultrasonic sensors detect an obstacle less tham 5 cm away

By John Hale, Santiago Estens

Controlling a servo position using a Raspberry Pi
*/
/*
Contributing Authors:
- Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
- Tom Igoe <http://www.arduino.cc/en/Tutorial/Tone>
*/
#include <Servo.h>
#include "pitches.h"

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
 
  // notes in the melody:
  int melody[] = {
    NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4
};
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    2, 2, 4, 4, 4, 8, 8, 8
};
 
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
    if(distance < 5){
      //emit warning sound
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 8; thisNote++) {
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);  
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
    }
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
