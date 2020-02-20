/*********************************************************************
 ** Program name: Lab1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 21, 2018
 ** Description:  the main file that contains main function to run the
 **               maxtrix calculator program.
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::setw;

//function prototype
int getMatrix();

int main()
{
   int matrixSize; // holds the matrix size input by user

   matrixSize = getMatrix(); //get the matrix size from user with getMatrix()

   // dynamically allocate 2D array
   int ** matrixArray = new int *[matrixSize];  //number of row
   for (int i = 0; i < matrixSize; i++)
   {
      matrixArray[i] = new int[matrixSize]; //number of column
   }

   //fill the matrix with readMatrix()
  readMaxtrix(matrixArray, matrixSize);

   //find the determimint of matrix using derterminant()
   int matrixDeterminant; // hold the determinant

   matrixDeterminant = determinant (matrixArray, matrixSize);

   //display matrix to the user
   for (int i = 0; i < matrixSize; i++)
   {
      for (int j = 0; j < matrixSize; j++)
      {
         cout<< setw(5) << matrixArray[i][j];
      }
      cout << endl;
   }

   //display determinant
   cout << "matrix determinant: " <<matrixDeterminant <<endl;

   //deallocating array when it's done
   for (int i = 0; i < matrixSize; i++)
   {
      delete [] matrixArray[i];
   }
   delete [] matrixArray;

   return 0;
}

/*********************************************************************
 **              int getMatrix()
 ** Description: a funtion returns the matrix size input by the user
 *********************************************************************/
int getMatrix()
{
   int userInput;

   //ask user to enter matrix size
   cout << "Please choose the size of the matrix:" << endl;
   cout << "Enter 2 for 2x2, enter 3 for 3x3" <<endl;
   cin >> userInput;

   //check to see if it is a valid number or data type
   while ((userInput != 2 && userInput != 3) || cin.fail())
   {
      cin.clear();
      cin.ignore();
      cout << "ERROR, please enter 2 or 3 for matrix size" <<endl;
      cin >> userInput;
   }

   return userInput;
}
