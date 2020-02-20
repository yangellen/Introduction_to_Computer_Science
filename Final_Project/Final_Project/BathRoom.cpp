/****************************************************************************
 **  Ellen Yang
 **  BathRoom.hpp
 **  This is the BathRoom class implantation file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#include "BathRoom.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  BathRoom::BathRoom():Space()
 **  default constructor for BathRoom
 ****************************************************************************/
BathRoom::BathRoom():Space()
{
   this->spaceName = "Bathroom";
   }

/****************************************************************************
 **  void BathRoom::roomIntro()
 **  This functions display the introduction and the goal of BathRoom.
 ****************************************************************************/
void BathRoom::roomIntro()
{
   cout <<"**************************************************************"<<endl;
   cout <<"* You are in the bathroom with the twins.                    *"<<endl;
   cout <<"* Your goal is to have the kids brush and floss their teeth, *"<<endl;
   cout <<"* so you can head to the kid's room. You will need to collect*"<<endl;
   cout <<"* sticker in order to enter the next room.                   *"<<endl;
   cout <<"* Every time you roll the dice, you will lost one engergy    *"<<endl;
   cout <<"* points. Whenever you get to drink coffee, you can have     *"<<endl;
   cout <<"* extra energy to use later if your bag is not full          *"<<endl;
   cout <<"**************************************************************"<<endl;
   cout <<endl;
}

/****************************************************************************
 **  void BathRoom::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will keep on rolling the dice until the goal has met. Player will
 **  use 1 energy per roll and collect a sticker when goal has met.
 ****************************************************************************/
void BathRoom::randomEvent()
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
            cout <<"Kids doesn't want to take a bath"<<endl;
            cout <<"Mommy has to sing the bath song."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"The twins are enjoying bubble bath."<<endl;
            cout <<"Mommy get to drink a cup of coffee and watch them"<<endl;
            cout <<"playing bubbles."<<endl;
            coffee++;
            cout <<endl;
         }
            break;
         case 3:
         {
            cout <<"One of the twins pee in the tub!"<<endl;
            cout <<"Mommy had to drain the water, clean the kids "<<endl;
            cout <<"with soap and water. Rinse and start the bath over."<<endl;
            cout <<endl;
         }
            break;
         case 4:
         {
            cout <<"Kids finished brush and floss their teeth."<<endl;
            cout <<"Time for bed, let's head to kid's room."<<endl;
            cout <<"Mommy gets a sticker"<<endl;
            cout <<endl;
         }
            break;
      }
   }
}


