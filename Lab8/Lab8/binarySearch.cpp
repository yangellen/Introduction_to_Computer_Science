/***********************************************************************
 **  Ellen Yang
 **  binarySearch.cpp
 **  11/16/18.
 **  A function that takes vector, target and file name as
 **  parameters, use binary search and output if the target is found or not.

 ** The binary search was based on textbook "Starting Out with C++ ."
 *************************************************************************/

#include "binarySearch.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

void binarySearch(vector<int> array, int target, string fileName)
{
   //start sorting
   int first = 0;
   int last = array.size() - 1;
   int middle;
   int position = -1;
   bool found = false;

   while (!found && first <= last)
   {
      middle = (first + last) / 2;
      if (array[middle] == target)
      {
         found = true;
         position = middle;

         cout <<endl;
         
      }
      else if (array[middle] > target)
      {
         last = middle - 1;
      }
      else
      {
         first = middle + 1;
      }

   }

   if (position == -1)
   {
      cout <<fileName<<": target value not found"<<endl;
      cout<<endl;
   }
   else
   {
      cout <<fileName<<": target value found"<<endl;
      cout <<endl;
   }

}
