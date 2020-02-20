/*******************************************************************************
 * Program name: Ant.hpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the header file for Ant class which contains 
 * functions for Ant behavior to move and to breed.
 *******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include "Grid.hpp"

class Ant: public Critter
{
   public:
      Ant();
      Ant(int, int, char, int);

      bool move(Critter***, int, int);
      void breed(Critter***, int, int, char, int);
};


#endif
