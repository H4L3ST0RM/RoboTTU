#include<iostream>
#include<fstream>
#include "create/create.h"
#include <unistd.h>
create::Create* robot;

int getState(create::Create* robot);
void goState0(create::Create* robot);
void goState1(create::Create* robot);
void goState2(create::Create* robot,int state[2]);
void goState3(create::Create* robot,int state[2]);
void writeData(std::ofstream* dataFile);


int main() {
  //DECLARING ROBOT
  std::cout<< "First Line Of Main\n";
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
//
  int state[2];
  state[0] = 2;   //Previous State
  state [1] = 2;  //Current State
  std::ofstream *dataFile;
  robot->drive(0.1,0.0);
/*******************************************************************************/

  while (true) {
    std::cout<<"Indside While Loop\n";
    std::cout<<"state[0]: " << state[0] << "\n";
    std::cout<<"state[1]: " << state[1] << "\n";

    state[0] = state[1];
    state[1] = getState(robot);
    if (state[0] != state[1]) {
      if (state[1] == 0){
        //writeData(dataFile);
        goState0(robot);
      }
      if (state[1] == 1 ) {
        //writeData(dataFile);
        goState1(robot);
      }
      if (state[1] == 2) {
        goState2(robot, state);
      }
      if (state[1] == 3) {
        //writeData(dataFile);
        goState3(robot, state);
      }
    }
  }
  // Make sure to disconnect to clean up
  robot->disconnect();
  delete robot;
  return 0;
}

void goState0(create::Create* robot) {
  std::cout<<"Inside State0\n";
  if (!(robot->isLightBumperCenterLeft()) && !(robot->isLightBumperFrontLeft())) {
    robot->drive(1.0, 0.0);
  }
  else {
    while ((robot->isLightBumperFrontLeft()) || (robot->isLightBumperCenterLeft())) {
      robot->drive(0.0,1.0);
    }
    robot->drive(1.0,0.0);
  }
}

void goState1(create::Create* robot) {
  std::cout<<"Inside State1\n";
  if (!(robot->isLightBumperCenterRight()) && !(robot->isLightBumperFrontRight())) {
    robot->drive(0.0, 0.0);
  }
  else {
    while ((robot->isLightBumperFrontRight()) || (robot->isLightBumperCenterRight())) {
      robot->drive(0.0,-1.0);
    }
    robot->drive(1.0,0.0);
  }
}
//ERROR IN WHILE LOOP!!!!!!!!
//
//BELOW!
//
//ERROR IN WHILE LOOP!!!!!!!!

void goState2(create::Create* robot, int state[2]) {
  std::cout<<"Inside State2\n";
  if (state[0] == 0) {
    while (!(robot->isLightBumperLeft()) ||
          !(robot->isLightBumperFrontLeft()) ||
           !(robot->isLightBumperCenterLeft())) {
             robot->drive(0.0,1.0);
    }
  }
  if (state[0] == 1) {
    while (!(robot->isLightBumperRight()) ||
          !(robot->isLightBumperFrontRight()) ||
           !(robot->isLightBumperCenterRight())) {
             robot->drive(0.0,-1.0);
    }
  }
  robot->drive(1.0,0.0);
  return;
}

void goState3(create::Create* robot,int state[2]) {
  std::cout<<"Inside State3\n";

  if (state[0] == 1) {
    while ((robot->isLightBumperLeft()) ||
          (robot->isLightBumperFrontLeft()) ||
           (robot->isLightBumperCenterLeft())) {
             robot->drive(0.0,1.0);
    }
  }
  if (state[0] == 0) {
    while ((robot->isLightBumperRight()) ||
          (robot->isLightBumperFrontRight()) ||
           (robot->isLightBumperCenterRight())) {
             robot->drive(0.0,-1.0);
    }
  }
  robot->drive(1.0,0.0);
}

int getState(create::Create* robot) {
  std::cout<<"Inside getState\n";
  if (((robot->isLightBumperLeft()) ||
        (robot->isLightBumperFrontLeft()) ||
         (robot->isLightBumperCenterLeft())) &&
         (!(robot->isLightBumperRight()) &&
               !(robot->isLightBumperFrontRight()) &&
                !(robot->isLightBumperCenterRight()))) {
                  std::cout<<"getState returns 0\n";
                  return 0;
  }
  if ((!(robot->isLightBumperLeft()) &&
        !(robot->isLightBumperFrontLeft()) &&
         !(robot->isLightBumperCenterLeft())) &&
         ((robot->isLightBumperRight()) ||
               (robot->isLightBumperFrontRight()) ||
                (robot->isLightBumperCenterRight()))) {
                  std::cout<<"getState returns 1\n";
                  return 1;
  }
  if (!(robot->isLightBumperLeft()) &&
        !(robot->isLightBumperFrontLeft()) &&
         !(robot->isLightBumperCenterLeft()) &&
         !(robot->isLightBumperRight()) &&
               !(robot->isLightBumperFrontRight()) &&
                !(robot->isLightBumperCenterRight())) {
                  std::cout<<"getState returns 2\n";
                  return 2;
  }
  else {
    std::cout<<"getState returns 3\n";
    return 3;
  }
}

void writeData(std::ofstream *dataFile){
  dataFile->open("mappingData.txt");
  *dataFile << robot->getPose().x << " "
            <<robot->getPose().y << " "
            <<robot->getPose().yaw
            * 180.0/create::util::PI
            << "\n";
  dataFile->close();
}
