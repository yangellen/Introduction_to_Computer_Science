/***********************************************************************
 **  Ellen Yang
 **  simpleSearch.cpp
 **  11/16/18.
 **  A function that take vector, target number and file name as parameters
 **  ,does simple search and output if the target is found or not.
 *************************************************************************/
#include "simpleSearch.hpp"
#include <iostream>

using std::cout;
using std::endl;

void simpleSearch(vector<int> array, int target, string fileName)
{
   int index = 0; //subscript of vector
   int position = -1; //position of search value
   bool found = false; //flag to indicate if the value is found

   while (index < array.size() && !found)
   {
      if (array[index] == target)
      {
         found = true;
         position = index;
         cout <<fileName<<": target value found"<<endl;
         cout <<endl;
      }
      index++;
   }

   if (position == -1)
   {
      cout <<fileName<<": target value not found"<<endl;
      cout<<endl; 
   }

}

