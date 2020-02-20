/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the main file that contains main function that simulates
 **               2-player dice-rolling war game.
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include "Game.hpp"
#include <cctype>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

int main()
{
   Game game; //declar a Game object

   int userChoice; //answer if user wants to play
   
   userChoice = game.introMenu(); //ask if user wants to play

   if (userChoice == 1) //if user wants to play
   {
      game.roundMenu(); // ask for number of rounds

      game.side1Menu(); // ask for number of sides of dice for player 1
      game.side2Menu(); //ask for number of sides of dice for player 2
      
      game.player1Menu(); //type of die for player 1
      game.player2Menu(); //type of die for player 2

      unsigned seed;//random generator see
      seed = time(0); //use the time function to get a "seed" value for srand
      srand(seed);

      game.playGame(); //play game and print result of each round
      game.finalResult(); // print final result
   }

   else if (userChoice == 2) //if user wants to quit
   {
      game.exitMenu();
   }

   return 0;
}




