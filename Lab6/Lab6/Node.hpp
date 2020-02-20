/************************************************************************
 **  Ellen Yang
 **  Node.hpp
 **  A specification file which contain private variables and public functions
 **  that is going to work closely with List class.
 *************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node
{
   private:
      Node *next; // a pointer to the next Node object
      Node *prev; //a pointer to the previous Node object
      int val; //integer value the specific Node contains

   public:
      Node(int val); //constructor takes int val as parameter

      void setVal(int);// set Val
      int getVal(); //get val

      void setNext(Node *); //set pointer to next Node
      Node* getNext(); //get pointer to next Node

      void setPrev(Node *);// set pointer to prev Node
      Node* getPrev();// get pointer to prev Node*/

      friend class List;

};

#endif
