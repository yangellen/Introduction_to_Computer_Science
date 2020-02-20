/**********************************************************************
**   Ellen Yang
**   Recursive.hpp
**   Oct 23, 2018
**   This is a declaration file, which list the prototype of three recursive
**   functions.
**********************************************************************/

#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP

#include<string>

using std::string;

//take string as parameter, then print the string in reverse order
void printReverse(string);

// take a pointer to the integer array and integer for the number of element
// in the array as parameter, then return sum of all integers.
void calculateSum (int array[], int size);

//a function recursively calculates the triangular number of an integer N
int triangleNumber(int row);

#endif
