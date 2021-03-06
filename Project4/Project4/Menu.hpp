/*********************************************************************
 ** Program name: Menu.hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2015
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

      //intro menu for the game
      int introMenu();

      //ask for number of fighter per team
      int numFighter();

      //choose character
      int pickCharacter();

      //display loser pile
      int displayLoser();

      //endOfGame
      int combatMenu();
};

#endif
