/*********************************************************************
 ** Program name: Project1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 26, 2018
 ** Description:  the main file that contains main function that simulates
 **               Langton's ant.
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include "Menu.hpp"
#include "Ant.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::setw;

int main()
{
   int numRow = 0; //number of rows for board
   int numColumn = 0; //number of column for board
   int numStep = 0; //number of steps for similation
   int startRow = 0; //staring row of ant
   int startColumn = 0; //starting column of ant

   Menu menu; //declar a Menu object
   Ant ant; //declar an Ant object

   int userChoice; //ask if user wants to play

   userChoice = menu.introMenu(); //ask if user wants to play

   if (userChoice == 1) //if user wants to play
   {
      do
      {
         numRow = menu.rowMenu(); // ask for number of rows for board
         numColumn = menu.columnMenu(); // ask for number of columns
         numStep = menu.stepMenu(); // ask for number of steps

         //dynamically allocate 2D array for board
         char ** antBoard = new char *[numRow]; //number of rows
         for (int i = 0; i < numRow; i++)
         {
            antBoard[i] = new char [numColumn]; //number of column
         }

         //fill the board with spaces, initilized antColor and ant direction
         ant.setBoard(antBoard, numRow, numColumn);

         //ask if user wants to use a random starting location
         int random = menu.randomMenu();

         if (random == 1) //yes, random select random start location
         {
            startRow = menu.randomRow();
            startColumn = menu.randomColumn();
         }
         else //no, ask user for starting row and column
         {
            startRow = menu.rowStart();
            startColumn = menu.columnStart();
         }

         //set the start position of ant
         ant.setAntRow (startRow);
         ant.setAntColumn(startColumn);

         //print board
         ant.printBoard(antBoard, numRow, numColumn);

         for (int i = 0; i < numStep; i++)
         {
            ant.changeDirection(); //change direction of ant
            ant.changeColor(antBoard); //change color of space
            ant.moveAnt(numRow, numColumn); //move ant
            ant.updateAntColor(antBoard); //update the color @ ant location
            ant.printBoard(antBoard, numRow, numColumn); //print board
         }

         //free the dynamically allocated memory
         for (int i = 0; i < numRow; i++)
         {
            delete [] antBoard [i];
         }
         delete [] antBoard;

         userChoice = menu.endMenu(); //at the end of similation

      }while (userChoice == 1); //loop again if user wants to play again
      

      if (userChoice == 2) //if user doesn't want to play again
      {
         cout <<" Thanks for visiting, please come again." <<endl;
      }
   }
   else if (userChoice == 2) //if user wants to quit
   {
      cout <<" Thanks for visiting, please come again." <<endl;
   }

   return 0;
}


