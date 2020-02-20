/*********************************************************************
 ** Program name: Tiger hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Tiger.hpp is a Tiger class specification. It is the
 **               Child class for Animal class.
 *********************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger: public Animal //child class
{
   public:
      Tiger();//default constructor
      Tiger (int); //constructor that takes parameters

};
#endif
