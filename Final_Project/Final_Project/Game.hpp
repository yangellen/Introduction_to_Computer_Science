/****************************************************************************
 **  Game.Hpp
 **  Ellen Yang
 **  11/28/18.
 **  This is the specification of the Game class. This class is used to allow
 **  player to go to different rooms, and play the game. This class has vector
 **  container that allow the user to store coffee and sticker. It also has
 **  private varialbe and public functions that keep track of player's energy
 **  level and content of purse.
 ****************************************************************************/

#ifndef Game_hpp
#define Game_hpp
#include "Space.hpp"
#include <vector>
#include <iostream>
#include <memory>

using std::vector;

class Game
{
   private:
      int energyLevel;
      vector<int> purse; //[0] = coffee (no more than 4 cups), [1] = sticker
   
   public:
      Game(int);

      void playGame();
      void storeCoffee(int); //store coffee energy in purse
      void momFaint(); //check to see if mom has enough energy and apply energy if available

      bool hasCoffee(); //check to see if there is coffee in the purse
      bool hasFaint(); //return true if there is no energy
      bool hasSticker(); //return true if there is sticker

      ~Game();

};

#endif 
