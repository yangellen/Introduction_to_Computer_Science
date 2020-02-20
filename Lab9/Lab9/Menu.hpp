/*********************************************************************
 ** Program name: Menu.hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description: Menu.hpp is a class specification file for Menu class. This
 **              display the menu and allowes users to choose options during
 **              the program.
 *********************************************************************/
#ifndef Menu_hpp
#define Menu_hpp

#include <vector> //needed to use vectors
#include <string>

using std::string;
using std::vector;

class Menu
{
   private:
      vector<string>menuString;//menuString as an empty vector of string objects

   public:
      void displayMenu(); // a function to display menu
      void addString(string); // take string as parameter and add to menu

      // displayMenu, take intger min option and interger max options as
      // parameter and take user input as string and return a valid integer
      int userInput(int min, int max);

      // displayMenu, take intger min option as
      // parameter and take user input as string and return a valid integer
      int userInput (int min);

      // displayMenu,take user input as string and return a valid integer
      int userInput ();

      //integers, both positive and negative
      int validate();

      //return number of rounds will be simulated
      int roundMenu();

      //return the percentage chance to add random number at the end of buffer
      int addEndChance();

      //ask the percentage change to remove random number the front of buffer
      int removeFrontChance();

      //ask user to under a string
      string stackMenu();

      //introduction
      int introMenu();

};

#endif
