/*********************************************************************
 **             Ellen Yang
 **             Medusa.cpp
 **             10/29/18.
 ** This is class Medusa implantation file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/

#include "Medusa.hpp"
#include <iostream>

using std::endl;
using std::cout;

/***********************************************************************
 **            Medusa::Medusa()
 ** default constructor, initilized attackPoints, defensePoints,
 ** armor and strength
 ************************************************************************/
Medusa::Medusa():Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 3;
   this->strength = 8;
}

/***********************************************************************
 **            Medusa::Medusa(int armor, int strength)
 ** constructor that take aromor and strength as parameter
 ************************************************************************/
Medusa::Medusa(int armor, int strength):Character()
{
   this->armor = armor;
   this->strength = strength;
}

/***********************************************************************
 **            int Medusa::attack()
 ** roll 6 sides of dice twice and return the total attack points. Medusa has
 ** specail ability Glare. If medusa rolls a 12 during attack, the defender
 ** turned into stone.
 ************************************************************************/
int Medusa::attack()
{
   this->attackPoints = rollDie(2, 6);

   if (this->attackPoints == 12)
   {
      cout <<"   Medusa uses Glare!" <<endl;
      attackPoints = 900;
   }
   else
   {
      cout <<"   No Glare." <<endl;
   }

   return attackPoints;
}

/***********************************************************************
 **            int Medusa::defense()
 ** roll 6 sides of dice once and retun the total defense points
 ************************************************************************/
int Medusa::defense()
{
   this->defensePoints = rollDie(1,6);

   return defensePoints;
}
