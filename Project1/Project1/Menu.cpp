/*********************************************************************
 ** Program name: Project1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 27, 2018
 ** Description:  the Menu.cpp that contains menu class implementation file,
 **               which prints menu options to the screen for the user,
 **               verify the user input and return the value back to the
 **               program.
 *********************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using std::cout; 
using std::endl;
using std::cin;
using std::string;
using std::isdigit;

/*********************************************************************
 **               Menu::introMenu
 ** Description: This function displays the introduction and ask if user wants
 **              to play Langton's Ant simulation and inputs, validates, and
 **              return the user's choice.
 *********************************************************************/
int Menu::introMenu()
{
   cout << "Welcome to Langton's Ant simulation!" <<endl;
   cout << "You can use a a random staring location for ant." <<endl;
   cout << "Please select" <<endl;
   cout << " 1. Start Langton's ant simulation or " <<endl;
   cout << " 2. Quit " <<endl;

   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer ||
          choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
   {
      cout << "Please enter 1 to play or 2 to quit" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer once the string contains either 1 or 2
   int answer = stoi(choice);
   introChoice = answer;

   return introChoice;
}
/*********************************************************************
 **               Menu::randomMenu
 ** Description: This function displays the random menu and ask if user wants
 **              to use a random starting location, validates, and
 **              return the user's choice.
 *********************************************************************/
int Menu::randomMenu()
{
   cout << "Would you like to use a random starting location" <<endl;
   cout << "Please select" <<endl;
   cout << " 1. Yes, I would like to use a random starting location " <<endl;
   cout << " 2. NO, I would like to pick my own starting location" <<endl;

   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer ||
          choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
   {
      cout << "Please enter 1 to play or 2 to quit" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }
   //convert the string to integer once the string contains either 1 or 2
   int answer = stoi(choice);
   randomChoice = answer;

   return randomChoice;
}
/*********************************************************************
 **               Menu::endMenu
 ** Description: This function displays the end menu and ask if user wants
 **              to play Langton's Ant simulation again,inputs, validates, and
 **              return the user's choice.
 *********************************************************************/
int Menu::endMenu()
{
   cout << "Thanks for playing Langton's Ant simulation!" <<endl;
   cout << "Please select" <<endl;
   cout << " 1. Play Langton's ant simulation again or " <<endl;
   cout << " 2. Quit " <<endl;

   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer ||
          choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
   {
      cout << "Please enter 1 to play or 2 to quit" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer once the string contains either 1 or 2
   int answer = stoi(choice);
   endChoice = answer;

   return endChoice;
}

/*********************************************************************
 **               Menu::rowMenu
 ** Description: This function ask user number of rows for the board and
 **              validates and return number of row as integer
 *********************************************************************/
int Menu::rowMenu()
{
   const int MAX = 500;
   const int MIN = 2;

   cout << "Please enter the number of rows for the board:" <<endl;
   cout << "minimum " << MIN << " and maximum "<<MAX <<endl;
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

   while (answer < MIN || answer > MAX)
   {
      cout << "The number of row needs to be at least " <<MIN <<endl;
      cout << "and less or qual to "<<MAX <<endl;
      cout << "Please enter the number of rows for board." <<endl;
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

   numberRow = answer;

   return numberRow;
}
/*********************************************************************
 **               Menu::columnMenu
 ** Description: This function ask user number of columns for the board and
 **              validates and return number of column as integer
 *********************************************************************/
int Menu::columnMenu()
{
   const int MAX = 500;
   const int MIN = 2;

   cout << "Please enter the number of column for the board:" <<endl;
   cout << "minimum " << MIN << " and maximum "<<MAX <<endl;
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

   while (answer < MIN || answer> MAX)
   {
      cout << "The number of column needs to be at least " <<MIN <<endl;
      cout << "and less or qual to "<<MAX <<endl;
      cout << "Please enter the number of column for board." <<endl;
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
   numberColumn = answer;

   return numberColumn;
}
/*********************************************************************
 **               Menu::stepMenu
 ** Description: This function ask user number of steps during simulation and
 **              validates and return number of row as integer
 *********************************************************************/
int Menu::stepMenu()
{
   const int MAX = 500;

   cout << "Please enter the number of steps during simulation:" <<endl;
   cout << "minimum 1 and maximum "<<MAX <<endl;
   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer || choice[0] == '0')
   {
      cout << "Please enter non zero, positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   while (answer > MAX)
   {
      cout << "The number of steps needs to be less or equal to "<<MAX <<endl;
      cout << "Please enter the number of steps during simulation." <<endl;
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
   }   numberStep = answer;

   return numberStep;
}
/*********************************************************************
 **               Menu::rowStart
 ** Description: This function ask user the starting row of the ant, validate
 **              and return starting row of ant as integer
 *********************************************************************/
int Menu::rowStart()
{
   cout << "Please enter the starting row of the ant." <<endl;
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
   //convert the string to integer with positive numbers only
   int answer = stoi(choice);

   while (answer >= numberRow)
   {
      cout << "The starting row of the ant needs to be less than "
            <<numberRow <<endl;
      cout << "Please enter the staring row of the ant." <<endl;
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

   startRow = answer;

   return startRow;

}
/*********************************************************************
 **               Menu::columnStart
 ** Description: This function ask user the starting row of the ant, validate
 **              and return starting row of ant as integer
 *********************************************************************/
int Menu::columnStart()
{
   cout << "Please enter the starting column of the ant." <<endl;
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
   //convert the string to integer with positive numbers only
   int answer = stoi(choice);

   while (answer >= numberColumn)
   {
      cout << "The starting column of the ant needs to be less than "
      <<numberColumn <<endl;
      cout << "Please enter the staring column of the ant." <<endl;
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

   startColumn = answer;

   return startColumn;

}
/*********************************************************************
 **               Menu::randomRow
 ** Description: This function randomlly select the starting row of the ant
 **              and return starting row of ant as integer
 *********************************************************************/
int Menu::randomRow()
{
   unsigned seed; //random generator seed

   int const MIN = 0;
   int const MAX = numberRow - 1;

   //use the time function to get a "seed" value for srand
   seed = time(0);
   srand(seed);

   startRow = (rand() % (MAX - MIN + 1)) + MIN;

   return startRow;
}
/*********************************************************************
 **               Menu::randomColumn
 ** Description: This function randomlly select the starting column of the ant
 **              and return starting column of ant as integer
 *********************************************************************/
int Menu::randomColumn()
{
   unsigned seed; //random generator seed

   int const MIN = 0;
   int const MAX = numberColumn - 1;

   //use the time function to get a "seed" value for srand
   seed = time(0);
   srand(seed);

   startColumn = (rand() % (MAX - MIN + 1)) + MIN;

   return startColumn;
}
/*********************************************************************
 **               Menu::isDigit(string)
 ** Description: This function takes a string to check if it contains all
 **              digits and return a boolean.
 *********************************************************************/
bool Menu::isDigit(string choice)
{
   int count = 0;
   bool integer = true;
   for (int i = 0; i < choice.length(); i++) //for each char in string
   {
      if (isdigit(choice[i]))
      {
         count += 1;
      }
      if (count == choice.length())
      {
         integer = true; //all digits
      }
      else if (count != choice.length())  //not all digits
      {
         integer = false;
      }
   }
   return integer;
}


