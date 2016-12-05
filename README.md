# RoboTTU

RoboTTU Platform

RoboTTU is a small suite of applications integrated to control motors, servos and more. 

Hardware Required:
* 1 Raspberry Pi 1b
* 1 H Bridge, Model #L289N
* 1 Pi Cam v1
* 1 Camera Servo
* 2 3V DC Motors
* Legos
* 1 Computer

Software Required (latest version unless otherwise specified):
* Raspbian-Jessie OS
* Python
* RPi.GPIO
* Windows Server (.NET Framework and IIS is included)
* Web Browser of your choice
* TensorFlow
* Ruby 64bit
* Ruby gems
* Twitter API

Software recommended for further development:
* Visual Studio
* PyCharm
* vim/nano/emacs

Installation:
* Must install ruby
* Must install rubygems https://rubygems.org/pages/download
* Must download and run ruby DevKit https://github.com/oneclick/rubyinstaller/wiki/Development-Kit#building-the-devkit
* Must install twitter api

Twitter API installation instructions from Windows command line
* After download of ruby gems, execute following commands:
* gem install twitter --source http://rubygems.org
* gem install oauth --source http://rubygems.org


Server
* Install Windows Server on the server
* Copy files from WebInterface folder on GitHub to the server’s web root folder (default is C:\inetpub\wwwroot)

Rover
* Install Raspbian-Jessie on the Raspberry Pi
* Install Python
* Install RPi.GPIO
* Copy WebClient.py to the Pi*
* Copy Motor.py to the Pi*
* Run command ‘python WebClient.py’*

Not available yet
