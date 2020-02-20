/*********************************************************************
 ** Author:          Ellen Yang
 **                  Person.cpp
 ** Date:            Oct 19, 2018
 ** Description:     Person. cpp is Person class implementation file, which act
 **                  as base class for Student class, Instructor class.
 *********************************************************************/
#include "Person.hpp"
#include <cstdlib> //for random number

using std::cout;
using std::endl;


/***********************************************************************
 **                Person()::Person()
 **         default contractor which initilized member variable name, age.
 ************************************************************************/
 Person::Person()
{
   name = "noName";
   age = 0;
}
/**************************************************************************
 **            Person()::Person(string name, int age)
 **         a constractior that takes name and age as parameter
***************************************************************************/
Person::Person(string name, int age)
{
   this->name = name;
   this->age = age;
}

//destructor
Person::~Person()
{

}

//getter function that return the name of the person
string Person::getName()
{
   return name;
}

//getter function that return the age of the person
int Person::getAge()
{
   return age;
}
/*****************************************************************************
** funciton:    int Person::do_work()
**           A funciton generaes a random number that represents how many hours
**          they will do work for, and then output message depending on if
**          the Person is a Student or Instructor.
****************************************************************************/
int Person::do_work()
{
   int hourWork = 0;

   hourWork = rand() % 40;
   
   return hourWork;
}

/*****************************************************************************
 **                void Person::printInfor()
 ** This function prints the information of the person (name, age)
 ***********************************************************************/
void Person::printInfo()
{
   cout << "Name: " <<getName()<<endl;
   cout << "Age: " <<getAge()<<endl;
}
