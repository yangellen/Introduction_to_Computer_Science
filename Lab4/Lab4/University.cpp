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
#include "University.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.hpp"


using std::endl;
using std::cout;

/***************************************************************************
University::University(string name, vector<Building> &, vector<Person> &person)
 **         A constructor that take string name as parameter
*****************************************************************************/
University::University(string name)
{
   this->universityName = "Oregon State University";
}

/***************************************************************************
 **          Univrsity::~Univeristy()
 ** A destructor deallocats memory that was dynamically allocate.
 ***************************************************************************/
University::~University()
{
   for (int i = 0; i < peopleV.size(); i++)
   {
      delete peopleV[i];
   }
}

/****************************************************************************
 **            void University::addBuilding(Building building)
 **  A function that can add building object to buildingV vector
 **************************************************************************/
void University:: addBuilding(Building building)
{
   buildingV.push_back(building);
}
/****************************************************************************
 **     void University::addInstructor(string name, int age, double rate)
 **  A function that adds Instructor to peopleV vector
 **************************************************************************/
void University::addInstructor(string name, int age, double rate)
{
   peopleV.push_back(new Instructor(name, age, rate));
}
/****************************************************************************
 **             void University::addStudent(string name, int age, double gpa)
 **  A function that adds Person  to peopleV vector
 **************************************************************************/
void University::addStudent(string name, int age, double gpa)
{
   peopleV.push_back(new Student (name, age, gpa));
}

/***************************************************************************
**            void University::printBuilding()
**  This function prints the information on all the buildings (name, address,
**   building's size)
**************************************************************************/
void University::printBuilding()
{
   for ( int i = 0; i < buildingV.size() ; i++)
   {
      cout << "Building: " << buildingV[i].getBuildingName() <<endl;
      cout << "Address: " << buildingV[i].getBuildingAddress() <<endl;
      cout << "Size:" <<buildingV[i].getBuildingSize()<< " sqft." <<endl;
      cout <<endl; 
   }
}
/****************************************************************************
 **            void University::printPeople()
 **  A function print information of all people (name, age, GPA or Rating)
 ***************************************************************************/
void University::printPeople()
{
   /*
   Student *ptr = nullptr;

   for (int i = 0; i < peopleV.size(); i++)
   {
      cout << "Name " <<peopleV[i].getName() <<endl;
      cout << "Age " <<peopleV[i].getAge() <<endl;

      if ( (ptr = dynamic_cast<Person>(peopleV[i] != nullptr ))
      {
         ptr->printInfo();
      }
    */
   for (int i = 0; i < peopleV.size(); i++)
   {
      peopleV[i]->printInfo();
      cout <<endl;
   }
}

/****************************************************************************
 **            void University::printName()
 **  A function print all people's name
 ***************************************************************************/
void University::printName()
{
   int userInput;
   Menu menu;
   menu.addString("Choose a person to do work from above list: ");

   for (int i = 0; i < peopleV.size(); i++)
   {
      cout << i  << ". ";
      cout << peopleV[i]->getName()<<endl;
   }
   userInput = menu.userInput(0, peopleV.size());

   peopleV[userInput]->do_work();

}
