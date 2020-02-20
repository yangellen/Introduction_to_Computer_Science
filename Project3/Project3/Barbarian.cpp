/*********************************************************************
 **             Ellen Yang
 **             Barbarian.cpp
 **             10/25/18.
 ** This is class Barbarian implantation file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/

#include "Barbarian.hpp"

/***********************************************************************
 **            Barbarian::Barbarian()
 ** default constructor, initilized attackPoints, defensePoints,
 ** armor and strength
 ************************************************************************/
Barbarian::Barbarian():Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 0;
   this->strength = 12;
}

/***********************************************************************
 **            Barbarian::Barbarian(int armor, int strength)
 ** constructor that take aromor and strength as parameter
 ************************************************************************/
Barbarian::Barbarian(int armor, int strength):Character()
{
   this->armor = armor;
   this->strength = strength;
}

/***********************************************************************
**            int Barbarian::attack()
** roll 6 sides of dice twice and return the total attack points
************************************************************************/
int Barbarian::attack()
{
   this->attackPoints = rollDie(2, 6);

   return attackPoints;
}

/***********************************************************************
 **            int Barbarian::defense()
 ** roll 6 sides of dice twice and retun the total defense points
 ************************************************************************/
int Barbarian::defense()
{
   this->defensePoints = rollDie(2,6);

   return defensePoints;
}

