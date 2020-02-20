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
#include <string>
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

/*********************************************************************
 **               int Menu::introMenu()
 ** Description: a function that display menu, take user input as string
 **             and return user input as valid integer
 *********************************************************************/
int Menu::introMenu()
{
   Menu menu1;
   menu1.addString("Ready for bed?!");
   menu1.addString("You just pick up your twins from preschool.");
   menu1.addString("You are tired from working all day.");
   menu1.addString("All you want to do is sleep.");
   menu1.addString("but before you head to bed, you need to finish your to-do list.");
   menu1.addString("Your goal is to go to bed before you run out of the energy.");
   menu1.addString("Are you ready to play?");
   menu1.addString("1. Play");
   menu1.addString("2. Quit");

   return menu1.userInput(1, 2);
}

/*********************************************************************
 **               int Menu::againMenu()
 ** Description: a function lets the users know game is over and ask if user
 **              wants to play again, take user input as string
 **              and return user input as valid integer
 *********************************************************************/
int Menu::againMenu()
{
   Menu menu3;
   menu3.addString("Game Over!");
   menu3.addString("Would you like to play agian?");
   menu3.addString("1. Play");
   menu3.addString("2. Quit");

   return menu3.userInput(1, 2);
}

//difficulty of the game
int Menu::gameLevel()
{
   Menu menuG;
   menuG.addString("Please pick the difficulty of the game");
   menuG.addString("1. Easy");
   menuG.addString("2. Medium");
   menuG.addString("3. Hard");

   return menuG.userInput(1, 3);
}
