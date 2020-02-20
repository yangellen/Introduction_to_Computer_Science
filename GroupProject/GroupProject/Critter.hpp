/*******************************************************************************
 * Program name: Critter.hpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the header file for Critter class.
 *******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>

class Critter
{
   protected:
      int steps;
      int hasMoved; // avoid move critter again if move is down or right
      int hungryDays;
      int rowNum; // row position
      int colNum; // col position
      int critterType; // 1 for ant, 2 for doodle
      char print; // 'O' for ant, 'X' for doodlebug, ' ' for empty space

   public:
      Critter();
      Critter(int row, int col, char print, int type);

      virtual ~Critter();
      virtual bool move(Critter***, int, int);
      virtual void breed(Critter***, int, int, char, int);
      virtual void starve(Critter***, int);
      int pickRandomDirection(Critter***, int, int);

      virtual int getCritterType();
      virtual char getPrint();
};

#endif

