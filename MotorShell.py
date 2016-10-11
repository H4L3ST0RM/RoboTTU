# Import required libraries
# Still working on getting PWM working
# Need to know how the controls are to be imlpemented,
# to properly design input
import sys
import time
import RPi.GPIO as GPIO


mode=GPIO.getmode()
print " mode ="+str(mode)
GPIO.cleanup()

RightForward = 24
RightBackward = 26
LeftForward = 21
LeftBackward = 23
sleeptime=1

def init():
    GPIO.setmode(GPIO.BOARD)
    GPIO.PWM(RightForward, 500)
    GPIO.PWM(RightBackward, 500)
    GPIO.PWM(LeftForward, 500)
    GPIO.PWM(LeftBackward, 500)
   


def forward():
    GPIO.output(RightForward, GPIO.HIGH)
    GPIO.output(LeftForward, GPIO.HIGH)
    time.sleep(.1)
    GPIO.output(RightForward, GPIO.LOW)
    GPIO.output(LeftForward, GPIO.LOW)

def reverse():
    GPIO.output(RightBackward, GPIO.HIGH)
    GPIO.output(LeftBackward, GPIO.HIGH)
    time.sleep(.1)
    GPIO.output(RightBackward, GPIO.LOW)
    GPIO.output(LeftBackward, GPIO.LOW)

def turnRight():
    GPIO.output(RightBackward, GPIO.HIGH)
    GPIO.output(LeftForward, GPIO.HIGH)
    time.sleep(.1)
    GPIO.output(RightBackward, GPIO.LOW)
    GPIO.output(LeftForward, GPIO.LOW)

def turnLeft():
    GPIO.output(LeftBackward, GPIO.HIGH)
    GPIO.output(RightForward, GPIO.HIGH)
    time.sleep(.1)
    GPIO.output(LeftBackward, GPIO.LOW)
    GPIO.output(RightForward, GPIO.LOW)

def main():
    while True:
        
        input(speed)
        input(direction)
        #et input
        if direction == "forward":
            forward(speed)
        if direction == "backward":
            backward(speed)
        if direction == "leftTurn":
            turnLeft(speed)
        if direction == "rightTurn":
            turnRight(speed)



            
     
    

