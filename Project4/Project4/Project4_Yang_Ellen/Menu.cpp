/*********************************************************************
 ** Program name: Menu.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2015
 ** Description: Menu.cpp is a class specification file for Menu class. This
 **              display the menu and allowes users to choose options during
 **              the program.
 *********************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <string>
#include "isDigit.hpp"

using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
 **               Menu::displayMenu()
 ** Description: a function to display menu
 *********************************************************************/
void Menu::displayMenu()
{
   for (int i = 0; i < menuString.size(); i++)
   {
      cout <<menuString[i]<<endl;
   }
}

/*********************************************************************
 **               Menu::addString()
 ** Description: a function to add string to the menu
 *********************************************************************/
void Menu::addString(string option)
{
   menuString.push_back(option);
}

/*********************************************************************
 **               int Menu::userInput(int MIN, int MAX)
 ** Description: a function that display menu, take int min option and int max
 **             option as parameter and take user input as string
 **             and return user input as valid integer
 *********************************************************************/
int Menu::userInput(int min, int max)
{
   displayMenu();
   string choice;

   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer)
   {
      cout << "Please enter positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   while (answer < min || answer > max)
   {
      cout << "Error, no such option !" <<endl;

      string choice;
      //takes in everything the user type in as string
      getline (cin, choice);
      //check to see if every charater in the string are numbers
      bool integer;
      integer = isDigit(choice);

      while (!integer)
      {
         cout << "Please enter positive integer only" <<endl;
         getline (cin, choice);
         integer = isDigit(choice);
      }
      //convert the string to integer with positive numbers only
      answer = stoi(choice);
   }

   return answer;
}
   /*********************************************************************
    **               int Menu::userInput(int min)
    ** Description: a function that display menu, take int min option
    **             as parameter and take user input as string
    **             and return user input as valid integer
    *********************************************************************/
   int Menu::userInput(int min)
   {
      displayMenu();
      string choice;

      getline (cin, choice); //takes in everything the user type in as string

      //check to see if every charater in the string are numbers
      bool integer;
      integer = isDigit(choice);

      while (!integer)
      {
         cout << "Please enter positive integer only" <<endl;
         getline (cin, choice);
         integer = isDigit(choice);
      }

      //convert the string to integer with positive non zero numbers only
      int answer = stoi(choice);

      while (answer < min)
      {
         cout << "Error, no such option !" <<endl;

         string choice;
         //takes in everything the user type in as string
         getline (cin, choice);
         //check to see if every charater in the string are numbers
         bool integer;
         integer = isDigit(choice);

         while (!integer)
         {
            cout << "Please enter positive integer only" <<endl;
            getline (cin, choice);
            integer = isDigit(choice);
         }
         //convert the string to integer with positive numbers only
         answer = stoi(choice);
      }

      return answer;
   }

/*********************************************************************
 **               int Menu::userInput()
 ** Description: a function that display menu, take user input as string
 **             and return user input as valid integer
 *********************************************************************/
int Menu::userInput()
{
   displayMenu();
   string choice;

   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer)
   {
      cout << "Please enter positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   //convert the string to integer with positive numbers only
   answer = stoi(choice);

   return answer;
}

/*********************************************************************
 **               int Menu::introMenu()
 ** Description: a function that display menu, take user input as string
 **             and return user input as valid integer
 *********************************************************************/
int Menu::introMenu()
{
   Menu menu1; 
   menu1.addString("Welcome to Fantasy Combat Game!");
   menu1.addString("Each team will pick fighters to fight for the tournament,");
   menu1.addString("would you like to play?");
   menu1.addString("1. Play");
   menu1.addString("2. Quit");

   return menu1.userInput(1, 2);
}

//ask for number of fighter per team
int Menu::numFighter()
{
   Menu menu;
   menu.addString("Please enter the number of fighters for both team.");
   menu.addString("min 1, max 5");

   return menu.userInput(1, 5);
}



/*********************************************************************
 **               int Menu::pickCharacter()
 ** Description: a function that display menu for the characters and ask user
 **              to pick one and take user input as string and return user
 **              input as valid integer
 *********************************************************************/
int Menu::pickCharacter()
{
   Menu menu2;
   menu2.addString("Please pick a character:");
   menu2.addString("1.Vampire");
   menu2.addString("2.Barbarian");
   menu2.addString("3.Blue Men");
   menu2.addString("4.Medusa");
   menu2.addString("5.Harry Potter");

   return menu2.userInput(1, 5);
}

/*********************************************************************
 **               int Menu::combatMenu()
 ** Description: a function lets the users know game is over and ask if user
 **              wants to play again, take user input as string
 **              and return user input as valid integer
 *********************************************************************/
int Menu::combatMenu()
{
   Menu menu3;
   menu3.addString("Game Over!");
   menu3.addString("Would you like to play agian?");
   menu3.addString("1. Play");
   menu3.addString("2. Quit");

   return menu3.userInput(1, 2);
}

//display loser pile
int Menu::displayLoser()
{
   Menu loser;
   loser.addString("Do you want to see the content of the loser pile");
   loser.addString("1. Yes");
   loser.addString("2. No");

   return loser.userInput(1,2);
}
