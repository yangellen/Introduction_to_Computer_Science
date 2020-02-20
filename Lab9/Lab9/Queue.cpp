/****************************************************************************
**  Ellen Yang
**  11/24/18.
**  Queue.cpp is Queue class implantation file, which has variable and functions
**  use to create a buffer with use of queue STL container
***************************************************************************/

#include "Queue.hpp"
#include <iostream>
using std::cout;
using std::endl;

/****************************************************************************
** void Queue::pushBack(int val)
** takes an int as parameter and add it to the back of the queue
 ***************************************************************************/
void Queue::pushBack(int val)
{
   buffer.push(val);
}

 /****************************************************************************
** void Queue::popFront()
** remove a number from the front of queue
  ***************************************************************************/
void Queue::popFront()
{
   if (!buffer.empty()) //if buffer is not empty
   {
      buffer.pop(); //remove front
   }
}

 /****************************************************************************
**  void Queue::printQueue(std::queue <int> q)
**  takes a queue container with integer as parameter then print the values in
**  the buffer.
  ***************************************************************************/
void Queue::printQueue(std::queue <int> q)
{
   cout <<"Values in the buffer: ";
   if (q.empty())
   {
      cout <<"The buffer is empty."<<endl;
   }
   
   while (!q.empty())
   {
      cout <<q.front()<<" ";
      q.pop();
   }
   cout <<endl; 
}

 /****************************************************************************
  **  double Queue::averageLength(double average, int size, double round)
  **  takes the averge length of previous round, size of buffer in current
  **  round, the number of current round as parameters then calculate and return
  ** the average length in double
  ***************************************************************************/
double Queue::averageLength(double average, int size, double round)
{
   return (average * (round - 1) + size) / round;
}
