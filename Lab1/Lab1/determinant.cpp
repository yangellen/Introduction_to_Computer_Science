/*********************************************************************
 ** Program name:Lab1_Yang_Ellen.zip
 ** Author:      Ellen Yang
 ** Date:        Sep 26, 2018
 ** Description: determinant.cpp is the determinant function implementation file.
 **              The determinant function has two paramters, a pointer
 **              to a 2D array and an integer as the size of the matrix.
 **              The function takes in the 2D array, which contains the value
 **              inside the matrix, and calculate the determinant. The
 **              function will return the determinant.
 *********************************************************************/
#include "determinant.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int determinant(int **matrixArray, int matrixSize)
{
   int determinant = 0; //to hold the derterminant

   if (matrixSize == 2) //for 2x2 matrix
   {
      determinant = (matrixArray[0][0] * matrixArray[1][1]) -
               (matrixArray[0][1] * matrixArray[1][0]);
   }
   else if (matrixSize == 3) //for 3x3 matrix
   {
      int tempA; // hold the number that Multiply a by the determinant of
                 //the 2×2 matrix that is not in a row or column

      tempA = matrixArray[0][0] * ((matrixArray[1][1] * matrixArray[2][2])
              - (matrixArray[1][2] * matrixArray[2][1]));

      int tempB; // hold the number that Multiply b by the determinant of
                 //the 2×2 matrix that is not in b row or column

      tempB = matrixArray[0][1] * ((matrixArray[1][0] * matrixArray[2][2])
                                   - (matrixArray[1][2] * matrixArray[2][0]));

      int tempC; // hold the number that Multiply c by the determinant of
                 //the 2×2 matrix that is not in c row or column

      tempC = matrixArray[0][2] * ((matrixArray[1][0] * matrixArray[2][1])
                                   - (matrixArray[1][1] * matrixArray[2][0]));

      determinant = tempA - tempB + tempC; //find determinant
   }

   return determinant;
}
