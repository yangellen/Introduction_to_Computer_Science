/***************************************************************************
**  Ellen Yang
**  main.cpp
**  12/1/2018
**  This is the main.cpp for the Final Project.
**  The Goal is for player to reach the master room and sleep without fainting.
**  Game over when player's energy level become less than one or when player
**  reach the master room.
**  The player has a purse that use to store coffee and sticker. The player can
**  only stored maximum of 4 coffee. Coffee can be use to restore some energy
**  for player.
****************************************************************************/
#include "Space.hpp"
#include "PlayRoom.hpp"
#include "Kitchen.hpp"
#include "BathRoom.hpp"
#include "KidsRoom.hpp"
#include "ComputerRoom.hpp"
#include "MasterRoom.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Menu.hpp"

int main()
{
   unsigned seed; //random generator seed
   seed = time(0);
   srand(seed);

   Menu menu;
   int userInput = menu.introMenu();

   while (userInput == 1)
   {
      int level = menu.gameLevel();
      Game game(level);
      game.playGame();
      userInput = menu.againMenu();
   }


   return 0;
}
