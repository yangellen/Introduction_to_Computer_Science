/**********************************************************************
 **   Ellen Yang
 **   Recursive.cpp
 **   Oct 23, 2018
 **   This is a implementation file, which define what three recursive
 **   functions do.
 **********************************************************************/

#include "Recursive.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
**            void printReverse(string string)
** take string as parameter, then print the string in reverse order
********************************************************************/
void printReverse(string string)
{
   int numChar = string.length(); //get the length of string

   if (numChar == 1)
   {
      cout <<string<<"\n";
   }

   else
   {
      cout <<string.back(); //get the last char of the string
      string.pop_back(); //erases the last character of the string
      printReverse(string);
   }
}

/*********************************************************************
**                   int sum (int* [], int number);
**    take a pointer to the integer array and integer for the number of element
**    in the array as parameter, then return sum of all integers.
 ** ********************************************************************/
void calculateSum (int array[], int number)
{
   if (number == 1) //only one integer, base case
   {
      cout<< "Sum: "<< array[0] <<endl;
   }
   else
   {
      array[number - 2] += array[number - 1];//add last int to the one before
      array[number - 1] = 0; //set the last int to zero
      calculateSum(array, number - 1); //call the function again
   }
}

/*********************************************************************
 **                int triangleNumber(int number)
 ** A function recursively calculates the triangular number of an integer row
 ** and return the calculation as integer.
 ** ********************************************************************/
int triangleNumber(int row)
{
   int sum = 0;

   if ( row != 0) //base case
   {
      sum = row + triangleNumber(row - 1);
   }
   
   return sum; 
}
