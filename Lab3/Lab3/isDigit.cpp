/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  A function that takes a string to check if it's all digits
 **               and retrun bool
 *********************************************************************/
#include "isDigit.hpp"
#include <string>

using std::string;
using std::isdigit;

/*********************************************************************
 **              isDigit(string)
 ** Description: This function takes a string to check if it contains all
 **              digits and return a boolean.
 *********************************************************************/
bool isDigit(string choice)
{
   int count = 0;
   bool integer = true;
   for (int i = 0; i < choice.length(); i++) //for each char in string
   {
      if (isdigit(choice[i]))
      {
         count += 1;
      }
      if (count == choice.length())
      {
         integer = true; //all digits
      }
      else if (count != choice.length())  //not all digits
      {
         integer = false;
      }
   }
   return integer;
}
