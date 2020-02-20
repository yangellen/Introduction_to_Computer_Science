/*********************************************************************
 ** Program name: Project1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 30, 2018
 ** Description:  the Ant.hpp that contains Ant.cpp class specification file,
 **               which contain the direction of the ant, the color of space
 **               where the ant is, the location of the ant and initilized
 **               the board, update the direction of ant, update color of the
 **               ant, and move the ant.
 *********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum antDirection {UP, DOWN, RIGHT, LEFT}; // assign direction of ant
enum spaceColor {WHITE, BLACK}; // assign color for the space ant is on

class Ant
{
   private:
      antDirection antOrientation; //declare enum antDirection
      spaceColor antColor; //declare enum antColor

      int antRow; //Row of ant location
      int antColumn; // Column of ant location

   public:
      void setAntRow(int startRow)
      { antRow = startRow; }

      void setAntColumn(int startColumn)
      { antColumn = startColumn;}
   
      /*take a pointer with 2d array, an interger as number of row, an integer
      of column and fill the board with spaces. initial step and star ant
      direction facing RIGHT, antColar is white*/
      void setBoard(char**, int, int);

      //a function that update the antDirection
      void changeDirection();

      //a function that change the color of space
      void changeColor (char **);

      //a function that move ant one step, check for edge case
      void moveAnt(int, int);

      //update the color of ant is at
      void updateAntColor(char**);

      // a funtion that print the board after each move
      void printBoard(char **, int, int);
};

#endif 
