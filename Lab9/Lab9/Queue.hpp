/**************************************************************************
 **  Queue.hpp
 **  Ellen Yang
 **  11/24/18.
 **  Queue.hpp is Queue class specification file, which has variable and functions
 **  use to create a buffer with use of queue STL container
 *****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>
using std::queue;

class Queue
{
   private:
      std::queue<int> buffer; //store the integers

   public:
      //takes an int as parameter and add it to the back of the queue
      void pushBack(int val);

      //remove a number from the front of queue
      void popFront();

      //print the values in the buffer and lenght of the buffer
      void printQueue(std::queue<int>);

      queue<int> getQueue()
      {return buffer;}

      int queueSize()
      {return buffer.size();}

      double averageLength(double average, int size, double round);

};

#endif
