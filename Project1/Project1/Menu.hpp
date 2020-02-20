/*********************************************************************
 ** Program name: Project1_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Sep 26, 2018
 ** Description:  the Menu.hpp that contains menu class specification file,
 **               which prints menu options to the screen for the user,
 **               verify the user input and return the value back to the
 **               program.
 *********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>

using std:: string;

//Menu class declaration
class Menu
{
   private:
      int introChoice; // see if user wants to play
      int endChoice; //see if user wants to play again
      int randomChoice; // see if user wants to use a random starting location

      int numberRow; //# rows for the board
      int numberColumn;//# columns for the board
      int numberStep; //# steps during simulation

      int startRow; //start Row for ant
      int startColumn; //start Column for ant

   public:
      int introMenu(); //display intro menu, inputs, validates, and returns the
                    //user's choice to play or not to play
      int randomMenu();//ask if user would like to use a random location for ant
                     //validates, and return the user's choice
      int endMenu();//display end of game menu, inputs, validates, and returns
                 //the user's choice to play or not to play

      int rowMenu();//ask the number of rows for the board, validates and
                    //return numberRow.
      int columnMenu();//ask the number of column for the board, validates and
                       //return numberRow.
      int stepMenu();//ask the number of steps during simulation, validates and
                    //return numberRow.

      int rowStart();// ask user for the starting row of ant, validates and
                     // return starting row of the ant.
      int columnStart();// ask user for the starting column of ant, validates
                  // and return starting column of the ant.

      int randomRow(); // randomlly pick a starting row and return starting
                       //row of ant

      int randomColumn(); // randomlly pick a starting column and return
                    //starting column of ant

      bool isDigit(string); //take a string to check if it's all digits and
                            //return bool
};

#endif
