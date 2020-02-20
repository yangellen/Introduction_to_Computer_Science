/*********************************************************************
 **             Ellen Yang
 **             BlueMen.cpp
 **             10/28/18.
 ** This is class BlueMen implantation file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#include "BlueMen.hpp"
#include <iostream>

using std::cout;
using std::endl;

/***********************************************************************
 **            BlueMen::BlueMen()
 ** default constructor, initilized attackPoints, defensePoints,
 ** armor and strength
 ************************************************************************/
BlueMen::BlueMen():Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 3;
   this->strength = 12;
   this->playerType = "Blue Men";
}

/***********************************************************************
 **            BlueMen::BlueMen(int armor, int strength)
 ** constructor that take aromor and strength as parameter
 ************************************************************************/
BlueMen::BlueMen(string name, string type,int armor, int strength):Character()
{
   this->name = name;
   this->playerType = type;
   this->armor = armor;
   this->strength = strength;
}

/***********************************************************************
 **            int BlueMen::attack()
 ** roll 10 sides of dice twice and return the total attack points
 ************************************************************************/
int BlueMen::attack()
{
   this->attackPoints = rollDie(2, 10);

   return attackPoints;
}

/***********************************************************************
 **            int BlueMen::defense()
 ** roll 6 sides of dice three times and retun the total defense points when
 ** no damage occur. However; when Mob occur, every 4 points of damage, they
 ** lose one defense die.
 ************************************************************************/
int BlueMen::defense()
{
   switch (this->strength)
   {
      case 12:
      case 11:
      case 10:
      case  9:
      {
         this->defensePoints = rollDie(3,6);
        // cout<<"   No Mob " <<endl;
      }
         break;
      case 8:
      case 7:
      case 6:
      case 5:
      {
         this->defensePoints = rollDie(2,6);
         //cout<<"   Mob, lose one defense die" <<endl;
      }
         break;
      case 4:
      case 3:
      case 2:
      case 1:
      {
         this->defensePoints = rollDie(1,6);
         //cout<<"   Mob, lose two defense dice" <<endl;
      }
         break;
   }

   return defensePoints;
}
