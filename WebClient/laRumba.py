#!/usr/bin/env python3

'''
robotest.py - Test the features of BreezyCreate2

This code is part of BreezyCreate2

The MIT License

Copyright (c) 2016 Simon D. Levy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
'''

from breezycreate2 import Robot
import time

# Create a Create2. This will automatically try to connect to your robot over serial
bot = Robot()

# Play a note to let us know you're alive!

def smoothVerseOne():
	time.sleep(0.1)

	bot.playNote('E4', 50)
	bot.setTurnSpeed(-100)
	time.sleep(1)

	bot.playNote('G4', 50)
	time.sleep(1)

	bot.setTurnSpeed(0)
	bot.setForwardSpeed(100)
	bot.playNote('E4', 50)
	time.sleep(1)

	
	bot.playNote('A4', 50)
	bot.setForwardSpeed(-100)
	time.sleep(1)

	bot.playNote('E3', 50)
	time.sleep(1)

	bot.setForwardSpeed(0)
	bot.playNote('E4', 50)
	time.sleep(1)

	bot.playNote('F4', 50)
	bot.setTurnSpeed(100)
	time.sleep(1)

	bot.setTurnSpeed(0)
	bot.playNote('G4', 50)
	time.sleep(1)

	bot.playNote('E4', 50)
	bot.setTurnSpeed(-100)
	time.sleep(1)

	bot.playNote('F4', 50)
	time.sleep(1)

	bot.setTurnSpeed(0)
	bot.playNote('E4', 50)
	time.sleep(1)

	bot.playNote('E4', 50)
	time.sleep(1)

	bot.playNote('A3', 50)
	time.sleep(1)

	bot.playNote('D4', 50)
	time.sleep(1)

	bot.playNote('D4', 50)
	time.sleep(1)

	bot.playNote('C4', 50)
	time.sleep(1)

	bot.playNote('B4', 50)


def smoothVerseTwo():
        time.sleep(0.1)

        bot.playNote('E4', 50)
        bot.setForwardSpeed(150)
        time.sleep(1)

        bot.playNote('G4', 50)
        time.sleep(1)

        bot.playNote('E4', 50)
        time.sleep(1)


        bot.playNote('A4', 50)
        bot.setTurnSpeed(100)
        time.sleep(1)


        bot.playNote('E4', 50)
        bot.setTurnSpeed(0)
	bot.setForwardSpeed(100)
        time.sleep(1)

        bot.playNote('G4', 50)
        time.sleep(1)

        bot.setForwardSpeed(0)
        bot.setTurnSpeed(-100)
        bot.playNote('E4', 50)
        time.sleep(1)
	
	bot.setForwardSpeed(100)
	bot.playNote('E4', 100)
	time.sleep(2)


        bot.playNote('A4', 50)
        bot.setForwardSpeed(-100)
        time.sleep(1)







def verseRise():
	time.sleep(1)

        bot.playNote('A4', 50)
	bot.setTurnSpeed(100)
        time.sleep(1)

        bot.playNote('B3', 50)
        bot.setTurnSpeed(-100)
	time.sleep(1)
	
        bot.playNote('C4', 50)
	bot.setTurnSpeed(150)
        time.sleep(1)

        bot.playNote('D4', 50)
	bot.setTurnSpeed(-150)
        time.sleep(1)

        bot.playNote('E4', 50)
	bot.setTurnSpeed(200)
        time.sleep(1)

        bot.playNote('F4', 50)
	bot.setTurnSpeed(-250)
        time.sleep(1)
	bot.playNote('G4', 50)
	bot.setTurnSpeed(250)	

def verseFall():
        time.sleep(0.1)
        bot.playNote('G4', 25)
        time.sleep(0.1)
        bot.playNote('F3', 25)
        time.sleep(0.1)
        bot.playNote('E4', 25)
        time.sleep(0.1)
        bot.playNote('D4', 25)
        time.sleep(0.1)
        bot.playNote('C4', 25)
        time.sleep(0.1)
        bot.playNote('B4', 25)
        time.sleep(0.1)
        bot.playNote('A4', 25)



# MAIN FUNCTION
for x in range (0,2):
	smoothVerseTwo()
	verseRise()
	smoothVerseOne()
	verseRise()
	verseFall()
bot.setTurnSpeed(0)
bot.setForwardSpeed(0)
time.sleep(1)
bot.close()

# Close the connection
bot.close()
