/*************************************************************************
**               Ellen Yang
**               Nov 6, 2018
** This is main.cpp for Lab7, where user can choose different functions to
** create, delete and print QueueNode from Queue using circlular link
************************************************************************/
#include "Queue.hpp"
#include <iostream>
#include "Menu.hpp"
#include "isDigit.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
   cout <<"Welcome to my queue!" <<endl;
   
   int choice; //to hold the user's choice

   Queue queue;

   Menu menu, menu1;

   menu.addString("Please choose from the following options:");
   menu.addString("1. Enter a value to be added to the back of queue");
   menu.addString("2. Display first node (front) value");
   menu.addString("3. Remove first node (front) value");
   menu.addString("4. display the queue contents");
   menu.addString("5. Exit");

   choice = menu.userInput(1, 5);

   while (choice != 5)
   {
      switch (choice)
      {
         case 1:
         {
            int val; //to hold the user input
            cout <<"Please enter a positive integer:"<<endl;
            val = menu1.userInput();

            //added to the back of queue
            queue.addBack(val);

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 5);
         }
            break;
         case 2:
         {
            //check to see if the list is emp
            if (queue.isEmpty())
            {
               cout <<"This list is empty."<<endl;
               cout <<endl;
            }
            else
            {
               // Display first node (front) value
               cout <<"The first node value is: ";
               cout <<queue.getFront()<<endl;
            }
            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 5);
         }
            break;
         case 3:
         {
            //Remove first node (front) value
            queue.removeFront();

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 5);

         }
            break;
         case 4:
         {
            //display the queue contents
            queue.printQueue();

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 5);

         }
            break;
      }
   }

   cout <<"Thanks for visiting! You choose to exit the program."<<endl;

   return 0;
}



