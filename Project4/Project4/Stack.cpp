/*******************************************************************************
**  Ellen Yang
**  Stack.cpp
**  11/14/18.
**  Stack.cpp is the Stack class function implementation file, which add the
**  loser to the top of stack and print the loser in reverse order.
*****************************************************************************/

#include "Stack.hpp"
#include "iostream"

using std::cout;
using std::endl;

/***************************************************************************
 ** Stack::Stack()
 ** default constactor which create memory for StackNode and set top to nullptr
****************************************************************************/
Stack::Stack()
{
   top = new StackNode;
   top = nullptr;
}

/***************************************************************************
 ** Stack::~Stack()
 ** destactor which delete player and StackNode at the end.
 ****************************************************************************/
Stack::~Stack()
{
   StackNode *temp = top; //start at the top of stack

   while (top != nullptr)
   {
      temp = top->next;

      if (top ->player != nullptr)
      {
         delete top->player;
      }
      delete top;

      top = temp;
   }
   
   temp = nullptr;

   //debugNode("AFTER destructor");

}

/******************************************************************************
 ** Void Stack::addTop(Character *character)
 ** This function add loser character to the top of stack
 *************************************************************************/
void Stack::addTop(Character *character)
{
   //debugNode("BEFORE addTop");

   StackNode *temp = new StackNode();
   temp ->player = character;

   if (top == nullptr)
   {
      top = temp; // top is temp
   }
   else //list is not empty
   {
      top->prev = temp; //add temp to the current top
      temp->next = top;
      top = temp;
   }

  // debugNode("AFTER addTop");
}

/*****************************************************************************
** void Stack::printStack()
** This function print the loser from top to bottom
*****************************************************************************/
void Stack::printStack()
{
   StackNode *temp = top;

   if (top == nullptr)
   {
      cout <<"There are no losers !"<<endl;
   }

   else
   {
      cout <<endl; 
      cout <<"Here are the losers: "<<endl;

      while (temp != nullptr)
      {
         cout <<temp->player->getPlayerType()<<" ";
         cout <<temp->player->getName() <<endl;
         temp = temp->next; 
      }
      cout <<endl;

   }
}

//
void Stack::debugNode(string s)
{
   if (top == nullptr)
   {
      std::cout << "DEBUG: " << s << " TOP is null\n";
   }
   else
   {
      std::cout << "DEBUG: " << s << ": TOP " << top->player->getPlayerType();
      if (top->next == nullptr)
      {
         std::cout << " and NEXT is null";
      }
      else
      {
         std::cout << " and NEXT " << top->next->player->getPlayerType();
      }
      std::cout << "\n";
   }

}

