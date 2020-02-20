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
   head = nullptr;
}

/***************************************************************************
 **      Queue::~Queue()
 ** destructor deallocates the memory used by the Queue.
 ****************************************************************************/
Queue::~Queue()
{
   QueueNode *nodePtr = head; //start at the head of Queue

   while (nodePtr != nullptr)
   {
      //garbage keeps track of node to be deleted
      QueueNode *garbage = nodePtr;

      //move on to the next node
      nodePtr = nodePtr->next;

      //delete garbage node
      delete garbage;
   }
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
 **   void Queue::addBack (int val)
 ** takes a user-inputted integer and add to the back of list
 ****************************************************************************/
void Queue::addBack(int val)
{
   QueueNode *temp = new QueueNode(); //allocate memorry
   temp->val = val;  //assign value

   if (isEmpty()) //empty list
   {
      head = temp; // head is temp
      head->prev = head;  //tail is temp
   }

   else //list is not empty
   {
      head->prev->next = temp; //old tail's next is temp
      head-> prev = head->prev->next;//new tail (temp) is old tail's next (temp)
   }
}

/***************************************************************************
 **      int Queue::getFront()
 ** returns the value of the node at the front of the queue
 ****************************************************************************/
int Queue::getFront()
{
   return head->val;
}

/****************************************************************************
 **      void Queue::removeFront()
 ** removed the front QueueNode of the queue and free the memory
 ***************************************************************************/
void Queue::removeFront()
{
   QueueNode *temp = head; //start at head of list

   if (isEmpty())
   {
      cout <<"This list is empty."<<endl;
   }
   else
   {
      temp = head;   //temp point at head...what we want to delete
      head = head->next; // new head is old head's next
      delete temp;
   }

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
      cout <<"This list is empty."<<endl;
   }

   while (temp != nullptr)
   {
      cout << temp-> val<<" ";
      temp = temp-> next; //move to next value
   }
   cout <<endl;
}

