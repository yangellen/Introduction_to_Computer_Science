/*********************************************************************
 ** Program name: Tiger.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Tiger.cpp is a Tiger class specification file. It is the
 **               child class of animals class. It has member variable of
 **               age, cost, numOfBabies, baseFoodCost and payOff that is
 **               different than animal class.
 *********************************************************************/
#include "Animal.hpp"
#include "Tiger.hpp"

/*********************************************************************
 **              Tiger::Tiger()
 ** Description:a default constructor
 *********************************************************************/
Tiger::Tiger():Animal()
{
   this->age = 1;
   this->cost = 10000;
   this->numOfbabies = 1;
   this->baseFoodCost = 5 * Animal::getBaseFoodCost();
   this->payOff = .2 * getCost();
}
/*********************************************************************
 **    Tiger::Tiger(int age)
 ** Description:a constructor that take int age as parameter.
 *********************************************************************/
Tiger::Tiger(int age):Animal(age)
{
   this->age = age;
}

