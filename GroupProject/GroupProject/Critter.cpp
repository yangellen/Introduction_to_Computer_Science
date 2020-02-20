/*******************************************************************************
 * Program name: Critter.cpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the implementation file for Critter class which contains 
 * data and functions common to ants and doodlebugs. The Critter class has a 
 * virtual function named move that is defined in the derived classes of Ant and
 * Doodlebug.
 *******************************************************************************/

#include <iostream>
#include "Critter.hpp"

/*******************************************************************************
                               Default Constructor
 * This is the default constructor for Critter objects which initializes the 
 * number of time steps taken in the game to zero. The Critter begins at row 0 
 * and column 0.
 *******************************************************************************/
Critter::Critter()
{
   steps = 0;
   hasMoved = 0;
   hungryDays = 0;
   rowNum = 0;
   colNum = 0;
   critterType = 0;
   print = ' ';
}

/*******************************************************************************
                               Constructor
 * This is a constructor for Critter objects. It takes two parameters and gives
 * the Critter a starting location of the respective row and column.
 *******************************************************************************/
Critter::Critter(int rowNum, int colNum, char print, int type)
{
   this->rowNum = rowNum;
   this->colNum = colNum;
   this->print = print;
   this->critterType = type;
}

bool Critter::move(Critter*** array, int maxRow, int maxCol) {
   // When a critter move DOWN or RIGHT, do not move the same critter again
   if (this->hasMoved == 1) {
      hasMoved = 0;
      return false;
   }

   int direction = pickRandomDirection(array, maxRow, maxCol);

   bool moved = false;
   std::cout << "(DEBUG) Critter [" << this->critterType << "] @ [" << rowNum << ", " << colNum << "] moves (" << direction << ") ";
   // try to move until all directions checked or moved
   switch (direction) {
         // move up
      case 0:
         array[rowNum - 1][colNum] = array[rowNum][colNum];
         array[rowNum][colNum] = nullptr;
         rowNum--;
         steps++;
         moved = true;
         break;
         // move down
      case 1:
         array[rowNum + 1][colNum] = array[rowNum][colNum];
         array[rowNum][colNum] = nullptr;
         rowNum++;
         steps++;
         moved = true;
         hasMoved = 1;
         break;
         // move left
      case 2:
         array[rowNum][colNum - 1] = array[rowNum][colNum];
         array[rowNum][colNum] = nullptr;
         colNum--;
         steps++;
         moved = true;
         break;
         // move right
      case 3:
         array[rowNum][colNum + 1] = array[rowNum][colNum];
         array[rowNum][colNum] = nullptr;
         colNum++;
         steps++;
         moved = true;
         hasMoved = 1;
         break;
   }
   std::cout << "to [" << rowNum << ", " << colNum << "], " << steps << " steps\n";

   return moved;
}

void Critter::breed(Critter*** array, int maxRow, int maxCol, char symbol, int type) {
   // override in derived classes
}

int Critter::pickRandomDirection(Critter*** array, int maxRow, int maxCol)
{
   int direction = std::rand() % 4;
   switch (direction) {
         // up
      case 0:
         if (!(rowNum > 0 && array[rowNum - 1][colNum] == nullptr)) {
            direction = -1; // selected cell is out of bound or occupied
         }
         break;
         // down
      case 1:
         if (!((rowNum < maxRow - 1) && array[rowNum + 1][colNum] == nullptr)) {
            direction = -1;
         }
         break;
         // left
      case 2:
         if (!(colNum > 0 && array[rowNum][colNum - 1] == nullptr)) {
            direction = -1;
         }
         break;
         // right
      case 3:
         if (!((colNum < maxCol - 1) && array[rowNum][colNum + 1] == nullptr)) {
            direction = -1;
         }
         break;
   }
   return direction;
}

void Critter::starve(Critter*** array, int days)
{
   if (this->hungryDays >= days)
   {
      std::cout << "RIP @ [" << rowNum << ", " << colNum << "]!!!\n";
      delete array[rowNum][colNum];
      array[rowNum][colNum] = nullptr;
   }
}

//virtual int getCritterType();
int Critter::getCritterType()
{
   return critterType;
}

//virtual string getPrint();
char Critter::getPrint()
{
   return print; 
}

Critter::~Critter()
{
   
}
