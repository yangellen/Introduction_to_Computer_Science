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

/**************************************************************************
**            Game::Game()
** A default contructor that initilized member variables.
****************************************************************************/
//default
Game::Game()
{
   player1 = nullptr;
   player2 = nullptr;

   this->attackerRoll = 0;
   this->defenderRoll = 0;

   this->damage = 0;

   player1Name = "NO Name";
   player2Name = "NO one";
}

/**************************************************************************
 **      void Game::setPlayer1()
 ** A function that let user pick character for player 1 and allocate memory
 ** for character depending on the user choice.
 ****************************************************************************/
void Game::setPlayer1()
{
   Menu menu;
   cout<<"Player 1:"<<endl;

   int choice = menu.pickCharacter();

   switch (choice)
   {
      case 1:
      {
         player1Name = "Vampire";
         player1 = new Vampire();
      }
         break;
      case 2:
      {
         player1Name = "Barbarian";
         player1 = new Barbarian();
      }
         break;
      case 3:
      {
         player1Name = "Blue Men";
         player1 = new BlueMen();
      }
         break;
      case 4:
      {
         player1Name = "Medusa";
         player1 = new Medusa();
      }
         break;
      case 5:
      {
         player1Name = "Harry Potter";
         player1 = new HarryPotter();
      }
         break;
   }
}

/**************************************************************************
 **      void Game::setPlayer2()
 ** A function that let user pick character for player 2 and allocate memory
 ** for character depending on the user choice.
 ****************************************************************************/
void Game::setPlayer2()
{
   Menu menu;
   cout <<"Player 2:"<<endl;

   int choice = menu.pickCharacter();

   switch (choice)
   {
      case 1:
      {
         player2Name = "Vampire";
         player2 = new Vampire();
         
      }
         break;
      case 2:
      {
         player2Name = "Barbarian";
         player2 = new Barbarian();
         
      }
         break;
      case 3:
      {
         player2Name = "Blue Men";
         player2 = new BlueMen();
      }
         break;
      case 4:
      {
         player2Name = "Medusa";
         player2 = new Medusa();
      }
         break;
      case 5:
      {
         player2Name = "Harry Potter";
         player2 = new HarryPotter();
      }
         break;
   }

}

/**************************************************************************
 **       void Game::deletePlayer()
 ** A functiont to deallocate players at the end of combact
 ****************************************************************************/
void Game::deletePlayer()
{
   delete player1;
   delete player2;
}

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
 **     void Game::player1Attack()
 ** This function lets player 1 attack, player 2 defend , display players' info,
 ** attacker dice roll, defender's dice roll, damage, and update strength of
 ** defender.
 ****************************************************************************/
void Game::player1Attack()
{
   cout <<"Player 1 attack"<<endl;
   cout <<"1. Attacker  type: "<<player1Name<<endl;
   cout <<"            armor: "<<player1->getArmor() <<endl;
   cout <<"   strength point: "<<player1->getStrength()<<endl;
   cout <<endl;

   cout <<"2. Defender  type: "<<player2Name <<endl;
   cout <<"            armor: "<<player2->getArmor() <<endl;
   cout <<"   strength point: "<<player2->getStrength()<<endl;

   attackerRoll = player1->attack();
   cout <<"3. Attacker's attack dice roll : " <<attackerRoll<<endl;

   defenderRoll = player2->defense();
   cout <<"4. Defender's defend dice roll: "<<defenderRoll<<endl;

   calDamage(player1->getAttack(), player2->getDefense(), player2->getArmor());

   cout <<"5. Total inflicted damage: " <<damage<<endl;

   player2->updateStrength(damage); //update strength

   cout <<"6. Defender's update strength point: "<<player2->getStrength()<<endl;
   cout <<endl;
}

/**************************************************************************
 **     void Game::player2Attack()
 ** This function lets player 2 attack, player 1 defend , display players' info,
 ** attacker dice roll, defender's dice roll, damage, and update strength of
 ** defender.
 ****************************************************************************/
void Game::player2Attack()
{
   cout <<"Player 2 attack"<<endl;
   cout <<"1. Attacker  type: "<<player2Name<<endl;
   cout <<"            armor: "<<player2->getArmor() <<endl;
   cout <<"   strength point: "<<player2->getStrength()<<endl;
   cout <<endl; 

   cout <<"2. Defender  type: "<<player1Name <<endl;
   cout <<"            armor: "<<player1->getArmor() <<endl;
   cout <<"   strength point: "<<player1->getStrength()<<endl;

   attackerRoll = player2->attack();
   cout <<"3. Attacker's attack dice roll : " <<attackerRoll<<endl;

   defenderRoll = player1->defense();
   cout <<"4. Defender's defend dice roll: "<<defenderRoll<<endl;

   calDamage(player2->getAttack(), player1->getDefense(), player1->getArmor());

   cout <<"5. Total inflicted damage: " <<damage<<endl;

   player1->updateStrength(damage); //update strength

   cout <<"6. Defender's update strength point: "<<player1->getStrength()<<endl;
   cout <<endl;
}

/*****************************************************************
 **   bool Game::player2Survive()
 **This function check if see if player 2 survive during the battle and return
 ** ture if player 2 survive and return false if player 2 didn't survive.
 ********************************************************************/
bool Game::player2Survive() 
{
   if (player2->getStrength() > 0)
   {
      return true;
   }
   else
   {
      cout <<"Player 2 didn't survive the battle!"<<endl;
      return false;
   }
}

/*****************************************************************
 **   bool Game::player1Survive()
 **This function check if see if player 1 survive during the battle and return
 ** ture if player 1 survive and return false if player 1 didn't survive.
 ********************************************************************/
bool Game::player1Survive()
{
   if (player1->getStrength() > 0)
   {
      return true;
   }
   else
   {
      cout <<"Player 1 didn't survive the battle!"<<endl;
      return false;
   }
}
