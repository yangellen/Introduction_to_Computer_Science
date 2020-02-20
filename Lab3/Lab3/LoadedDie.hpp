/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 11, 2018
 ** Description:  the LoadedDie.hpp class class specification file, which has
 **               member variable int numSide that represents the number of
 **               sides on die, a function that return random number from 1-N
 **               integers plus 1 if the number is not at the maximun. 
 *********************************************************************/
#ifndef LOADEDDIE_hpp
#define LOADEDDIE_hpp

#include "Die.hpp"

class LoadedDie: public Die  //derivated class of Die class
{
   public:
      LoadedDie(int);
      int rollDie(); //override the rollDie function in base class
};

#endif
