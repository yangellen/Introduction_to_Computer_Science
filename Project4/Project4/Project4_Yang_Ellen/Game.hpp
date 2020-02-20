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
#include "Queue.hpp"

class Game
{
   private:
      Character *player;

      int damage;
      int attackerRoll; 
      int defenderRoll;

   public:
      Game();
      void setPlayer();

      //function to deallocate players at the end of combact
      //void deletePlayer(Character *player);

      //damage after attack, //attacker's roll - defender's roll-defender's armor
      int calDamage(int attack, int defend, int armor);

      //team A attack, return damage for team B
      int teamAattack(Character* teamA, Character* teamB);

      //team B attack, return damage for team A
      int teamBattack(Character* teamA, Character* teamB);

      //bool to check if player survive
      bool playerSurvive(Character* player);

      //
      Character* getPlayer();

};

#endif

