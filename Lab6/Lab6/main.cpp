/************************************************************************
**  Ellen Yang
**  main.cpp
**  main fucntion for Lab 6. User can build a list using diffreent functions.
*************************************************************************/
#include <iostream>
#include "List.hpp"
#include "Menu.hpp"
#include "isDigit.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
   int choice; //to hold the user's choice

   List list;

   Menu menu, menu1, menu2;

   menu.addString("Please choose from the following options:");
   menu.addString("1. Add new node to the head");
   menu.addString("2. Add new node to the tail");
   menu.addString("3. Delete the first node in the list");
   menu.addString("4. Delete the last node in the list");
   menu.addString("5. Print the nodes reversely");
   menu.addString("6. Print the value of the Node the head is pointing to");
   menu.addString("7. Print the value of the Node the tail is pointing to");
   menu.addString("8. Exit");

   choice = menu.userInput(1, 8);

   while (choice != 8)
   {
      switch (choice)
      {
         case 1:
         {
            int val; //to hold the user input
            cout <<"Please enter a positive integer:"<<endl;
            val = menu1.userInput();

            //add node to head
            list.addToHhead(val);

            //print from head to tail
            cout <<"Your linked list is: ";
            list.printList();

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);
         }
            break;
         case 2:
         {
            int val; //to hold the user input
            cout <<"Please enter a positive integer:"<<endl;
            val = menu2.userInput();

            //add node to tail
            list.addToTail(val);

            //print from head to tail
            list.printList();

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);
         }
            break;
         case 3:
         {
            //if list is not empty
            if (!list.listEmpty())
            {
               //delete from head
               list.deleteFirst();

               //print from head to tail
               list.printList();
            }

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);

         }
            break;
         case 4:
         {
            //if list is not empty
            if (!list.listEmpty())
            {
               //delete from tail
               list.deleteLast();

               //print from head to tail
               list.printList();
            }
            
            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);

         }
            break;
         case 5:
         {
            list.printReverse();

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);

         }
            break;

         case 6:
         {
            //if list is not empty
            if (!list.listEmpty())
            {
               //print the value of head
               list.printHead();

               //print from head to tail
               list.printList();
            }

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);

         }
            break;

         case 7:
         {
            //if list is not empty
            if (!list.listEmpty())
            {
               //print the value of tail
               list.printTail();

               //print from head to tail
               list.printList();
            }

            //ask if user wants to pick from menu again
            choice = menu.userInput(1, 8);

         }
      }
   }

   cout <<"Thanks for visiting! You choose to exit the program."<<endl;

   return 0;
}

