/*******************************************************************************
 **  Ellen Yang
 **  Stack.cpp
 **  11/14/18.
 **  Stack.hpp is the Stack class function specification file, which add the
 **  loser to the top of stack and print the loser in reverse order.
 *****************************************************************************/

#ifndef STACK_hpp
#define STACK_hpp
#include "Character.hpp"

class Stack
{
   private:
      struct StackNode
      {
         Character *player;
         StackNode *next;
         StackNode *prev;

      };
   
      StackNode *top;

   public:
      Stack();
      ~Stack();

      void addTop(Character*);
      void printStack(); //print from top to bottom

      void debugNode(string s);
   
};

#endif
