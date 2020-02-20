/************************************************************************
 **  Ellen Yang
 **  Node.cpp
 **  A implantation file which contain private variables and public functions
 **  that is going to work closely with List class.
 *************************************************************************/

#include "Node.hpp"

//constructor takes int val as parameter
Node::Node(int val)
{
   this->val = val;
   this->next = nullptr;
   this->prev = nullptr;
}

// set Val
void Node::setVal(int val)
{
   this->val = val;
}

//get val
int Node::getVal()
{
   return this->val;
}

//set pointer to next Node
void Node::setNext(Node* next)
{
 this->next = next;
}

//get pointer to next Node
Node* Node::getNext()
{
   return this->next;
}

// set pointer to prev Node
void Node::setPrev(Node* prev)
{
   this->prev = prev;
}

// get pointer to prev Node
Node* Node::getPrev()
{
   return this->prev; 
}
