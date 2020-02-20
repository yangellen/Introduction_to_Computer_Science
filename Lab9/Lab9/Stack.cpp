/**********************************************************************
 **  Stack.cpp
 **  Ellen Yang
 **  11/24/18.
 **  Stack.hpp is Stack class implementation file, which has variable and functions
 **  use to create panlindrome with use of stack STL container
 ***************************************************************************/

#include "Stack.hpp"
#include <iostream>
using std::endl;
using std::cout;

/*******************************************************************************
**  void Stack::pushTop(char letter)
**  takes an char as parameter and add it to the top of the stack
******************************************************************************/
void Stack::pushTop(char letter)
{
   word.push(letter);
}

/*******************************************************************************
 ** void Stack::printStack(std::stack<char> q)
 ** take the stack container with characters as parameter and print the char
 ** in the container in reverse order
 ******************************************************************************/
void Stack::printStack(std::stack<char> q)
{
   if (q.empty())
   {
      cout <<"The stack is empty."<<endl;
   }

   while (!q.empty())
   {
      cout <<q.top();
      q.pop();
   }
   cout <<endl;

}

 /*******************************************************************************
 **  void Stack::popTop()
 **  remove a char from top of stack
  ******************************************************************************/
void Stack::popTop()
{
   if (!word.empty()) //if word is not empty
   {
      word.pop(); //remove front
   }
   else
   {
      std::cout<<"The stack is empty."<<std::endl;
   }
}
