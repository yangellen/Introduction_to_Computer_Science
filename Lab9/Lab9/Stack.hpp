/**********************************************************************
**  Stack.hpp
**  Ellen Yang
**  11/24/18.
**  Stack.hpp is Stack class specification file, which has variable and functions
**  use to create panlindrome with use of stack STL container
***************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
#include <iostream>

class Stack
{
   private:
      std::stack<char> word; //store the char

   public:
   //takes an char as parameter and add it to the top of the stack
   void pushTop(char letter);

   //remove a char from top of stack
   void popTop();

   //print the char in the word
   void printStack(std::stack<char>);

   //return word
   std::stack<char> getWord()
   {return word;}
};



#endif
