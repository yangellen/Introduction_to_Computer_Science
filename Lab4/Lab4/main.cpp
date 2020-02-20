/*********************************************************************
 ** Author:        Ellen Yang
 ** Date:          Oct. 19, 2018
 ** Description:   OSU Information System which lets user choose to print
 **                building informations, people information or choose a
 **                person to do work.
 *********************************************************************/ 
#include <iostream>
#include <cstdlib> //needed to use srand and rand
#include <ctime> //needed to use time
#include "University.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Menu.hpp"

using std::cout;
using std::endl;

int main()
{
   unsigned seed; //random generator seed
   seed = time(0);
   srand(seed);

   University osu ("Oregon State University"); //create University obj

   Building building1   //create Building obj
      ("Owen Hall", 64501,"1501 SW Campus Way, Corvallis , OR 97331");

   Building building2
      ("Adams Hall", 11168, "606 SW 15Th St. Corvallis, OR 97331");

   osu.addBuilding(building1); //add to buildingV vector
   osu.addBuilding(building2);

   osu.addInstructor ("Luyao Zhang",35, 4.1);
   osu.addStudent("Ellen Yang", 26, 3.9);

   Menu menu;
   int userChoice;

   menu.addString("Please select one of the options: ");
   menu.addString(" 1. Print information about all the buildings");
   menu.addString(" 2. Print informaiton about everybody at the university");
   menu.addString(" 3. Choose a person to do work");
   menu.addString(" 4. Exit the program");
   userChoice = menu.userInput(1, 4);

   switch (userChoice)
   {
      case 1: osu.printBuilding();
         break;

      case 2: osu.printPeople();
         break;

      case 3: osu.printName();
         break;

      case 4: cout << "Goodbye!"<<endl;
   }
   
   return 0;
}
