/*********************************************************************
 ** Author:       Ellen Yang
 ** Program:      Instructor.cpp
 ** Date:         Oct 19, 2018
 ** Description:  This is class Instructor implenmentation file, which
 **               is derived class from Person class. This class has additional
 **               rating as member variable and modified do_work function.
 *********************************************************************/
#include "Instructor.hpp"
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************************
 **              Instructor::Instructor()
 **    default constructor which initilized rating. 
 ******************************************************************/
Instructor::Instructor() : Person()
{
   rating = 0.0;
}

/****************************************************************************
 **                Instructor::Instructor(strin name, int age, double rating)
 **    constructor that takes instructor's name, age and rating as parameters
 ****************************************************************************/
Instructor::Instructor(string name, int age, double rating) : Person(name,age)
{
   this->rating = rating;
}

//getter function for GPA
double Instructor::getRating()
{
   return rating;
}

//destructor
Instructor::~Instructor()
{

}
/**************************************************************************
 **                  int Instructor:: do_work()
 **   A funciton generaes a random number that represents how many hours
 **  they will do work for, and then output message depending for a instructor
 ****************************************************************************/
int Instructor::do_work()
{
   int hourWork = 0;

   hourWork = rand() % 40;

   cout << name <<" " <<"graded papers for  "<<hourWork <<" hours." <<endl;

   return hourWork;
}

/**************************************************************************
 **            void Instructor::printInfor()
 **  This function prints the information of the instructor (name, age, rating)
 ***************************************************************************/
void Instructor::printInfo()
{
   Person::printInfo();
   cout << "Rating: " <<getRating()<<endl;
}
