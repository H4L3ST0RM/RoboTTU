#include "create/create.h"
#include <unistd.h>
create::Create* robot;
/*
DESCRIPTION: This program will begin to roam when the "Hour" button is pushed.
If will go straight until either, the light bumpers detect something, in which
case it turns; the bumpers hit something, in which case it backs up and turns;
or it detects a cliff/wheels are lifted, in which case it stops. It will quit
roam when either the hour button is pressed again ,and exit the program when the
Clean button is pressed.
Based on "create_demo" in "examples" files from libcreate library.
AUTHORS:
  - John C. Hale
  - Santiago Estens
LAST DATE MODIFIED:
  -11/13/2016 11:34 pm
*/
int playbackUpBeeper(create::Create* robot);

int main() {
   std::string port = "/dev/ttyUSB0";
   int baud = 115200;
   create::RobotModel model = create::RobotModel::CREATE_2;

   robot = new create::Create(model);

   // Attempt to connect to Create
   if (robot->connect(port, baud))
       std::cout << "Successfully connected to Create" << std::endl;
   else {
       std::cout << "Failed to connect to Create on port " << port.c_str() << std::endl;
       return 1;
   }

   // Note: Some functionality does not work as expected in Safe mode
   robot->setMode(create::MODE_FULL);

   bool drive = false;

   // Quit when center "Clean" button pressed
   while (!robot->isCleanButtonPressed()) {

       if (robot->isHourButtonPressed()) {
           std::cout << "hour button press" << std::endl;
           drive = !drive;
       }
       // Check for wheeldrop or cliffs
       if (robot->isWheeldrop() || robot->isCliff()) {
           drive = false;
       }

       // If everything is ok, drive forward using IR's to avoid obstacles
       if (drive) {
           if (robot->isLightBumperLeft() ||
               robot->isLightBumperFrontLeft() ||
               robot->isLightBumperCenterLeft()) {
               // turn right
               robot->drive(0.1, -1.0);
           }
           else if (robot->isLightBumperRight() ||
                    robot->isLightBumperFrontRight() ||
                    robot->isLightBumperCenterRight()) {
               // turn left
               robot->drive(0.1, 1.0);
           }
<<<<<<< HEAD
           else if (robot->isRightBumper()) {
               robot->drive(-0.1,0.0);
=======
           else if (robot->isRightBumper()) {               
               robot->drive(-0.1,0.5);
>>>>>>> 32f8e2aaeb61750abf8e97cad6b52c637bec127b
               playbackUpBeeper(robot);
               usleep(2000000);//2 seconds
               robot->drive(0.1,1.0);
               usleep(1000000);
           }
               // Check bumpers
<<<<<<< HEAD
           else if (robot->isLeftBumper()) {
               robot->drive(-0.1,0.0);
=======
           else if (robot->isLeftBumper()) {               
               robot->drive(-0.1,-0.5);
>>>>>>> 32f8e2aaeb61750abf8e97cad6b52c637bec127b
               playbackUpBeeper(robot);
               usleep(2000000);//2 seconds
               // turn right
               robot->drive(0.1, -1.0);
               usleep(1000000);
           }
           else {
               // drive straight
               robot->drive(0.1, 0.0);
           }
       }
       else { // drive == false
           // stop moving
           robot->drive(0, 0);
       }
       usleep(1000 * 100); //10hz
   }
   // Make sure to disconnect to clean up
   robot->disconnect();
   delete robot;
   return 0;
}

//Function that plays a warning beep when the create2 is going backwards

int playbackUpBeeper(create::Create* robot){
    uint8_t songLength = 4;
    //83 for backup beeper
    uint8_t notes[4] = {83, 83, 83, 83};
    float durations[songLength];
    for (int i = 0; i < songLength; i++) {
        durations[i] = 0.50;
    }
    robot->defineSong(0, songLength, notes, durations);
    robot->playSong(0);
    return 0;
}
