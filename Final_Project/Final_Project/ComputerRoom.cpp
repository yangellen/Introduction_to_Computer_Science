/****************************************************************************
 **  Ellen Yang
 **  ComputerRoom.hpp
 **  This is the ComputerRoom class implantation file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#include "ComputerRoom.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  ComputerRoom::ComputerRoom():Space()
 **  default constructor for ComputerRoom
 ****************************************************************************/
ComputerRoom::ComputerRoom():Space()
{
   this->spaceName = "Computer Room";
   }

/****************************************************************************
 **  void ComputerRoom::roomIntro()
 **  This functions display the introduction and the goal of computer room.
 ****************************************************************************/
void ComputerRoom::roomIntro()
{
   cout <<"*************************************************************"<<endl;
   cout <<"* You are in the computer room. Kids are alseep now.        *"<<endl;
   cout <<"* Your goal is to finish your cs 162 project, so you can    *"<<endl;
   cout <<"* head to bed. You will need to collect a sticker in order  *"<<endl;
   cout <<"* to enter the next room.                                   *"<<endl;
   cout <<"* Every time you roll the dice, you will lost one engergy   *"<<endl;
   cout <<"* point. Whenever you get to drink coffee, you can have     *"<<endl;
   cout <<"* extra energy to use later if your bag is not full         *"<<endl;
   cout <<"*************************************************************"<<endl;
   cout <<endl;
}

/****************************************************************************
 **  void ComputerRoom::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will keep on rolling the dice until the goal has met. Player will
 **  use 1 energy per roll and collect a sticker when goal has met.
 ****************************************************************************/
void ComputerRoom::randomEvent()
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
            cout<<"The program is running, but with memory leak."<<endl;
            cout <<"You are pulling your hair and trying to find the leak."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"The twins stay asleep."<<endl;
            cout <<"You get to drink coffee and work on project."<<endl;
            coffee++;
            cout <<endl;
         }
            break;
         case 3:
         {
            cout <<"Internet is not working!"<<endl;
            cout <<"You are having trouble submiiting file online."<<endl;
            cout <<endl;
         }
            break;
         case 4:
         {
            cout <<"You finished working on the project."<<endl;
            cout <<"and submitted online before its due."<<endl;
            cout <<"You get a sticker"<<endl;
            cout <<endl;
         }
            break;
      }
   }
}

//
//void ComputerRoom::moveForward()
//{

//}
