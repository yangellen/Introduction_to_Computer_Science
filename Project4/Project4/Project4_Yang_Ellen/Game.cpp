/***************************************************************************
**            Ellen Yang
**            Game.cpp
**            Oct 25, 2018
** This is Game.cpp implantation file for class Game, which contain member
** varialbes and function that facilitate the actons of the game.
 *************************************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

/**************************************************************************
**            Game::Game()
** A default contructor that initilized member variables.
****************************************************************************/
//default
Game::Game()
{
   player = nullptr;

   this->attackerRoll = 0;
   this->defenderRoll = 0;

   this->damage = 0;
}

/**************************************************************************
 **      void Game::setPlayer()
 ** A function that let user pick character and allocate memory
 ** for character depending on the user choice.
 ****************************************************************************/
void Game::setPlayer()
{
   Menu menu;

   int choice = menu.pickCharacter();
   string playerName;

   cout <<"Please enter a name for the fighter."<<endl;
   getline(cin, playerName);
   cout <<endl;

   switch (choice)
   {
      case 1:
      {
         player = new Vampire(playerName,"Vampire", 1, 18);
      }
         break;
      case 2:
      {
         player = new Barbarian(playerName,"Barbarian",0, 12);
      }
         break;
      case 3:
      {
         player = new BlueMen(playerName,"Blue Men", 3, 12);
      }
         break;
      case 4:
      {
         player = new Medusa(playerName,"Medusa",3, 8);
      }
         break;
      case 5:
      {
         player = new HarryPotter(playerName,"Harry Potter", 0, 10);
      }
         break;
   }
}

/**************************************************************************
 **       void Game::deletePlayer()
 ** A functiont to deallocate players at the end of combact
 ****************************************************************************/
/*void Game::deletePlayer(Character *player)
{
   delete player; 
}
*/
/**************************************************************************
 **         int Game::callDamage(int attacker, int defender, int armor)
 ** This function calculate damage after attack. The function take attacker's
 ** roll, defender's rol, and defender's armor as parameters.
 ** damage = attacker's roll - defender's roll-defender's armor
 ****************************************************************************/
int Game::calDamage(int attacker, int defender, int armor)
{
   this->damage = attacker - defender - armor;

   if (this->damage < 0)
   {
      this->damage = 0;
   }

   return damage;
}

/**************************************************************************
 **     void Game:TeamAattack()
 ** This function lets team A attack, team B defend and return damage.
 ****************************************************************************/
int Game::teamAattack(Character* teamA, Character* teamB)
{
   teamA->attack();
   teamB->defense();

   calDamage(teamA->getAttack(), teamB->getDefense(), teamB->getArmor());

   teamB->updateStrength(damage); //update strength

   return damage;
}

/**************************************************************************
 **     void Game::teamBattack()
 ** This function lets team B attack, team A defend and return damage.
 ****************************************************************************/
int Game::teamBattack(Character* teamA, Character* teamB)
{
  teamB->attack();
  teamA->defense();

   calDamage(teamB->getAttack(), teamA->getDefense(), teamA->getArmor());

   teamA->updateStrength(damage); //update strength

   return damage;
}

/*****************************************************************
 **   bool Game::playerSurvive()
 **This function check if see if player survive during the battle and return
 ** ture if player 1 survive and return false if player didn't survive.
 ********************************************************************/
bool Game::playerSurvive(Character *player)
{
   if (player->getStrength() > 0)
   {
      return true;
   }
   else
   {
      //cout <<player->getName()<<" didn't survive the battle!"<<endl;
      return false;
   }
}

//getter function which return player. 
Character* Game::getPlayer()
{
   return player;
}



