#include "create/create.h"
#include <unistd.h>
create::Create* robot;
/*
DESCRIPTION: This program will begin to roam when the "Hour" button is pushed.
If will go straight until either, the light bumpers detect something, in which
case it turns; the bumpers hit something, in which case it backs up and turns;
or it detects a cliff/wheels are lifted, in which case it stops

Based on "create_demo" in "examples" files from libcreate library.

AUTHORS:
  - John C. Hale
  - Santiago Estens

LAST DATE MODIFIED:
  -11/13/2016 11:34 pm
*/


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
           else if (robot->isRightBumper()) {
               robot->drive(-0.1,0.5);
               usleep(2000000);//2 seconds
           }
               // Check bumpers
           else if (robot->isLeftBumper()) {
               robot->drive(-0.1,-0.5);
               usleep(2000000);//2 seconds
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
