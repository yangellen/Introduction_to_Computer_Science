/*************************************************************************
 **               Ellen Yang
 **               Nov 6, 2018
 ** Queue.cpp is the Queue class function implementation file, which contain
 ** QueueNode structure, head pointer to the first QueueNode and functions
 ** that can be use to create Queue.
 ************************************************************************/

#include "Queue.hpp"
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************************
 **       Queue::Queue()
 ** default constructor that initilized head to nullptr.
 ****************************************************************************/
Queue::Queue()
{
   head = new QueueNode;
   head = nullptr;
}

/***************************************************************************
 **      Queue::~Queue()
 ** destructor deallocates the memory used by the Queue.
 ****************************************************************************/
Queue::~Queue()
{
   QueueNode *temp = head; //start at the head of Queue

   while (head != nullptr)
   {
      temp = head->next;
      if (head ->player != nullptr)
      {
         delete head->player;
      }
      delete head;
      head = temp;
   }

   tail = nullptr;
   temp = nullptr;
   
   //debugNode("AFTER destructor");
}

/******************************************************************************
**        bool Queue::isEmpty()
** checks if the queue is empty, return true if it's empty; otherwise,
** return false
****************************************************************************/
bool Queue::isEmpty()
{
   if (head == nullptr)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/*****************************************************************************
 **   void Queue::addBack (Character* player)
 ** takes a user-inputted integer and add to the back of list
 ****************************************************************************/
void Queue::addBack(Character *fighter)
{
   QueueNode *temp = new QueueNode(); //allocate memorry
   temp->player = fighter;  //assign player

   // debugNode("BEORE addBack");

   if (head == nullptr) //empty queue
   {
      // head is the same as tail when adding the first node
      head = temp;
      tail = head;
   }
   else
   {
      tail->next = temp; // add new node
      tail = temp; // set new tail
   }

  // debugNode("AFTER addBack");
}

/***************************************************************************
 **      int Queue::getFront()
 ** returns the value of the node at the front of the queue
 ****************************************************************************/
Character* Queue::getFront()
{
   return head->player;

}

/****************************************************************************
 **      void Queue::removeFront()
 ** removed the front QueueNode of the queue and free the memory
 ***************************************************************************/
void Queue::removeFront()
{
   QueueNode *temp = head; //start at head of list

   // debugNode("BEFORE removeFront");

   if (isEmpty())
   {
      cout <<"No member survive during the battle."<<endl;
   }
   else
   {
      temp = head; // head to delete
      head = head->next; // set new head
      delete temp; // delete old head
   }
  // debugNode("AFTER removeFront");

}

/**************************************************************************
 **    void Queue::printQueue()
 ** Pirnt the values of each QueueNode in the queue
 ***************************************************************************/
void Queue::printQueue()
{
   QueueNode *temp = head; //start at head of list

   if (isEmpty())
   {
      cout <<"No member survive during the battle."<<endl;
   }

   while (temp != nullptr)
   {
      cout << temp-> player<<" ";
      temp = temp-> next; //move to next value
   }
   cout <<endl;
}

void Queue::debugNode(string s)
{
   if (head == nullptr)
   {
      std::cout << "DEBUG: " << s << " HEAD is null\n";
   }
   else
   {
      std::cout << "DEBUG: " << s << ": HEAD " << head->player->getPlayerType();
      if (head->next == nullptr)
      {
         std::cout << " and NEXT is null";
      }
      else
      {
         std::cout << " and NEXT " << head->next->player->getPlayerType();
      }
      if (tail == nullptr)
      {
         std::cout << " and TAIL is null";
      }
      else
      {
         std::cout << " and TAIL " << tail->player->getPlayerType();
      }
      std::cout << "\n";
   }
   if (tail == nullptr)
   {
      std::cout << "DEBUG: TAIL is null\n";
   }
}

