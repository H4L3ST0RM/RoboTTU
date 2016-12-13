from RPIO import PWM
import RPIO
import sys
import time
motor = PWM.Servo()

# using BCM numbering
rightForward = 8
rightBackward = 7
leftForward = 9
leftBackward = 11
sleep_time = 1

# Set a 4000us (4ms) pulse every 20ms for GPIO 15:
# motor.set_servo(15, 4000)


def init():
    # Function to setup the output channels
    RPIO.setmode(RPIO.BCM)
    RPIO.setup(rightForward, RPIO.OUT)
    RPIO.setup(rightBackward, RPIO.OUT)
    RPIO.setup(leftForward, RPIO.OUT)
    RPIO.setup(leftBackward, RPIO.OUT)


def forward(x, multipler):
    # Function to move forward
    # RPIO.output(rightForward, RPIO.HIGH)
    # RPIO.output(leftForward, RPIO.HIGH)
    motor.set_servo(rightForward, 4000*multipler)
    motor.set_servo(leftForward,4000*multipler)
    print("forwarding running  motor ")
    time.sleep(x)
    # RPIO.output(rightForward, RPIO.LOW)
    # RPIO.output(leftForward, RPIO.LOW)
    motor.stop_servo(rightForward)
    motor.stop_servo(leftForward)


def reverse(x, multipler):
    # Function to move backwards
    # RPIO.output(rightBackward, RPIO.HIGH)
    # RPIO.output(leftBackward, RPIO.HIGH)
    motor.set_servo(rightBackward,4000*multipler)
    motor.set_servo(leftBackward,4000*multipler)
    print("backwarding running motor")
    time.sleep(x)# Function to move forward
    # RPIO.output(rightBackward, RPIO.LOW)
    # RPIO.output(leftBackward, RPIO.LOW)
    motor.stop_servo(rightBackward)
    motor.stop_servo(leftBackward)

def turn_right(x, multipler):
    # Function to turn right
    # RPIO.output(rightBackward, RPIO.HIGH)
    # RPIO.output(leftForward, RPIO.HIGH)
    motor.set_servo(rightBackward, 4000*multipler)
    motor.set_servo(leftForward, 4000*multipler)
    print("right motor backwards, right motor forward")
    time.sleep(x)
    # RPIO.output(rightBackward, RPIO.LOW)
    # RPIO.output(leftForward, RPIO.LOW)
    motor.stop_servo(rightBackward)
    motor.stop_servo(leftForward)


def turn_left(x, multipler):
    # Function to turn left
    # RPIO.output(leftBackward, RPIO.HIGH)
    # RPIO.output(rightForward, RPIO.HIGH)
    motor.set_servo(leftBackward,4000*multipler)
    motor.set_servo(rightForward, 4000*multipler)
    print("left motor backwards, right motor forwards motor")
    time.sleep(x)
    # RPIO.output(leftBackward, RPIO.LOW)
    # RPIO.output(rightForward, RPIO.LOW)
    motor.stop_servo(leftBackward)
    motor.stop_servo(rightForward)

init()
print("forward motor")
forward(2)
time.sleep(1)
print("reverse motor")
reverse(2)
time.sleep(1)
print("turn left")
turn_left(2)
time.sleep(1)
print("turn right")
turn_right(2)
time.sleep(1)
print("Stopping motor")
RPIO.cleanup()
