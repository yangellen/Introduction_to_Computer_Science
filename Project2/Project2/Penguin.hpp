/*********************************************************************
 ** Program name: Penguin.hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Penquin.hpp is a Penguin class specification. It is the
 **               Child class for Animal class.
 *********************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin: public Animal //child class
{
public:
   Penguin();//default constructor
   Penguin(int); //constructor that takes age as parameter

};
#endif
