/*********************************************************************
 ** Program name: Menu.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description: Menu.cpp is a class specification file for Menu class. This
 **              display the menu and allowes users to choose options during
 **              the program.
 *********************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <limits>
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

/***************************************************************************
 ** int Menu::validate()
 ** A function used to validate user input, which will keep ask for
 ** for integers only if user input wrong data type.
 **************************************************************************/
int Menu::validate()
{
   displayMenu();
   int numChoice;
   cin >> numChoice;

   while (cin.fail())
   {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout <<"Please enter integers only!"<<endl;
      cin>>numChoice;
   }

   return numChoice;
}

/*****************************************************************************
 ** int Menu::introMenu()
 ** A funtion to ask for target value for search, and return user input after
 ** validation.
***************************************************************************/
int Menu::introMenu()
{
   addString("What is target Value:");

   return validate();
}
