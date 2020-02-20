/***********************************************************************
 **  Ellen Yang
 **  binarySearch.hpp
 **  11/16/18.
 **  Prototype of a function that takes vector, target and file name as
 **  parameters, use binary search and output if the target is found or not.
 **
 ** The binary search was based on textbook "Starting Out with C++ ."
 *************************************************************************/

#ifndef binarySearch_hpp
#define binarySearch_hpp
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

void binarySearch(vector<int> array, int target, string fileName);

#endif 
