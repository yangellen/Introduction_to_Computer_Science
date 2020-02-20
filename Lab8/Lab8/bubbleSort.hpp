/*********************************************************************
** Ellen Yang
** bubbleSort.hpp
** 11/16/18.
** This is the prototye of bubble sort algorithm to sort vector of integers
** in ascending order and output the sorted values to the output files. It also
** print the sorted vaules in each file onto the screen and return the filename
** that stored the sorted numbers.

** The bubble sort algorthm was based on textbook "Starting Out with C++ ."
***********************************************************************/

#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#include<string>
#include <vector>

using std::vector;
using std::string; 

string sortVector(vector<int> &array);


#endif
