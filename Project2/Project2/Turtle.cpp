/*********************************************************************
 ** Program name: Turtle.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Turtle.cpp is a Turtle class specification file. It is the
 **               child class of animals class. It has member variable of
 **               age, cost, numOfBabies, baseFoodCost and payOff that is
 **               different than animal class.
 *********************************************************************/
#include "Animal.hpp"
#include "Turtle.hpp"

/*********************************************************************
 **              Turtle::Turtle()
 ** Description:a default constructor
 *********************************************************************/
Turtle::Turtle():Animal()
{
   this->age = 1;
   this->cost = 100;
   this->numOfbabies = 10;
   this->baseFoodCost = .5 * Animal::getBaseFoodCost();
   this->payOff = .05 * getCost();
}
/*********************************************************************
 **    Turtle::Turtle(int age)
 ** Description:a constructor that take int age as parameter.
 *********************************************************************/
Turtle::Turtle(int age):Animal(age)
{
   this->age = age;
   
}
