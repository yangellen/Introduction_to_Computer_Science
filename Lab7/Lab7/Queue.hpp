/*************************************************************************
 **               Ellen Yang
 **               Nov 6, 2018
 ** Queue.hpp is the Queue class specification file, which contain QueueNode
 ** structure, head pointer to the first QueueNode and functions that can be
 ** use to create Queue. 
 ************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
   private:
      struct QueueNode
      {
         QueueNode *next; // a pointer to the next QueueNode object
         QueueNode *prev; //a pointer to the previous QueueNode object
         int val; //integer value the specific Node contains
      };

      QueueNode *head; //a pointer to the first QueueNode

   public:
      Queue();
      ~Queue(); //destructor

      bool isEmpty(); //checks if the queue is empty

      //takes a user-inputted integer and ad to the back of list
      void addBack(int val);

      //returns the value of the node at the front of the queue
      int getFront();

      //removed the front QueueNode of the queue and free the memory
      void removeFront();

      //Pirnt the values of each QueueNode in the queue
      void printQueue();
      
};

#endif
