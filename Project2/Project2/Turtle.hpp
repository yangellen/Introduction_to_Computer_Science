/*********************************************************************
 ** Program name: Turtle.hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Turtle.hpp is a Turtle class specification. It is the
 **               Child class for Animal class.
 *********************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle: public Animal //child class
{
   public:
      Turtle();//default constructor
      Turtle (int); //constructor that takes age as parameter

};
#endif
