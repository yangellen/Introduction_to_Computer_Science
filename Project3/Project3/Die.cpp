/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the Die.cpp class class implementation file, which has member
 **               variable int numSide that represents the number of sides on
 **               die, a function that return random integer when user roll
 **               the die.
 *********************************************************************/
#include "Die.hpp"

#include <cctype>
#include <cstdlib>
#include <ctime>

/*********************************************************************
 **               Die::rollDie()
 ** Description: This function randomlly select number from 1-N and retun the
 **              number as integer.
 *********************************************************************/
int Die::rollDie()
{
   int const MIN = 1;
   int const MAX = numSide;

   return (rand() % (MAX - MIN + 1)) + MIN;
 }
