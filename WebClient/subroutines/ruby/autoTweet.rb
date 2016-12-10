require 'rubygems'
require 'oauth'
require 'json'
# CS 4365 PROJECT GROUP 3
#
# DESCRIPTION: Tweets to the twitter account Robo_TTU. 
#			   Uses command line arguments that are takes as
#			   input. The command line type is defined as:
#			   either c, o, y, or s.
#			   c - tweets the time of connection to the server
#			   o - tweets the amount of obstacles collided
#			   y - tweets the link to the youtube channel
#	           l/r - tweets the direction instructed
#			   p - tweets that the robot is being controlled from a mobile device
#
# AUTHOR:      Aaron Trusty
#			   Big thanks to codeacademy.com for the example code that I used as a base.
#
# LATE DATE MODIFIED: 12/9/2016 at 3:00 p.m.
#

tweetType = ARGV.first
tweetContent = ""
currentTime = Time.now
#types:
#	c - time of connection tweet
#	o - obstacles collided
#	y - tweet youtube channel
#	l/r - left or right instruction
#   p - mobile controls

# Consumer key and access token.
consumer_key = OAuth::Consumer.new("q4DZXUuCrqGvFHIcy90LO0lFk","ocoPZJ1edWGNMQ7WsQwdRw8Cd6wqKWjVYkPJAHyAHcp9zZDB6Y")
access_token = OAuth::Token.new("790329083154444288-ttWdk7xH1pWTiFH7CyesuupyW0MmBOT","c1PIjXDF4NVY0ENhT7VoQc1ir8Rm5LUISKodpVg2Jst51")


if tweetType == 'y' then #tweet youtube channel url
	tweetContent = "We are live! Check out the stream at https://www.youtube.com/channel/UCci5U62GUrWc6Ax90f2Wmnw #RoboTTU #{currentTime}" 
elsif tweetType == 'c' then #connection
	tweetContent = "I connected at #{currentTime} #RoboTTU"
elsif tweetType == 'o' then #obstacles
	tweetContent = "I collided with #{ARGV[1]} obstacle(s)! #RoboTTU #{currentTime}"
elsif tweetType == 'p' then #phone controls 
	tweetContent = "#RoboTTU is being controlled from a mobile device! #{currentTime}"
elsif tweetType == 'l' then #left sensor hit
	tweetContent = "The server instructed me to turn left! #RoboTTU #{currentTime}"	
elsif tweetType == 'r' then #right sensor hit
	tweetContent = "The server instructed me to turn right! #RoboTTU #{currentTime}"
else #error handling
	tweetContent = "Failed ARGV value at #{currentTime}. The value passed was #{tweetType}. #RoboTTU"
end

# Contents of tweet
baseurl = "https://api.twitter.com"
path    = "/1.1/statuses/update.json"
address = URI("#{baseurl}#{path}")
request = Net::HTTP::Post.new address.request_uri
#request.set_form_data("status" => "Tweet script running on server successfully! #RoboTTU")
request.set_form_data("status" => tweetContent)

# HTTP set up
http             = Net::HTTP.new address.host, address.port
http.use_ssl     = true
http.verify_mode = OpenSSL::SSL::VERIFY_NONE

# Request
request.oauth! http, consumer_key, access_token
http.start
response = http.request request

# Informs user that tweet can or cannot be sent.
tweet = nil
if response.code == '200' then
  tweet = JSON.parse(response.body)
  puts "Successfully sent #{tweet["text"]}"
else
  puts "Could not send the Tweet! " +
  "Code:#{response.code} Body:#{response.body}"
end
