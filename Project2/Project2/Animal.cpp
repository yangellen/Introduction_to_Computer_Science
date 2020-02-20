/*********************************************************************
 ** Program name: Animal cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Animal cpp is a animal class implantation file. It is the
 **               base class for other animals. It has member variable of
 **               age, cost, numOfBabies, baseFoodCost and payOff.
 *********************************************************************/
#include "Animal.hpp"

/*********************************************************************
 **              Animal::Animal()
 ** Description:a default constructor
 *********************************************************************/
Animal::Animal()
{
   this->age = 1;
   this->cost = 0;
   this->numOfbabies = 0;
   this->baseFoodCost = 10; //set base food cost $10
   this->payOff = 0;
}
/*********************************************************************
 **    Animal::Animal(int age)
 ** Description:a constructor that take int age as parameter.
 *********************************************************************/
Animal::Animal(int age)
{
   this->age = age;
}

//get function for age, which return the age of the animal
int Animal::getAge()
{
   return age;
}
//get function for cost, which return the cost of animals
int Animal::getCost()
{
   return cost;
}
//get function for numOfBabies, which return the number of babies
int Animal::getNumOfBabies()
{
   return numOfbabies;
}
//get function for base food cost, which return the base food cost
int Animal::getBaseFoodCost()
{
   return baseFoodCost;
}
//get function for payoff, which return the pay off at the end of day
int Animal::getPayOff()
{
   return payOff;
}

/*********************************************************************
 **    void Animal::increaseAge()
 ** Description:increase animal age by one day
 *********************************************************************/
void Animal::increaseAge()
{
   this->age ++;
}

//default destructor
Animal::~Animal()
{
   
}
