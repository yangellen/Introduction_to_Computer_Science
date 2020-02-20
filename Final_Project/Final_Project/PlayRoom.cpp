/****************************************************************************
 **  Ellen Yang
 **  PlayRoom.cpp
 **  This is the PlayRoom class implantation file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#include "PlayRoom.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  PlayRoom::PlayRoom():Space()
 **  default constructor for PlayRoom
 ****************************************************************************/
PlayRoom::PlayRoom():Space()
{
   this->spaceName = "Play Room";

}

/****************************************************************************
 **  void PlayRoom::roomIntro()
 **  This functions display the introduction and the goal of Play room.
 ****************************************************************************/
void PlayRoom::roomIntro()
{
   cout <<"*************************************************************"<<endl;
   cout <<"*  You are in the play area with the twins.                 *"<<endl;
   cout <<"*  Your goal is to have the kids clean up the play area, so *"<<endl;
   cout <<"*  you can head to the kitchen. You will need to collect    *"<<endl;
   cout <<"*  a sticker in order to enter the next room.               *"<<endl;
   cout <<"*  Every time you roll the dice, you will lost one engergy  *"<<endl;
   cout <<"*  point. Whenever you get to drink coffee, you can have    *"<<endl;
   cout <<"*  extra energy to use later if your purse is not full.     *"<<endl;
   cout <<"*************************************************************"<<endl;
   cout <<endl;}

/****************************************************************************
 **  void PlayRoom::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will keep on rolling the dice until the goal has met. Player will
 **  use 1 energy per roll and collect a sticker when goal has met. 
 ****************************************************************************/
void PlayRoom::randomEvent()
{
   int event = 0;

   //only able to exit the room when play area has been clean
   while (event != 4)
   {
      energylost ++;
      event = rand() % 4 + 1; //1,2,3,4
      cout <<"Player rolled the dice "<<energylost<< " time(s)"<<endl;

      switch (event)
      {
         case 1:
         {
            cout<<"The twins are fighting for toys!"<<endl;
            cout <<"Mommy runs to the rescue."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"The twins are playing nicely with each other"<<endl;
            cout <<"Mommy get to drink a cup of coffee and watch them play"<<endl;
            coffee++;
            cout <<endl;
         }
            break;
         case 3:
         {
            cout <<"One of the twins pee on the pants!"<<endl;
            cout <<"Mommy had to change the kid's clothes and clean the floor."<<endl;
            cout <<endl;
         }
            break;
         case 4:
         {
            cout <<"Clean up time. Twins helped clean up the toys."<<endl;
            cout <<"Mommy gets a sticker"<<endl;
            cout <<endl; 
         }
            break;
      }
   }
}

