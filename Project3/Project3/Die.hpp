/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the Die.hpp class class specification file, which has member
 **               variable int numSide that represents the number of sides on
 **               die, a function that return random integer when user roll
 **               the die.
 *********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
   protected: 
      int numSide; //number of sides on the indiviual die

   public:
      int rollDie(); // function that returns a random integer between 1 and N
                     //as result of rolling the die once

      Die(int side) //contructor that take integer number of sides as parameter
      { numSide = side;}

};

#endif
