/*******************************************************************************
 * Program name: Doodlebug.cpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the implementation file for Doodlebug.cpp which contains
 * functions for Doodlebug behavior to move, breed, and starve.
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Grid.hpp"

/*******************************************************************************
               			Default Constructor
 * This is the default constructor for Doodle objects which initializes the 
 * Doodlebug Ant with a starting location, character, and critter type.
 *******************************************************************************/
Doodlebug::Doodlebug() : Critter()
{
   print = 'X';
   critterType = 2;
}

/*******************************************************************************
 				Constructor
 * This is a constructor for Doodlebug objects. It takes two parameters and gives
 * the Doodlebug a starting location of the respective row and column, a 
 * character, and a critter type.
 *******************************************************************************/
Doodlebug::Doodlebug(int rowNum, int colNum, char print, int type): Critter()
{
   this->rowNum= rowNum;
   this->colNum = colNum;
   this->print = print;
   this->critterType = type;
}

/*******************************************************************************
 				move
 * This is the move function for Doodlebug. It overrides the virtual function in 
 * the base class Critter. The doddlebug tries to find an ant around itself, and 
 * if it finds one, the doodlebug eats it and takes its place on the board. If 
 * there is no ant ant around, update starveStep and move same rules as ants.
 *******************************************************************************/
bool Doodlebug::move(Critter*** array, int maxRow, int maxCol)
{
   if (this->hasMoved == 1) {
      hasMoved = 0;
      return false;
   }
   //check to see if there is ant around, in order of up, down, left ,right
   bool ate = false;
   bool moved = false;
   // try to eat up, if doodle not at top edge, has ant)
   if ((rowNum > 0) && array[rowNum - 1][colNum] != nullptr && array[rowNum - 1][colNum]->getCritterType() == 1)
   {
      delete array[rowNum - 1][colNum];
      //eat ant
      array[rowNum - 1][colNum] = array[rowNum][colNum];
      //set old cell to null
      array[rowNum][colNum] = nullptr;
      //update row
      rowNum --;
      ate = true;
   }
   // try to eat down, if doodle is not at bottole edge, has ant
   else if ((rowNum < maxRow - 1) && array[rowNum + 1][colNum] != nullptr && array[rowNum + 1][colNum]->getCritterType() == 1)
   {
      delete array[rowNum + 1][colNum];
      //eat ant
      array[rowNum + 1][colNum] = array[rowNum][colNum];
      //set old cell to null
      array[rowNum][colNum] = nullptr;
      //update row
      rowNum ++;
      ate = true;

      hasMoved = 1;
   }
   //try to eat left, if doodle is not at left edge, has ant
   else if ((colNum > 0) && array[rowNum][colNum - 1] != nullptr && array[rowNum][colNum - 1]->getCritterType()==1)
   {
      delete array[rowNum][colNum - 1];
      //eat left
      array[rowNum][colNum - 1] = array[rowNum][colNum];
      //set old cell to null
      array[rowNum][colNum] = nullptr;
      //update col
      colNum --;
      ate = true;
   }
   //try to eat right, if doodle is not at right edge, has ant
   else if ((colNum < maxCol - 1) && array[rowNum][colNum + 1] != nullptr && array[rowNum][colNum + 1]->getCritterType()==1)
   {
      delete array[rowNum][colNum + 1];
      //eat right
      array[rowNum][colNum + 1] = array[rowNum][colNum];
      //set old cell to null
      array[rowNum][colNum] = nullptr;
      //update col
      colNum ++;
      ate = true;

      hasMoved = 1;
   }
   else //no ants to eat, move like ant
   {
      moved = Critter::move(array, maxRow, maxCol);
      hungryDays++;
      std::cout << hungryDays << " hungryDays\n";
   }

   if (ate)
   {
      std::cout << "Yummy!!!\n";
      steps++;
      moved = true;
      hungryDays = 0;
   }

   return moved;
}

/*******************************************************************************
 			void starve(Critter ***&, int, int)
 * If doodlebug has not eaten an ant within three time steps, at the end of the 
 * third time step it will starve and die. The doodlebug is then removed from 
 * the grid of cells
 *******************************************************************************/
void Doodlebug::starve(Critter*** array, int row, int col)
{
   Critter::starve(array, 3);
}  

/*******************************************************************************
 				breed
 * This function overrides virtual function in Critter base class. Checks random
 * adjacent cell and if empty, creates a new doodlebug. If not empty, keeps 
 * randomly checking other cells. If none are empty, no breeding takes place.
 *******************************************************************************/
void Doodlebug::breed(Critter *** array, int maxRow, int maxCol, char symbol, int type) {
   // check for survival steps
   if (this->steps >= 8) {
      int direction = Critter::pickRandomDirection(array, maxRow, maxCol);
      // try again if first random selection is unavailable
      if (direction == -1)
      {
         direction = Critter::pickRandomDirection(array, maxRow, maxCol);
      }
      switch (direction) {
            // spawn up
         case 0:
            array[rowNum - 1][colNum] = new Doodlebug(rowNum - 1, colNum, symbol, type);
            break;
            // spawn down
         case 1:
            array[rowNum + 1][colNum] = new Doodlebug(rowNum + 1, colNum, symbol, type);
            break;
            // spawn left
         case 2:
            array[rowNum][colNum - 1] = new Doodlebug(rowNum, colNum - 1, symbol, type);
            break;
            // spawn right
         case 3:
            array[rowNum][colNum + 1] = new Doodlebug(rowNum, colNum + 1, symbol, type);
            break;
      }
      // reset steps
      if (direction != -1) {
         this->steps = 0;
      }
   }
}
