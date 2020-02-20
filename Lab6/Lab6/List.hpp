/************************************************************************
 **  Ellen Yang
 **  List.hpp
 **  A specification file thant contain private variables and public functions
 **  that is used to build a boubly linked list
 *************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

class List
{
   private:
      Node *head; //points to the first Node in
      Node *tail; //points to the last Node

   public:
      List(); //constructor
      ~List(); //destructor

      void addToHhead(int val);
      void addToTail(int val);

      void deleteFirst();
      void deleteLast();

      void printReverse();
      void printList();

      void printHead();
      void printTail();

      bool listEmpty();

};

#endif
