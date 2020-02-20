/*******************************************************************************
* Program name: Grid.hpp
* Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
* Date: November 4th, 2018
* Description: This is the header file for Grid class which contains 
* functions to create the grid, to populate the grid, and to print the grid. 
*******************************************************************************/
#ifndef GRID_HPP
#define GRID_HPP
#include "Critter.hpp"

class Grid
{
  private:
    int timeSteps;
    int numAnts; //number of ants to start the grid
    int numDoodles; //number of doodles to start the grid
    int row; //number of row for grid
    int col; //number of col for grid
  
    //2D array of object pointers
    Critter ***grid;  

  public:
    Grid();
    Grid(int);
    Grid (int, int, int, int, int);
    ~Grid();
  
    void fillGrid(Critter***);
    void printGrid();
    bool checkSpace(int, int); //check to see if space is empty

    int getRow();
    int getCol();
  
    void play();
  
};
#endif
