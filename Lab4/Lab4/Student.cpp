/*********************************************************************
 ** Author:       Ellen Yang
 ** Program:      Student.hpp
 ** Date:         Oct 19, 2018
 ** Description:  This is Student.cpp class Student implementation file, which
 **               is derived class from Person class. This class has additional
 **               GPA member variable and modified do_work function.
 *********************************************************************/
#include "Student.hpp"
#include <iostream>

using std::cout;
using std::endl; 

/****************************************************************************
 **               Student::Student()
 **    default constructor which initilized GAP
 ******************************************************************/
Student::Student() : Person()
{
   GPA = 0.0;
}

/****************************************************************************
 **                Student::Student(string name, int age, double GPA)
 **    constructor that takes, student's name, age and  GPA as parameter
 ****************************************************************************/
Student::Student(string name, int age, double GPA) : Person(name,age)
{
   this->GPA = GPA;
}

//getter function for GPA
double Student::getGPA()
{
   return GPA;
}

//destructor
Student::~Student()
{

}
/**************************************************************************
 **                  int Student:: do_work()
 **   A funciton generaes a random number that represents how many hours
 **  they will do work for, and then output message depending for a Student
 ****************************************************************************/
int Student::do_work()
{
   int hourWork = 0;

   hourWork = rand() % 40;

   cout << name <<" " <<"did "<<hourWork <<" hours of homework." <<endl;

   return hourWork;
}
/**************************************************************************
 **            void Student::printInfor()
 **  This function prints the information of the student (name, age, GPA)
 ***************************************************************************/
void Student::printInfo()
{
   Person::printInfo();
   cout << "GPA: "<<getGPA() <<endl; 

}
