/*********************************************************************
 **             Ellen Yang
 **             HarryPotter.cpp
 **             10/29/18.
 ** This is class HarryPotter implantation file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/

#include "HarryPotter.hpp"
#include <iostream>
using std::endl;
using std::cout;

/***********************************************************************
 **            HarryPotter::HarryPotter()
 ** default constructor, initilized attackPoints, defensePoints,
 ** armor, strength, and Hogwarts.
 ************************************************************************/
HarryPotter::HarryPotter():Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 0;
   this->strength = 10;
   this->Hogwarts = 0;
}

/***********************************************************************
 **            HarryPotter::HarryPotter(int armor, int strength)
 ** constructor that take aromor and strength as parameter
 ************************************************************************/
HarryPotter::HarryPotter(int armor, int strength):Character()
{
   this->armor = armor;
   this->strength = strength;
}

/***********************************************************************
 **            int HarryPotter::attack()
 ** roll 6 sides of dice twice and return the total attack points
 ************************************************************************/
int HarryPotter::attack()
{
   this->attackPoints = rollDie(2, 6);

   return attackPoints;
}

/***********************************************************************
 **            int Harry Potter::defense()
 ** roll 6 sides of dice twice and retun the total defense points
 ************************************************************************/
int HarryPotter::defense()
{
   this->defensePoints = rollDie(2,6);

   return defensePoints;
}

/**************************************************************************
 **       void HappyPotter::updateStrength(int damage)
 ** This function takes the damage as parameter thn update strength after being
 ** attack. Harry Potter can use Hogwarts the first time he dies.
 ****************************************************************************/
void HarryPotter::updateStrength(int damage) 
{
   strength -= damage; //calculate new strength

   //if strength becomes zero or less and never die before.
   if (strength <= 0 && Hogwarts == 0)
   {
      strength = 20;
      cout <<"   Hogwarts! Harry Potter's strength becomes 20." <<endl;
      Hogwarts++;
   }
}
