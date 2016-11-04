import sys
import socket
import string

Server = "127.0.0.1"
Port = 9001
buffer = ""

Socket = socket.socket()
Socket.connect((Server,Port))

while 1:
    buffer = buffer + Socket.recv(1024)
    lines = string.split(buffer, "\n")
    buffer = lines.pop()

    for line in lines:
        line = string.rstrip(line)
        line = string.split(line)

        if line[0] == "FORWARD":
            print "received FORWARD command"
            Socket.send("RECEIVED\r\n")