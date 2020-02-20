/*********************************************************************
 ** Author:       Ellen Yang
 ** Program:      Student.hpp
 ** Date:         Oct 19, 2018
 ** Description:  This is Student.hpp class Student specification file, which
 **               is derived class from Person class. This class has additional
 **               GPA member variable and modified do_work function.
 *********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"
#include <iostream>
#include <string>

using std::string;

class Student : public Person
{
   private:
      double GPA; //0.0-4.0

   public:
      Student();
      Student(string, int, double);

      ~Student();

      double getGPA();
      int do_work();

      void printInfo();
};

#endif
