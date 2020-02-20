/*            Ellen Yang
**            Game.cpp
**            Oct 25, 2018
** This is Game.cpp specification file class Game, which contain member varialbes
** and function that facilitate the actons of the game. 
 *************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <string>

using std::string;

#include "Character.hpp"

class Game
{
   private:
      Character *player1;
      Character *player2;

      string player1Name;
      string player2Name;

      int damage;
      int attackerRoll; 
      int defenderRoll;

   public:
      Game();
      void setPlayer1();
      void setPlayer2();

      //functiont to deallocate players at the end of combact
      void deletePlayer();

      //damage after attack, //attacker's roll - defender's roll-defender's armor
      int calDamage(int attack, int defend, int armor);

      //player 1 attack
      void player1Attack();

      //plahyer 2 attack
      void player2Attack();

      //bool to check if player2 survive
      bool player2Survive();

      //bool to check if player1 survive
      bool player1Survive();

};

#endif
