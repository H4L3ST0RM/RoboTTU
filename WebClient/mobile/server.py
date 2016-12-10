from flask import Flask, render_template, request, jsonify
from breezycreate2 import Robot

app = Flask(__name__)

# return index page when IP address of RPi is typed in the browser
@app.route("/")
def Index():
    return render_template("index.html", uptime=GetUptime())

# ajax GET call this function to set led state
# depeding on the GET parameter sent
@app.route("/_UPDATE")
def _update():
    speedX=4
    #left[-10,10]
    #right[-10,10]
    left = int(request.args.get('left'))
    right = int(request.args.get('right'))
    """
    radius=left-right #in mm 0=straight 1=sharpest turn
    #radius[-20,20]
    radius*=radius
    #radius[0,400]
    if radius>0:
        radius=401-radius
    #radius[0,400]

    if radius<0: #[-400,-1]
        radius+=21
        radius*=radius
        radius*=-1
    if radius>0: #[1,400]
        radius-=21
        radius*=radius

    if right>left:
        radius=-1*radius
    #radius[-400,400]

    if right==left:  #not turning
        radius=0
    elif right>left: #turning left
        radius=400*min(abs(right),abs(left))/max(abs(right),abs(left))-401
    else:            #turning right
        radius=-400*min(abs(right),abs(left))/max(abs(right),abs(left))+401
    """
    radius=GetRadius(right,left)
    speed=(left+right)*speedX #[-200,200]
    if speed*speed<=400:
        speed=speed
    if radius*radius==1:
        speed=(left-right)*speedX
    print(speed,radius)
    Bot.robot.drive(speed,radius)
    return ""

@app.route("/_R")
def _V():
    state = request.args.get('state')
    print(state)
    Bot.setForwardSpeed(int(state)-50)
    return ""

# ajax GET call this function periodically to read button state
# the state is sent back as json data
@app.route("/_button")
def _button():
    return jsonify("not pressed")

def GetUptime():
    # get uptime from the linux terminal command
    from subprocess import check_output
    output = check_output(["uptime"])
    # return only uptime info
    uptime = output[output.find("up"):output.find("user")-5]
    return uptime

def GetRadius(R,L):
    if R==L:
        return 0
    if R>L: #turning left
        return -400*min(abs(R),abs(L))/max(abs(R),abs(L))+401
    #turning right
    return 400*min(abs(R),abs(L))/max(abs(R),abs(L))-401


# run the webserver on standard port 80, requires sudo
if __name__ == "__main__":
    Bot = Robot()
    app.run(host='0.0.0.0', port=80, debug=True)