# Import required libraries
import sys
import time
import RPi.GPIO as GPIO


mode=GPIO.getmode()
print " mode ="+str(mode)

RightForward = 24
RightBackward = 26
LeftForward = 21
LeftBackward = 23
sleeptime=1

def init():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(RightForward, GPIO.OUT)
    GPIO.setup(RightBackward, GPIO.OUT)
    GPIO.setup(LeftForward, GPIO.OUT)
    GPIO.setup(LeftBackward, GPIO.OUT)


def forward(x):
    GPIO.output(RightForward, GPIO.HIGH)
    GPIO.output(LeftForward, GPIO.HIGH)
    print "forwarding running  motor "
    time.sleep(x)
    GPIO.output(RightForward, GPIO.LOW)
    GPIO.output(LeftForward, GPIO.LOW)

def reverse(x):
    GPIO.output(RightBackward, GPIO.HIGH)
    GPIO.output(LeftBackward, GPIO.HIGH)
    print "backwarding running motor"
    time.sleep(x)
    GPIO.output(RightBackward, GPIO.LOW)
    GPIO.output(LeftBackward, GPIO.LOW)

def turnRight(x):
    GPIO.output(RightBackward, GPIO.HIGH)
    GPIO.output(LeftForward, GPIO.HIGH)
    print "right motor backwards, right motor forward"
    time.sleep(x)
    GPIO.output(RightBackward, GPIO.LOW)
    GPIO.output(LeftForward, GPIO.LOW)

def turnLeft(x):
    GPIO.output(LeftBackward, GPIO.HIGH)
    GPIO.output(RightForward, GPIO.HIGH)
    print "left motor backwards, right motor forwards motor"
    time.sleep(x)
    GPIO.output(LeftBackward, GPIO.LOW)
    GPIO.output(RightForward, GPIO.LOW)

init()
print "forward motor "
forward(2)
time.sleep(1)
print "reverse motor"
reverse(2)
time.sleep(1)
print "turn left"
turnLeft(2)
time.sleep(1)
print "turn right"
turnRight(2)
time.sleep(1)
print "Stopping motor"
GPIO.cleanup()
