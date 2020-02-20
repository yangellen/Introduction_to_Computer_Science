/*********************************************************************
 **             Ellen Yang
 **            Character.cpp
 **              10/25/18.
 ** This is class Character implantation file. This is the abstract base class
 ** for the different character classes.
 ****************************************************************************/

#include "Character.hpp"
#include "Die.hpp"
#include <iostream>

using std::cout;
using std::endl; 

/***********************************************************************
 **        Character::Character()
 ** default constructor
************************************************************************/
Character::Character()
{
   this->attackPoints = 0;
   this->defensePoints = 0;
   this->armor = 0;
   this->strength = 0;
}

/***********************************************************************
 **    int Character::roll(int numRoll, int numSide)
 ** take number of rolls and number of side of die  as parameter and return
 ** the sum of all rolls
 ************************************************************************/
int Character::rollDie(int numRoll, int numside)
{
   int total = 0;

   Die die(numside);
   for (int i = 0; i< numRoll; i++)
   {
      total += die.rollDie();
   }
   return total;
}

/**************************************************************************
**       void Character::updateStrength(int damage)
** This function takes the damage as parameter thn update strength after being
** attack
****************************************************************************/
void Character::updateStrength(int damage)
{
   strength -= damage; //calculate new strength
}

//defalut destructor
Character::~Character()
{

}


