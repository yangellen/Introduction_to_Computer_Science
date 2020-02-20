/*****************************************************************
**       Ellen Yang
**       Project3_Yang_Ellen.zip
**       main.cpp
**       This is the main function of the fantasy combact game. This is the
 **      entry point of the game. 
********************************************************************/
#include "Character.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


using std::endl;
using std::cout;

int main()
{
   unsigned seed; //random generator seed
   seed = time(0);
   srand(seed);

   Menu menu;
   int userInput = menu.introMenu();

   while (userInput == 1)
   {
      int round = 0; //counter for number of rounds
      Game game;
      game.setPlayer1(); //player 1 pick character
      game.setPlayer2(); //player 2 pick character

      bool player1 = true; //use to check if player 1 survive
      bool player2 = true; //use to check if player 2 survive

      while (player1 && player2)
      {
         round++;
         cout << "Round: "<<round<<endl;

         game.player1Attack();//player 1 attack first

         //check to see if player 2 survive
         player2 = game.player2Survive();

         if (player2)
         {
            game.player2Attack(); //player 2 attack

            //check to see if playe 1 survive
            player1 = game.player1Survive();
         }
      }

      game.deletePlayer(); //delete players when game over
      //combat over, ask if user wants to play again
      userInput = menu.combatMenu();
   }

   cout <<"Goodbye, See you next time"<<endl;

   return 0;
}

/*****************************************************************
 **
 **
 ********************************************************************/
