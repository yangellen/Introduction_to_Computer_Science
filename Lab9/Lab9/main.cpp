/*       main.cpp
**       Lab9
**       Ellen Yang
**       11/20/18.
**       main.cpp file for Lab 9. This program allows user to test the buffer
**       and create a palindrome.
**********************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Queue.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Stack.hpp"

using std::cout;
using std::endl;


int main()
{
   unsigned seed = time(0);
   srand(seed);

   Menu menu;
   Queue queue;
   Stack stack;
   int choice;

   choice = menu.introMenu();

   while (choice != 3)
   {
      switch (choice)
      {
         case 1:
         {
            int numRound; //number of rounds will be simulated
            int addEndChance; //the percentage chance to add random number at the end of buffer
            int removeFrontChance; //the percentage change to remove random number the front of buffer

            int N; //ramdom number to be add or remove
            int appNumber; //random number from 1-100
            int removeNumber; //random number from 1-100

            double averageLength = 0.0; //

            numRound = menu.roundMenu();
            addEndChance = menu.addEndChance();
            removeFrontChance = menu.removeFrontChance();
            cout <<endl;

            //buffer simulation start
            for (int i = 0; i <numRound; i++)
            {
               cout <<"Round: "<<i + 1<<endl;

               //generate a random number from 1-1000
               N = rand() % 1000 + 1;
               cout <<"N: "<<N<<endl;

               appNumber = rand() % 100 + 1;
               cout <<"Random push number: " <<appNumber<<";";
               cout <<"Push chance: "<<addEndChance<<endl;

               //add N to the end if appNumber <= addEndChance
               if (appNumber <= addEndChance)
               {
                  queue.pushBack(N);
                  cout <<"push "<<N<<endl;

               }
               else
               {
                  cout<<"no push"<<endl;
               }

               removeNumber = rand() % 100 + 1;
               cout <<"Random pop numbber: "<<removeNumber<<";";
               cout <<"Pop chance: "<<removeFrontChance<<endl;

               //remove a number from the front of queue
               if (removeNumber <= removeFrontChance)
               {
                  queue.popFront();
                  cout<<"Pop if queue not empty"<<endl;
               }
               else
               {
                  cout <<"No pop"<<endl;
               }

               //Print out the values in the buffter and length of the buffer
               queue.printQueue(queue.getQueue());
               cout <<"The length of buffer: "<<queue.queueSize()<<endl;

               //print the avaerage length of buffer

               averageLength = queue.averageLength(averageLength, queue.queueSize(), i + 1);

               cout<<"The average length: "<<std::fixed<<std::setprecision(2)<<averageLength<<endl;

               cout <<endl;
            }

            for (int i = 0; i < numRound; i++) //empty queue, so it can start over
            {
               queue.popFront();
            }

            choice = menu.introMenu();

         }
            break;

         case 2:
         {
            //palindrome
            string word;
            word = menu.stackMenu();

            cout <<"palindrome: ";
            for (int i = 0; i < word.size(); i++)
            {
               stack.pushTop(word.at(i));
               cout <<word.at(i);
            }

            stack.printStack(stack.getWord());
            cout <<endl;

            for (int i = 0; i < word.size(); i++) //empty stack, so it can start over
            {
               stack.popTop();
            }
            choice = menu.introMenu();
         }
            break;
      }
   }

   cout <<"Good bye!"<<endl;

   return 0;
}
