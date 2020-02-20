 /*********************************************************************
 ** Program name: Lab1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 24, 2018
 ** Description:  readMatrix.cpp is the void readMaxtrix() implantation file.
 **               The readMaxtrix() function has two paramters, a pointer
 **               to a 2D array and an integer as the size of the matrix.
 **               The function prompt the user for all the numbers within
 **               the matrix *******************************************/

#include "readMatrix.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void readMaxtrix (int **inputArray, int arraySize)
{
   int userInput = 0; //hold the integer enter by user
   int numberInteger; //number of integers needs to be enter

   numberInteger = arraySize * arraySize;

   //prompt the user to enter the integers

   cout <<"Please enter " <<numberInteger << " integers" <<endl;

   for (int i = 0; i < arraySize; i++) //fill the matrix
   {
      for (int j = 0; j < arraySize; j++)
      {
         cin >> userInput; //integer enter by user

         while (cin.fail())//check to see if it is a valid data type
         {
            cin.clear();
            cin.ignore();
            cout << "ERROR, please enter an integer" <<endl;
            cin >> userInput;
         }

         inputArray[i][j] = userInput; //fill the matrix if correct
      }
   }
}


