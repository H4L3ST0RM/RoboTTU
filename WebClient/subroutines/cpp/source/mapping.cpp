#include<iostream>
#include<fstream>
#include "create/create.h"
#include <unistd.h>
create::Create* robot;

//Declaring all functions
int getState(create::Create* robot);
void goState0(create::Create* robot);
void goState1(create::Create* robot);
void goState2(create::Create* robot,int state[2]);
void goState3(create::Create* robot,int state[2]);
void writeData(std::ofstream* dataFile);

//Global Variables
int previous = 0;
int current = 1;
int state[2];

int main() {
  std::cout<< "First Line Of Main\n";
  std::string port = "/dev/ttyUSB0";
  int baud = 115200;
  //Making robot object
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
  robot->setMode(create::MODE_SAFE);

  //Set current/previous states to 2
  state[previous] = 2;
  state[current] = 2;
  //Create ofstream object for outputting data to file
  std::ofstream *dataFile;
  //Set intial direction to forward
//  robot->drive(0.1,0.0);
/*******************************************************************************/
  //Main While Loop
  while (!robot->isCleanButtonPressed()) {
    robot->drive(0.1,0.0);
    std::cout<<"Indside While Loop\n";
    usleep(1000 * 100); //10hz
    std::cout<<"isLightBumperLeft: " << robot->isLightBumperLeft()<<"\n";
    std::cout<<"isLightBumperFrontLeft: " << robot->isLightBumperFrontLeft()<<"\n";
    std::cout<<"isLightBumperCenterLeft: " << robot->isLightBumperCenterLeft()<<"\n";
    std::cout<<"isLightBumperRight: " << robot->isLightBumperRight()<<"\n";
    std::cout<<"isLightBumperFrontRight: " << robot->isLightBumperFrontRight()<<"\n";
    std::cout<<"isLightBumperCenterRight: " << robot->isLightBumperCenterRight()<<"\n";

    //Update previous and current states
    state[current] = getState(robot);
    std::cout<<"state[previous]: " << state[previous] << "\n";
    std::cout<<"state[current]: " << state[current] << "\n";
    //If there has been a state change, we need to update robot statis
    if (state[previous] != state[current]) {
      //Before changing state, save data to file for mapping later
      //writeData(dataFile);
      //Go to whatever state is now current
      if (state[current] == 0){
        goState0(robot);
      }
      if (state[current] == 1 ) {
        goState1(robot);
      }
      if (state[current] == 2) {
        goState2(robot, state);
      }
      if (state[current] == 3) {
        goState3(robot, state);
      }
    }
  }
  // Make sure to disconnect to clean up
  robot->disconnect();
  delete robot;
  return 0;
}
//If current state is zero, then one or more of the 3 left light bumpers is on
void goState0(create::Create* robot) {
  std::cout<<"Inside State0\n";
  state[previous] = 0;
  //if its only the far left bumper that is on, move straight
    while ((robot->isLightBumperFrontLeft()) || (robot->isLightBumperCenterLeft())
            || (robot->isLightBumperLeft())) {
      //Turn right
      robot->drive(0.0,-0.1);
    }
    //Drive straight
    robot->drive(0.1,0.0);
}

//If current state is one, then one or more of the 3 right light bumpers is on
void goState1(create::Create* robot) {
  std::cout<<"Inside State1\n";
  //If its only the far right bumper that is on, move straight
  state[previous] = 1;
    while ((robot->isLightBumperFrontRight()) || (robot->isLightBumperCenterRight())
              || (robot->isLightBumperRight())) {
      //Turn left
      robot->drive(0.0,0.1);
    }
    //Move straight
    robot->drive(0.1,0.0);
}

//If current state is two, then no light bumpers are currently on
void goState2(create::Create* robot, int state[2]) {
  std::cout<<"Inside State2\n";
  //If previously left bumpers were on (ie state 0)
  //Drive straight
  robot->drive(0.1,0.0);
  return;
}
//If current straight is three, then its any combination of light bumpers that
//is not state zero or one
void goState3(create::Create* robot,int state[2]) {
  std::cout<<"Inside State3\n";
  //If previously any right light bumpers were on (ie state 1)
  if (state[previous] == 1) {
    //Turn left until only light right bumpers are on again
    while ((robot->isLightBumperLeft()) ||
          (robot->isLightBumperFrontLeft()) ||
           (robot->isLightBumperCenterLeft())) {
             //Turn left
             robot->drive(0.0,0.1);
    }
  }
  //If previously any left bumpers were on (ie state )
  if (state[previous] == 0) {
    //Turn right until only left light bumpers are on again
    while ((robot->isLightBumperRight()) ||
          (robot->isLightBumperFrontRight()) ||
           (robot->isLightBumperCenterRight())) {
             //Turn Right
             robot->drive(0.0,-0.1);
    }
  }
  //Move straight
  robot->drive(0.1,0.0);
}

//Get current state
int getState(create::Create* robot) {
  std::cout<<"Inside getState\n";
  //If any left bumpers and no right bumpers, its in state 0
  if (((robot->isLightBumperLeft()) ||
        (robot->isLightBumperFrontLeft()) ||
         (robot->isLightBumperCenterLeft())) &&
         (!(robot->isLightBumperRight()) &&
               !(robot->isLightBumperFrontRight()) &&
                !(robot->isLightBumperCenterRight()))) {
                  std::cout<<"getState returns 0\n";
                  return 0;

  }
//If any right bumpers and no left bumpers, its in state 1
  if ((!(robot->isLightBumperLeft()) &&
        !(robot->isLightBumperFrontLeft()) &&
         !(robot->isLightBumperCenterLeft())) &&
         ((robot->isLightBumperRight()) ||
               (robot->isLightBumperFrontRight()) ||
                (robot->isLightBumperCenterRight()))) {
                  std::cout<<"getState returns 1\n";
                  return 1;
  }
//If not bumpers its in state 2
  if (!(robot->isLightBumperLeft()) &&
        !(robot->isLightBumperFrontLeft()) &&
         !(robot->isLightBumperCenterLeft()) &&
         !(robot->isLightBumperRight()) &&
               !(robot->isLightBumperFrontRight()) &&
                !(robot->isLightBumperCenterRight())) {
                  std::cout<<"getState returns 2\n";
                  return 2;
  }
  //Any other bumper combination, its in state 3
  else {
    std::cout<<"getState returns 3\n";
    return 3;
  }
}
//Write x,y, and angle data to output file.
void writeData(std::ofstream *dataFile){
  dataFile->open("mappingData.txt");
  *dataFile << robot->getPose().x << " "
            <<robot->getPose().y << " "
            <<robot->getPose().yaw
            * 180.0/create::util::PI
            << "\n";
  dataFile->close();
}
