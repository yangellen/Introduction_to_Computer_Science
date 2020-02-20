/*******************************************************************************
* Program name: main.cpp
* Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
* Date: November 4th, 2018
* Description: This is the implementation file for Grid class which contains 
* functions to create the grid, to populate the grid, and to print the grid. 
*******************************************************************************/
#include <iostream>
#include <string>
#include "isDigit.hpp"
#include "Menu.hpp"
#include "Grid.hpp"
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl; 

int main()
{
   unsigned seed; //random generator seed
   seed = time(0);
   srand(seed);

   Menu menu, menu1, menu2, menu3, menu4, menu5, menu6, menu7;
   int userChoice;
   menu.addString("Welcome to Predator-Prey Game!");
   menu.addString("Please select:");
   menu.addString("1. Play");
   menu.addString("2. Quit");
   userChoice = menu.userInput(1, 2);

   if (userChoice == 1) //play
   {
      int customGrid;  //make costome grid?
      menu1.addString("Please choose:");
      menu1.addString("1. design own grid size, number of ants and doddlebugs");
      menu1.addString("2. use premade one");
      customGrid = menu1.userInput(1, 2);

     int numStep;

     if (customGrid == 1)
     {
         //ask for more
         int numRow;
         int numCol;
         int numAnt;
         int numDoodlebug;

         menu2.addString("Please enter number of steps:");
         numStep = menu2.userInput();

         menu3.addString("Please enter number of row:");
         numRow = menu3.userInput();

         menu4.addString("Please enter number of columns:");
         numCol = menu4.userInput();

         menu5.addString("Please enter number of ants:");
         numAnt = menu5.userInput();

         menu6.addString("Please enter number of doodlebugs");
         numDoodlebug = menu6.userInput();

         /*construct grid take parameter that take step, ant, doodlebugs, row,
          col, initialized board, fill with nullptr and randomlly place ant,
          doddlebug */
         Grid grid1(numStep, numAnt, numDoodlebug, numRow, numCol);

         std::cout << "numStep " << numStep << "\n";
         for( int i = 0; i < numStep; i++)
         {
            std:cout << "Play #" << (i+1) << "\n";
            grid1.play();
         }

         int again; //if user wants to play again at the end.

         do
         {
           //end of simulation, run again?
           menu7.addString("You reach the time step enter.");
           menu7.addString("Do you want to run the simulation again?");
           menu7.addString("1. yes");
           menu7.addString("2. no");
           again = menu7.userInput(1,2);

           if (again == 1)
           {
              numStep = menu2.userInput();
              for( int i = 0; i < numStep; i++)
              {
                 std::cout << "Play " << i << "\n";
                 grid1.play();
              }
           }

           else
           {
              cout <<"Thanks for visiting."<<endl;
           }

         } while (again == 1);

      }

      else
      {
         menu2.addString("Please enter number of steps");
         numStep = menu2.userInput();

         /*construct grid take parameter step,initialized board, fill with
          nullptr and randomlly place ant,doddlebug */
         Grid grid1(numStep);

         for( int i = 0; i < numStep; i++)
         {
            std::cout << "Play " << i << "\n";
            grid1.play();
         }
         
         int again; //if user wants to play again at the end.

         do
         {
            //end of simulation, run again?
            menu7.addString("You reach the time step enter.");
            menu7.addString("Do you want to run the simulation again?");
            menu7.addString("1. yes");
            menu7.addString("2. no");
            again = menu7.userInput(1,2);

            if (again == 1)
            {
               numStep = menu2.userInput();
               for( int i = 0; i < numStep; i++)
               {
                  std::cout << "Play " << i << "\n";
                  grid1.play();
               }
            }

            else
            {
               cout <<"Thanks for visiting."<<endl;
            }

         } while (again == 1);
     }

   }

   cout <<"Thanks for visiting."<<endl;



   return 0;

}
