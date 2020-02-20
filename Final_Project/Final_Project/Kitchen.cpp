/****************************************************************************
**  Ellen Yang
**  Kitchen.hpp
**  This is the Kitchen class implantation file. This is the child class
**  of Space class in this game. The class has it's own introduction and
**  random events.
****************************************************************************/

#include "Kitchen.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **  Kitchen::Kitchen():Space()
 **  default constructor for Kitchen
 ****************************************************************************/
Kitchen::Kitchen():Space()
{
   this->spaceName = "Kitchen";
   }

/****************************************************************************
 **  void Kitchen::roomIntro()
 **  This functions display the introduction and the goal of Kitchen.
 ****************************************************************************/
void Kitchen::roomIntro()
{
   cout <<"*************************************************************"<<endl;
   cout <<"*  You are in the kitchen with the twins.                   *"<<endl;
   cout <<"*  Your goal is to have the kids finish eating their dinner,*"<<endl;
   cout <<"*  so you can head to the bathroom. You will need to collect*"<<endl;
   cout <<"*  one sticker in order to enter the next room.             *"<<endl;
   cout <<"*  Every time you roll the dice, you will lost one engergy  *"<<endl;
   cout <<"*  points. Whenever you get to drink coffee, you can have   *"<<endl;
   cout <<"*  extra energy to use later if your bag is not full        *"<<endl;
   cout <<"*************************************************************"<<endl;
   cout <<endl;

}

/****************************************************************************
 **  void Kitchen::randomEvent()
 **  A funtions that lets player roll dice for random events in the room.
 **  Player will keep on rolling the dice until the goal has met. Player will
 **  use 1 energy per roll and collect a sticker when goal has met.
 ****************************************************************************/
void Kitchen::randomEvent()
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
            cout <<"Mac and Cheese are ruuning low"<<endl;
            cout <<"Mommy has to cook more."<<endl;
            cout <<endl;
         }
            break;
         case 2:
         {
            cout <<"The twins loves mommy's cooking and couln't stop eating"<<endl;
            cout <<"Mommy get to drink a cup of coffee and enjoy dinner, too"<<endl;
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
            cout <<"Twins finished eating dinner."<<endl;
            cout <<"Mommy gets a sticker"<<endl;
            cout <<endl;
         }
            break;
      }
   }
}

