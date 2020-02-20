/****************************************************************************
 **  Ellen Yang
 **  MasterRoom.cpp
 **  This is the MasterRoom class implantation file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#include "MasterRoom.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  MasterRoom::MasterRoom():Space()
 **  default constructor for MasterRoom
 ****************************************************************************/
MasterRoom::MasterRoom():Space()
{
   this->spaceName = "Master Room";

}

/****************************************************************************
 **  void MasterRoom::roomIntro()
 **  This functions display the introduction and the goal of Master room.
 ****************************************************************************/
void MasterRoom::roomIntro()
{
   cout <<"*************************************************************"<<endl;
   cout <<"* You are in the Mater Room.                                *"<<endl;
   cout <<"* Your goal is to go to bed before your energy reach zero.  *"<<endl;
   cout <<"*************************************************************"<<endl;
   cout <<endl;}

/****************************************************************************
 **  void MasterRoom::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will go sleep in this room. 
 ****************************************************************************/
void MasterRoom::randomEvent()
{
     int event = 0;


      energylost ++;
      event = rand() % 4 + 1; //1,2,3,4
      cout <<"Player rolled the dice "<<energylost<< " time(s)"<<endl;

      switch (event)
      {
         case 1:
         {
            cout<<"You turn on your diffuer with your favorite essential oil,"<<endl;
            cout <<"and sleep peacefully till the next morning."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"It's already 2am. Your husband already sound asleep."<<endl;
            cout <<"You quickly go to bed and sleep peacefully till the next morning."<<endl;
            cout <<endl;
         }
            break;
         case 3:
         {
            cout <<"It's only 9pm. You get to watch netflix with your husband,"<<endl;
            cout <<"then sleep peacefully till the next morning."<<endl;
            cout <<endl;
         }
            break;
         case 4:
         {
            cout <<"You are still thinking about your project and can't go to sleep."<<endl;
            cout <<"You decided to take a bubble bath,"<<endl;
            cout <<"then sleep peacefully till the next morning."<<endl;
            cout <<endl;
         }
            break;
      }
}



