import select
import socket
import string
import sys
import time

############################################
# Client Configuration
############################################
Server = "127.0.0.1"
Port = 9001
MaxReconnAttempts = 100
############################################

# Initialize
ReconnectAttempts = 1
Buffer = ""


# Parses a line of data sent by server
def parse(input):
    input = string.rstrip(input)
    # tokenize by space
    input = string.split(input)

    # stick API calls here
    if input[0] == "FORWARD":
        print "received FORWARD command"
        Socket.send("RECEIVED\r\n")

    if input[0] == "BACKWARD":
        print "received BACKWARD command"
        Socket.send("RECEIVED\r\n")

    if input[0] == "TURNLEFT":
        print "received TREADLEFT command"
        Socket.send("RECEIVED\r\n")

    if input[0] == "TURNRIGHT":
        print "received TREADRIGHT command"
        Socket.send("RECEIVED\r\n")

    if input[0] == "CAMERARIGHT":
        print "received CAMERARIGHT command"
        Socket.send("RECEIVED\r\n")

    if input[0] == "CAMERALEFT":
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

