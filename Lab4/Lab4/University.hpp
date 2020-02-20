/*********************************************************************
 ** Author:       Ellen Yang
 ** Program:      University hpp
 ** Date:         10/19/2018
 ** Description:This is University.hpp specification file, which contains the
 **             Person objectss (base class for student and instructor),
 **             Building objects that store in vectors of pointers. It also
 **             contains functions that print out building and people
 **             information.
 *********************************************************************/ 
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <vector> //1D array
#include <string>
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

using std::string;
using std::vector;


class University
{
   private:
      string universityName; // name of University
      vector<Building> buildingV; //buildingV is vector of Building obj
      vector <Person*> peopleV; //peopleV is vector of Person obj

      public:
      //constructor takes parameters
      University(string name);

      ~University();

      void addBuilding(Building building);//add building obj to buildingV vector

      void addInstructor(string name, int age, double rate);

      void addStudent(string name, int age, double GPA); 

      //prints the information on all the buildings (name, address,
      //building's size)
      void printBuilding();

      //print information of all people (name, age, GPA or Rating)
      void printPeople();

      //print all people name
    void printName();
};

#endif
