/*********************************************************************
 **             Ellen Yang
 **             Vampire.cpp
 **             10/28/18.
 ** This is class Vampire implantation file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/

#include "Vampire.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std:: endl;  

/***********************************************************************
 **            Vampire::Vampire()
 ** default constructor, initilized attackPoints, defensePoints,
 ** armor and strength
 ************************************************************************/
Vampire::Vampire():Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 1;
   this->strength = 18;
   this->playerType = "Vampire";
}

/***********************************************************************
 **            Vampire::Vampire(int armor, int strength)
 ** constructor that take aromor and strength as parameter
 ************************************************************************/
Vampire::Vampire(string name, string type, int armor, int strength):Character()
{
   this->playerType = type;
   this->name = name; 
   this->armor = armor;
   this->strength = strength;
}

/***********************************************************************
 **            int Vampire::attack()
 ** roll 12 sides of dice once and return the total attack points
 ************************************************************************/
int Vampire::attack()
{
   this->attackPoints = rollDie(1, 12);

   return attackPoints;
}

/***********************************************************************
 **            int Vampire::defense()
 ** roll 6 sides of dice once and retun the total defense points. Vampire has
 ** charm special ablility. There are 50% chance that their opponent does not
 ** actually attack them. 
 ************************************************************************/
int Vampire::defense()
{


   if (!charm()) //if no charm
   {
      this->defensePoints = rollDie(1,6);
     // cout <<"   Vampire's charm didn't work!" <<endl;
   }
   else
   {
      this->defensePoints = 1000;
     // cout <<"   Vampire used Charm!"<<endl; 
   }

   return defensePoints;
}

/************************************************************************
 **   bool Vampire:: charm ()
 **  A function to check if vampire used charm. Return true if charm is used.
*************************************************************************/
bool Vampire::charm()
{
   int random = rand() % 2 + 1; // return 1, 2
   bool charm = true;

   if (random == 1)
   {
      charm = true;
   }
   else if (random == 2)
   {
      charm = false;
   }
   return charm;
}
