/****************************************************************************
 **  Ellen Yang
 **  KidsRoom.hpp
 **  This is the KidsRoom class implantation file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#include "KidsRoom.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  KidsRoom::KidsRoom():Space()
 **  default constructor for KidsRoom
 ****************************************************************************/
KidsRoom::KidsRoom():Space()
{
   this->spaceName = "Kids' room";
   }

/****************************************************************************
 **  void KidsRoom::roomIntro()
 **  This functions display the introduction and the goal of kids room.
 ****************************************************************************/
void KidsRoom::roomIntro()
{
   cout <<"*************************************************************"<<endl;
   cout <<"* You are in the Kids' room with the twins.                 *"<<endl;
   cout <<"* Your goal is to tuck the kids in bed, so you can head to  *"<<endl;
   cout <<"* the computer room to do your homework. You will need to   *"<<endl;
   cout <<"* collect a sticker in order to enter the next room.         *"<<endl;
   cout <<"* Every time you roll the dice, you will lost one engergy   *"<<endl;
   cout <<"* point. Whenever you get to drink coffee, you can have    *"<<endl;
   cout <<"* extra energy to use later if your bag is not full         *"<<endl;
   cout <<"*************************************************************"<<endl;
   cout <<endl;
}

/****************************************************************************
 **  void KidsRoom::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will keep on rolling the dice until the goal has met. Player will
 **  use 1 energy per roll and collect a sticker when goal has met.
 ****************************************************************************/
void KidsRoom::randomEvent()
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
            cout <<"Kids doesn't want to sleep"<<endl;
            cout <<"Mommy has to read a book."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"Daddy is reading to the twins."<<endl;
            cout <<"Mommy get to drink a cup of coffee."<<endl;
            coffee++;
            cout <<endl;
         }
            break;
         case 3:
         {
            cout <<"Twins want to drink water"<<endl;
            cout <<"Mommy had to run to the kitchen and get them some "<<endl;
            cout <<"water."<<endl;
            cout <<endl;
         }
            break;
         case 4:
         {
            cout <<"Mommy tuck the twins in bed"<<endl;
            cout <<"Kids are asleep. Time to study."<<endl;
            cout <<"Mommy head to the computer room."<<endl;
            cout <<"Mommy gets a sticker"<<endl;
            cout <<endl;
         }
            break;
      }
   }
}

