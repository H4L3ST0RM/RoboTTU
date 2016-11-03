require 'rubygems'
require 'oauth'
require 'json'
# Author: Aaron Trusty
#	Big thanks to codeacademy.com for the example code that I used as a base.

# Consumer key and access token.
consumer_key = OAuth::Consumer.new("q4DZXUuCrqGvFHIcy90LO0lFk","ocoPZJ1edWGNMQ7WsQwdRw8Cd6wqKWjVYkPJAHyAHcp9zZDB6Y")
access_token = OAuth::Token.new("790329083154444288-ttWdk7xH1pWTiFH7CyesuupyW0MmBOT","c1PIjXDF4NVY0ENhT7VoQc1ir8Rm5LUISKodpVg2Jst51")

# Contents of tweet
baseurl = "https://api.twitter.com"
path    = "/1.1/statuses/update.json"
address = URI("#{baseurl}#{path}")
request = Net::HTTP::Post.new address.request_uri
request.set_form_data("status" => "Tweet script running on server successfully! #RoboTTU",)

# HTTP set up
http             = Net::HTTP.new address.host, address.port
http.use_ssl     = true
# http.verify_mode = OpenSSL::SSL::VERIFY_PEER
# Above code causes problems... Testing code below
http.verify_mode = OpenSSL::SSL::NONE

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