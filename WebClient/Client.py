import select
import socket
import string
import sys
import time
from subprocess import call
from breezycreate2 import Robot
############################################
# Client Configuration
############################################
Server = "99.64.48.184"
Port = 9001
MaxReconnAttempts = 100
############################################

# Initialize
ReconnectAttempts = 1
Buffer = ""
Bot = Robot()

# Parses a line of data sent by server
def parse(data):
    data = string.rstrip(data)
    # tokenize by space
    data = string.split(data)

    # stick API calls here
    if data[0] == "FORWARD":
		print "received FORWARD command"
		Bot.setForwardSpeed(100)
		time.sleep(1)
		Bot.setForwardSpeed(0)
    #    Socket.send("RECEIVED\r\n")

    if data[0] == "REVERSE":
        print "received REVERSE command"
        Bot.setForwardSpeed(-100)
        time.sleep(1)
        Bot.setForwardSpeed(0)
        Socket.send("RECEIVED\r\n")

    if data[0] == "TURNLEFT":
        print "received TURNLEFT command"
        Bot.setTurnSpeed(-100)
        time.sleep(1)
        Bot.setTurnSpeed(0)
        Socket.send("RECEIVED\r\n")

    if data[0] == "TURNRIGHT":
        print "received TURNRIGHT command"
        Bot.setTurnSpeed(100)
        time.sleep(1)
        Bot.setTurnSpeed(0)
        Socket.send("RECEIVED\r\n")

    if data[0] == "CAMERARIGHT":
        print "received CAMERARIGHT command"
        Socket.send("RECEIVED\r\n")

    if data[0] == "CAMERALEFT":
        print "received CAMERALEFT command"
        Socket.send("RECEIVED\r\n")


# Doesn't actually reconnect, just handles logic based around reconnecting
# The actual reconnecting happens when the main loop is continue'd and performs
# the connect logic all over again
def reconnect():
    global ReconnectAttempts
    if ReconnectAttempts >= MaxReconnAttempts:
        print "maximum reconnection attempts reached, exiting..."
        sys.exit()
    print "reconnecting in 5 seconds, attempt {0} of {1}".format(ReconnectAttempts, MaxReconnAttempts)
    ReconnectAttempts += 1
    time.sleep(5)


# This is in a separate method from reconnect() because it'll throw exceptions
# if the socket isn't connected already.
def close_socket():
    global Socket
    Socket.shutdown(2)
    Socket.close()
    print "connection error"


# Main loop
while True:

    # connection logic
    Socket = socket.socket()

    try:
        Socket.connect((Server, Port))
    except socket.error:
        print "cannot connect to web service"
        reconnect()
        continue
    print "connection established"
	#subprocess.call(["ruby", "autoTweet.rb", "-c"])
	ReconnectAttempts = 1
    #

    # sub main loop that runs while socket is connected
    # reads lines from socket and sends them off to be parsed
    while True:
        try:
            ready_to_read, ready_to_write, in_error = select.select([Socket, ], [Socket, ], [], 5)
            Buffer = Buffer + Socket.recv(1024)
        # no idea why python doesn't have fall-through for exceptions
        except select.error:
            close_socket()
            reconnect()
            break
        except socket.error:
            close_socket()
            reconnect()
            break

        lines = string.split(Buffer, "\n")
        Buffer = lines.pop()

        for line in lines:
            parse(line)
    #
