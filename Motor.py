import sys
import time
import RPi.GPIO as GPIO

RightForward = 24
RightBackward = 26
LeftForward = 23
LeftBackward = 21

def init():
    GPIO.setwarnings(False)
    GPIO.cleanup()
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(RightForward, GPIO.OUT)
    GPIO.setup(RightBackward, GPIO.OUT)
    GPIO.setup(LeftForward, GPIO.OUT)
    GPIO.setup(LeftBackward, GPIO.OUT)

def control(L,x):
    GPIO.output(RightForward, L[0])
    GPIO.output(RightBackward, L[1])
    GPIO.output(LeftForward, L[2])
    GPIO.output(LeftBackward, L[3])
    time.sleep(x)

def forward(x):
    control([1,0,1,0],x)
    stop(0)

def reverse(x):
    control([0,1,0,1],x)
    stop(0)

def left():
    for i in range(5):
        control([0,0,1,0],1)
        control([0,1,0,0],1)
    stop(0)

def right():
    for i in range(5):
        control([0,1,0,0],1)
        control([0,0,1,0],1)
    stop(0)

def stop(x):
    control([0,0,0,0],x)

if __name__ == "__main__":
    init()
    forward(1)
    left()
    forward(1)
    reverse(1)
    right()
    reverse(1)
    GPIO.cleanup()
    quit()

