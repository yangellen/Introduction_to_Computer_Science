/*********************************************************************
 ** Program name: Penguin.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Penguin.cpp is a Penguin class specification file. It is the
 **               child class of animals class. It has member variable of
 **               age, cost, numOfBabies, baseFoodCost and payOff that is
 **               different than animal class.
 *********************************************************************/
#include "Animal.hpp"
#include "Penguin.hpp"

/*********************************************************************
 **              Penguin::Penguin()
 ** Description:a default constructor
 *********************************************************************/
Penguin::Penguin():Animal()
{
   this->age = 1;
   this->cost = 1000;
   this->numOfbabies = 5;
   this->baseFoodCost = Animal::getBaseFoodCost();
   this->payOff = .1 * getCost();
}
/*********************************************************************
 **    Penguin::Penguin(int age, int cost, int babies, int foodCost, int payOff )
 ** Description:a constructor that take int age as parameter.
 *********************************************************************/
Penguin::Penguin(int age):Animal(age)
{
   this->age = age;
}
