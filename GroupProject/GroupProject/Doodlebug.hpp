/*******************************************************************************
 * Program name: Doodlebug.hpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the header file for Doodlebug.cpp which contains
 * functions for Doodlebug behavior to move, breed, and starve.
 *******************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include "Grid.hpp"

class Doodlebug: public Critter
{
   public:
      Doodlebug();
      Doodlebug(int, int, char, int);

      bool move(Critter***, int , int);
      void breed(Critter***, int, int, char, int);
      void starve(Critter***, int, int);
};


#endif
