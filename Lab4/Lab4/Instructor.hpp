/*********************************************************************
 ** Author:       Ellen Yang
 ** Program:      Instructor.hpp
 ** Date:         Oct 19, 2018
 ** Description:  This is class Instructor specification file, which
 **               is derived class from Person class. This class has additional
 **               rating as member variable and modified do_work function.
 *********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>
#include <string>
#include "Person.hpp"

using std::string;

class Instructor : public Person
{
   private:
      double rating; //0.0-5.0

   public:
      Instructor();
      Instructor(string, int, double);

      ~Instructor();

      double getRating();
      void printInfo();
   
      int do_work();
};

#endif
