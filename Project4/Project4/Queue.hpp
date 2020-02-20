/*************************************************************************
 **               Ellen Yang
 **               Nov 6, 2018
 ** Queue.hpp is the Queue class specification file, which contain QueueNode
 ** structure, head pointer to the first QueueNode and functions that can be
 ** use to create Queue. 
 ************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Character.hpp"

class Queue
{
   private:
      struct QueueNode
      {
         QueueNode *next; // a pointer to the next QueueNode object
         Character *player; //player pointer the specific Node contains
      };
   
      QueueNode *head; //a pointer to the first QueueNode
      QueueNode *tail;

   public:
      Queue();
      ~Queue(); //destructor

      bool isEmpty(); //checks if the queue is empty

      //takes a character and add to the back of list
      void addBack(Character *player);

      //returns the value of the node at the front of the queue
      Character* getFront();

      //removed the front QueueNode of the queue and free the memory
      void removeFront();

      //Pirnt the values of each QueueNode in the queue
      void printQueue();

      void debugNode(string s);
};

#endif
