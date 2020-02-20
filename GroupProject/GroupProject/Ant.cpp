/*******************************************************************************
 * Program name: Ant.cpp
 * Group 11 Authors:  Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the implementation file for Ant class which contains 
 * functions for Ant behavior to move and to breed.
 *******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Critter.hpp"
#include "Ant.hpp"
#include "Grid.hpp"

/*******************************************************************************
               			Default Constructor
 * This is the default constructor for Ant objects which initializes the Ant with 
 * a starting location, character, and critter type.
 *******************************************************************************/
Ant::Ant() : Critter()
{
   print = 'O';
	critterType = 1;
}

/*******************************************************************************
 				Constructor
 * This is a constructor for Ant objects. It takes four parameters and gives
 * the Ant a starting location of the respective row and column, a character, 
 * and a critter type.
 *******************************************************************************/
Ant::Ant(int rowNum, int colNum, char print, int type) : Critter()
{
   this->rowNum = rowNum;
   this->colNum = colNum;
   this->print = print;
   this->critterType = type;
}

/*******************************************************************************
 				move
 * This function moves the Ant on the grid in the direction up, down, left, or 
 * right. It overrides the virtual function in the base class Critter.
*******************************************************************************/
bool Ant::move(Critter*** array, int row, int col)
{
   return Critter::move(array, row, col);
}

/*******************************************************************************
 				breed
 * This is the breed function for Ant.  It overrides the virtual function in the 
 * base class Critter.
 *******************************************************************************/
void Ant::breed(Critter*** array, int maxRow, int maxCol, char symbol, int type) {
   // check for survival steps
   if (this->steps >= 3) {
      int direction = Critter::pickRandomDirection(array, maxRow, maxCol);
      // try again if first random selection is unavailable
      if (direction == -1)
      {
         direction = Critter::pickRandomDirection(array, maxRow, maxCol);
      }
      std::cout << "Ant spawn direction (" << direction << ")\n";
      switch (direction) {
            // spawn up
         case 0:
            array[rowNum - 1][colNum] = new Ant(rowNum - 1, colNum, symbol, type);
            break;
            // spawn down
         case 1:
            array[rowNum + 1][colNum] = new Ant(rowNum + 1, colNum, symbol, type);
            break;
            // spawn left
         case 2:
            array[rowNum][colNum - 1] = new Ant(rowNum, colNum - 1, symbol, type);
            break;
            // spawn right
         case 3:
            array[rowNum][colNum + 1] = new Ant(rowNum, colNum + 1, symbol, type);
            break;
      }
      // reset steps
      if (direction != -1) {
         this->steps = 0;
      }
   }
}
