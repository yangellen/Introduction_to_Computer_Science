/*********************************************************************
 ** Author:          Ellen Yang
 **                  Person.hpp
 ** Date:            Oct 19, 2018
 ** Description:     Person. hpp is Person class specification file, which act
 **                  as base class for Student class, Instructor class.
 *********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

using std::string;

class Person
{
   protected:
      string name; //name of person
      int age;//age of person

   public:
      Person();
      Person(string, int);

      ~Person();

      virtual string getName();
      virtual int getAge();

      virtual int do_work();
   
      virtual void printInfo();   
};

#endif
