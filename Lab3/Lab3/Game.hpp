/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the Game.hpp that contains Game class specification file,
 **               which implements the dice-rolling war game
 *********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

//Game class declaration
class Game
{
   private:
      int introChoice; // see if user wants to play
      int numRound; //# rounds during simulation

      int numSide1; //# of sides of dice for player 1
      int numSide2; //# of sides of dice for player 2

      int countRound; //help to count the round

      int player1HelpChoice; //answer if player 1 needs help
      int player2HelpChoice; //aswer if player 2 needs help
   
      int player1Score;//hold score for player 1
      int player2Score;//hold score for player 2

      int *player1Array; //hold the numbers player1 roll
      int *player2Array; //hold the numbers player2 roll


   public:

      int introMenu(); //display intro menu, inputs, validates, and returns the
                     //user's choice to play or not to play

      int roundMenu();//ask the number of round during simulation, validates and
                  //return numbRound.

      int side1Menu();//ask the number of sides for the dice, validates and
                 //return numberSide
      int side2Menu();//ask the number of sides for the dice, validates and
                   //return numberSide

      int player1Menu();//ask if player 1 would like help during the game
                        //return and validate player1's choice
      int player2Menu();//ask if player 2 would like help during the game
                        //return and validate player2's choice

      void exitMenu(); //exit menu when user doesn't want to play

      void playGame(); //start to play game

      void finalResult(); //final result of the game


   











};

#endif

