/*********************************************************************
 **                           Ellen Yang
 **  main.cpp
 **  This lab allowes the user to choose 3 options from the menu. Option 1
 **  will print the reverse order of the string user input. Option 2 will print
 **  the sum of all integers in the array. Option 3 will print the trianglular
 **  number.
 ********************************************************************/
#include "Recursive.hpp"
#include "Menu.hpp"
#include "isDigit.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   int userChoice;

   Menu menu;
   menu.addString("Please pick the following options:");
   menu.addString("1. Print the string in reverse.");
   menu.addString("2. Calculate the sum of an array of integers.");
   menu.addString("3. Calculat the triangular number.");
   menu.addString("4. Quit.");
   userChoice = menu.userInput(1, 4);

   while (userChoice != 4)
   {
      if (userChoice == 1)
      {
         string string;
         cout<<"Please enter a string:"<<endl;
         getline(cin,string);
         printReverse(string);
      }

      else if (userChoice == 2)
      {
         Menu menu;
         menu.addString("Please enter number of integers in the array:");
         int size = menu.userInput(1);

         Menu menu2;
         int array[size];
         int integer;

         menu2.addString("Please enter a integer in the array:");

         for (int i = 0; i < size; i++)
         {

            integer = menu2.userInput();

            array[i] = integer;
         }

         calculateSum(array,size);

      }

      else if (userChoice == 3)
      {
         Menu menu;
         menu.addString("Please enter a integer:");
         int number = menu.userInput(1);

         cout << "Triangular number: "<< triangleNumber(number)<<endl;
      }

      userChoice = menu.userInput(1, 4);

   }




   return 0;
}
