/*******************************************************************************
 * Program name: Grid.cpp
 * Group 11 Authors: Livia Barwick, Helen Tran, Ellen Yang, Marie Knapp
 * Date: November 4th, 2018
 * Description: This is the implementation file for Grid class which contains 
 * functions to create the grid, to populate the grid, and to print the grid. 
 *******************************************************************************/
#include "Grid.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include <string>
#include "isDigit.hpp"

using std::endl;
using std::cout;

/*******************************************************************************
                             Default Constructor
 * This is the default constructor for the Grid class. Variables are intialized 
 * to 0 steps, 100 Ants, 5 Doodlebugs, and 20 rows and columns for the grid. 
 * An array of Critter pointers is created and filled with empty spaces.
 *******************************************************************************/
Grid::Grid(int numStep)
{
    timeSteps = 0;
    numAnts = 100;
    numDoodles = 5;
  
    row = 20;
    col = 20;
  
    this->timeSteps = numStep;
  
    //initialize 2D array of object pointers
    grid = new Critter**[row];
    for (int i = 0; i < row; i++)
    {
        grid[i] = new Critter*[col];
      
    }
  
    //fill array with null
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         grid[i][j] = nullptr;
      }
   }
  
  //randomlly place ant and doodlebug
   fillGrid(grid);
}

/*******************************************************************************
                                 Constructor
 * This is a constructor for the Grid class. Variables are intialized based on 
 * user input taken from the Menu class. An array of Critter pointers is created 
 * and filled with empty spaces.
 *******************************************************************************/
Grid::Grid (int numStep, int numAnts, int numDoodles, int numRow, int numCol)
{
   this->timeSteps = numStep;
   this->numAnts = numAnts;
   this->numDoodles = numDoodles;
   this->row = numRow;
   this->col = numCol;

   //initialize 2D array of object pointers
   grid = new Critter**[row];
   for (int i = 0; i < row; i++)
   {
     grid[i] = new Critter*[col];
   }

   //initialized with null
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         grid[i][j] = nullptr;
      }
   }
  
  //randomlly place ant and doodlebug
   fillGrid(grid);
}


/*******************************************************************************
                           fillGrid(Critter*** grid)
 * This function randomly places the number of doodlebugs and ants onto the grid.
 *******************************************************************************/
void Grid::fillGrid(Critter*** grid)
{
    //fill grid with ants
    while (numAnts != 0)
    {
      int antRow = rand() % row ;
      int antCol = rand() % col;
      if (grid[antRow][antCol] == nullptr)
      {
        grid[antRow][antCol] = new Ant(antRow, antCol, 'O', 1);
        numAnts--;
      }
    }

    //fill grid with doodlebugs
    while (numDoodles != 0)
    {
      int doodRow = rand() % row;
      int doodCol = rand() % col;
      if (grid[doodRow][doodCol] == nullptr)
      {
        grid[doodRow][doodCol] = new Doodlebug(doodRow, doodCol, 'X', 2);
        numDoodles--;
      }
    }

   printGrid();
}
/*******************************************************************************
                                 printGrid()
 * This function prints the grid and creates a border around the grind.
 *******************************************************************************/

void Grid::printGrid(){
    //create top border
    for (int borderTop = 0; borderTop < col + 2; borderTop++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        //create left border
        cout << "|";
        for (int j=0; j<col; j++)
        {
          if (checkSpace(i,j)== false)
            {
              cout << grid[i][j]->getPrint();
            }
            else
            {
              cout << ' ';
            }
        }
        //create right border
        cout << "|";
        cout << endl;
    }
    //create bottom border
    for (int borderBot = 0; borderBot < col + 2; borderBot++){
        cout << "-";
    }
    cout << endl;

}

/*******************************************************************************
                                    checkSpace
 * This function checks to see if a space is currently occupied. If space is 
 * occupied, checkSpace returns false.
 ********************************************************************************/
bool Grid::checkSpace(int rowCheck, int colCheck)
{
  if (grid [rowCheck][colCheck] == nullptr)
   {
      return true; //if empty
   }
   else
   {
      return false;
    }
}

/*******************************************************************************
                                     play
 * This function is called after the Menu creates the Grid. It contains the 
 * movements of the game as it is played on the Grid.
 ********************************************************************************/
void Grid::play()
{
   // critter type (1, ant) (2, doodlebug)
   // doodlebug move
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         if (grid[i][j] != nullptr && grid[i][j]->getCritterType() == 2)
         {
            grid[i][j]->move(grid, row, col);
         }
      }
   }
   // ant move
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         if (grid[i][j] != nullptr && grid [i][j]->getCritterType() == 1)
         {
            grid[i][j]->move(grid, row, col);
         }
      }
   }
   // doodlebug breed
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         if (grid[i][j] != nullptr && grid[i][j]->getCritterType() == 2)
         {
            grid[i][j]->breed(grid, row, col, 'X', 2);
         }
      }
   }
   // ant breed
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         if (grid[i][j] != nullptr && grid[i][j]->getCritterType() == 1)
         {
            grid[i][j]->breed(grid, row, col, 'O', 1);
         }
      }
   }
   // doodlebug starve
   for (int i = 0; i < row; i++)
      {
      for (int j = 0; j < col; j++)
      {
         if (grid[i][j] != nullptr && grid[i][j]->getCritterType() == 2)
         {
         // cast Critter to doodlebug
         // Doodlebug *ptr = static_cast<Doodlebug*>(grid[i][j]);
         static_cast<Doodlebug*>(grid[i][j])->starve(grid, row, col);
         }
      }
   }
   //display grid after each step
   printGrid();
}

/*******************************************************************************
                                   Destructor
 *******************************************************************************/
Grid::~Grid(){
/*for (int i = 0; i < row; i++)
{
   for(int j=0; j<col; j++)
   {
      if (grid[i][j] != nullptr)
      {
         delete [] grid[i][j];
      }
   }
      if (*grid [i] != nullptr)
      {
      delete [] grid[i];
      }
   }
      if (*grid != nullptr)
      {
         delete [] grid;
      }*/
}


int Grid::getRow()
{
   return row;
}

//
int Grid::getCol()
{
   return col; 
}
  
