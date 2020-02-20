/************************************************************************
 **  Ellen Yang
 **  List.cpp
 **  A implantation file thant contain private variables and public functions
 **  that is used to build a boubly linked list
 *************************************************************************/
#include "List.hpp"
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************************
 **       List::List()
 ** default constructor
 ****************************************************************************/
List::List()
{
   head = nullptr;
   tail = nullptr;
}

/***************************************************************************
 **      List::~List()
 ** destructor deallocates the memory used by the list
 ****************************************************************************/
List::~List()
{
   Node *nodePtr = head; //start at the head of list
   while (nodePtr != nullptr)
   {
      //garbage keeps track of node to be deleted
      Node *garbage = nodePtr;

      //move on to the next node
      nodePtr = nodePtr->getNext();

      //delete garbage node
      delete garbage;
   }
}

/***************************************************************************
 **       void List::addToHead(int val)
 ** Take user input and add new node to the head of the list
 ****************************************************************************/
void List::addToHhead(int val)
{
   //allocate memory and assign value
   Node *temp = new Node (val);

   //check to see if list is empty
   if (head == nullptr)
   {
      head = temp; // head is temp
      temp-> prev = nullptr; //set prev to null
      tail = temp;
      temp->next = nullptr; //set next to null
   }

   else
   {
      head->prev = temp; //connect current head to temp
      temp->next = head; //set next to current head
      head = temp; //temp becomes head
      temp -> prev = nullptr;
   }
}

/***************************************************************************
 **            void Node::addToTail(int val)
 ** Add new node to the tail of the list
 ****************************************************************************/
void List::addToTail(int val)
{
   Node *temp = new Node(val); //allocate memorry and assign value

   if (head == nullptr) //empty list
   {
      head = temp; // head is temp
      temp->prev = nullptr; //set prev to null
      tail = temp;
      temp->next = nullptr; //set next to null

   }

   else //list is not empty
   {
      temp->next = nullptr; //set next to null
      temp->prev = tail; // new prev is tail
      tail->next = temp; //current tail to temp
      tail = temp; // temp become tail
   }
}

/***************************************************************************
 **         void List::printList()
 ** Print the list from head to tail
 ****************************************************************************/
void List::printList()
{
   Node *temp = head; //start at head of list

   if (temp == nullptr)
   {
      cout <<"This list is empty."<<endl;
   }

   while (temp != nullptr)
   {
      cout << temp-> getVal()<<" ";
      temp = temp->getNext(); //move to next value
   }

   cout <<endl; 
}

/***************************************************************************
 **      void List::printReverse()
 ** Print the list from tail to head
 ****************************************************************************/
void List::printReverse()
{
   Node *temp = tail; //start at tail of list

   if (temp == nullptr)
   {
      cout <<"This list is empty."<<endl;
   }

   while (temp != nullptr)
   {
      cout << temp-> getVal() <<" ";
      temp = temp-> getPrev(); //move to prev value
   }

   cout <<endl;

}

/***************************************************************************
 **         void List::deleteFirst()
 ** delete the value in first node
 ****************************************************************************/
void List::deleteFirst()
{
   if (head->next == nullptr || tail->prev == nullptr)
   {
      delete head;
      head = nullptr;
      tail = nullptr;
   }
   else
   {
      head = head->next; // set head to next node
      delete head->prev; //delete the old head
      head->prev = nullptr; // set prev to null
   }
}

/***************************************************************************
 **         void List::deleteLast()
 ** delete the value in last node
 ****************************************************************************/
void List::deleteLast()
{
   if (head->next == nullptr || tail->prev == nullptr) //one node only
   {
      delete head;
      head = nullptr;
      tail = nullptr;
   }
   else
   {
      tail = tail->prev; //set tail to the one before
      delete tail->next; //delete the old tail
      tail-> next = nullptr; // set next to null
   }
}

/***************************************************************************
 **     bool List::listEmpty()
 ** check to see if the list is empty and return true if it is empty.
 ****************************************************************************/
bool List::listEmpty()
{
   bool empty = true;

   if (head == nullptr) //empty list
   {
      cout <<"The list is empty."<<endl;
      empty = true;
   }
   else empty = false;
   
   return empty;
}

//
void List::printHead()
{
   cout <<"The first value in the list is: ";

   Node *temp = head; //start at head of list
   cout << temp-> getVal()<<endl;
}

//
void List::printTail()
{
   cout <<"The last value in the list is: ";

   Node *temp = tail; //start at tail of list
   cout << temp-> getVal()<<endl;
}
