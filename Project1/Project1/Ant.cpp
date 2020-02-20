/*********************************************************************
 ** Program name: Project1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 30, 2018
 ** Description:  the Ant.cpp that contains Ant class implementation file,
 **               which contain the direction of the ant, the color of space
 **               where the ant is, the location of the ant and initilized
 **               the board, update the direction of ant, update color of the
 **               ant, and move the ant.
 *********************************************************************/

#include "Ant.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

/*********************************************************************
 **              Ant::setBoard (char**, int, int)
 ** Description: a funtion that take a pointer with 2d array, an integer as
 **              number of row, an integer as number of column and fill the
 **              board with spaces, initialized countStep and ant direction
 *********************************************************************/
void Ant::setBoard(char** antBoard, int numRow, int numColumn)
{
   for (int i = 0; i < numRow; i ++)
   {
      for (int j = 0; j < numColumn; j++)
      {
         antBoard[i][j] = ' ';
      }
   }
   
   antOrientation = RIGHT; //have ant start facing right
   antColor = WHITE; //ant was first place on board with white colar only
}

/*********************************************************************
 **              Ant::printBoard (char**, int, int)
 ** Description: a funtion that take a pointer with 2d array, an integer as
 **              number of row, an integer as number of column and print the
 **              board after each move
 *********************************************************************/
void Ant::printBoard(char ** antBoard, int numRow, int numColumn)
{
   for (int i = 0; i < numRow; i ++)
   {
      for (int j = 0; j < numColumn; j++)
      {
         if (antRow == i && antColumn == j)
         {
            cout << setw(2) <<"*";
         }
         else
         {
            cout << setw(2) <<antBoard[i][j];         }
      }
      cout <<endl;
   }
}

/*********************************************************************
 **              Ant::changeDirection()
 ** Description: a function that update the direction of the ant depends on the
 **              color of space where ant is.
 *********************************************************************/
void Ant::changeDirection()
{
   if (antColor == WHITE)
   {
      switch (antOrientation)
      {
         case UP: antOrientation = RIGHT;
            break;
         case DOWN: antOrientation = LEFT;
            break;
         case RIGHT: antOrientation = DOWN;
            break;
         case LEFT: antOrientation = UP;
            break;
      }
   }
   else if (antColor == BLACK)
   {
      switch (antOrientation)
      {
         case UP: antOrientation = LEFT;
            break;
         case DOWN: antOrientation = RIGHT;
            break;
         case RIGHT: antOrientation = UP;
            break;
         case LEFT: antOrientation = DOWN;
            break;
      }
   }
}

/*********************************************************************
 **              Ant::changeColor(char ** antBoard)
 ** Description: a function that takes pointer of 2D array which represent the
 **             board as parameter and change the color of space where ant is.
 *********************************************************************/
void Ant::changeColor (char ** antBoard)
{
   if (antColor == WHITE)
   {
      antBoard[antRow][antColumn] = '#';
   }
   else if (antColor == BLACK)
   {
      antBoard[antRow][antColumn] = ' ';
   }
}

/*********************************************************************
 **              Ant::moveAnt(int numRow, int numColumn)
 ** Description: a funtion that take the integer of number of row and number of
 **              column of the board as parameter, check to see if the ant is at
 **              the edge of the board. If the ant is at the edge of the board,
 **              turn the ant around, then take one step. If not, take the step
 **              as usual.
 *********************************************************************/
void Ant::moveAnt(int numRow, int numColumn)
{
      switch (antOrientation)
      {
         case UP:
            if (antRow == 0)          //if ant is at the top edge
            {
               antOrientation = DOWN; //turn around tthe ant to face down
               antRow = antRow + 1;   //move down 1
            }
            else
            {
               antRow = antRow - 1;
            }
            break;

         case DOWN:
            if (antRow == (numRow - 1)) //if ant is at the bottom edge
            {
               antOrientation = UP;   //turn arund the ant to face up
               antRow = antRow - 1;   // move up 1
            }
            else
            {
               antRow = antRow + 1;
            }
            break;

         case RIGHT:
            if (antColumn == (numColumn - 1)) //if ant is at right edge
            {
               antOrientation = LEFT; //turn around the ant to face left
               antColumn = antColumn - 1;  //move 1 to left
            }
            else
            {
               antColumn = antColumn + 1;
            }
            break;

         case LEFT:
            if (antColumn == 0) // if ant is at the left edge
            {
               antOrientation = RIGHT; //turn around the ant to face right
               antColumn = antColumn + 1; //move 1 to right
            }
            else
            {
                antColumn = antColumn - 1;

            }
            break;
      }
   }

/*********************************************************************
 **              Ant::updateAntColor(char** antBoard)
 ** Description: a function that takes pointer of 2D array which represent the
 **             board as parameter and update the color of the space where
 **             the ant is at.
 *********************************************************************/
void Ant::updateAntColor(char** antBoard)
{
   if (antBoard[antRow][antColumn] == ' ')
   {
      antColor = WHITE;
   }
   else if (antBoard[antRow][antColumn])
   {
      antColor = BLACK;
   }
}
