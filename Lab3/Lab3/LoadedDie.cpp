/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the LoadedDie.cpp class class implementation file, which has
 **               member variable int numSide that represents the number of
 **               sides on die, a function that return the average of two
 **               random integers when user roll the die twice.
 *********************************************************************/
#include "LoadedDie.hpp"

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>

/*********************************************************************
 **               Loaded::rollDie()
 ** Description: This function randomlly select number from 1-N and return the
 **              number plus one if it's not higher than the number of sides it
 **              has.
 *********************************************************************/
int LoadedDie::rollDie()
{
   int const MIN = 1;
   int const MAX = numSide;

   int numRoll;

   numRoll = (rand() % (MAX - MIN + 1)) + MIN;

   if (numRoll < numSide) //add one to the die if not exceed number of side
   {
      numRoll++;
   }

   return numRoll;
}
/*********************************************************************
 **               Loaded::LoadedDie(int side):Die(side)
 ** Description: A constructor that take integer the number of side as
 **              parameter, which inherited from it's base class
 *********************************************************************/
LoadedDie::LoadedDie(int side):Die(side)
{
   numSide = side;
}
