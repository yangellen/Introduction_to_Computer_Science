/****************************************************************************
 **  Game.cpp
 **  Ellen Yang
 **  11/28/18.
 **  This is the implantation of the Game class. This class is used to allow
 **  player to go to different rooms, and play the game. This class has vector
 **  container that allow the user to store coffee and sticker. It also has
 **  private varialbe and public functions that keep track of player's energy
 **  level and content of purse.
 ****************************************************************************/
#include "Game.hpp"
#include "PlayRoom.hpp"
#include "Kitchen.hpp"
#include "KidsRoom.hpp"
#include "BathRoom.hpp"
#include "ComputerRoom.hpp"
#include "MasterRoom.hpp"

using std::cout;
using std::endl;

/****************************************************************************
 **  Game::Game(int energy)
 **  default constructor for Game class. The start energy leavel will depend
 **  on the difficulty user choose. This function will take user input as
 **  parameter. This function also pushing zero int values in the purse.
 **  purse[0] for number of coffee
 **  purse[1] for sticker.
 ****************************************************************************/
Game::Game(int energy)
{
   switch (energy)
   {
      case 1:
         this->energyLevel = 20; //easy
         break;

      case 2:
         this->energyLevel = 15; //medium
         break;

      case 3:
         this->energyLevel = 10; //hard
         break;
   }
  // this->energyLevel = 15;
   purse.push_back(0); // coffee = 0;
   purse.push_back(0); // sticker = 0;
}

//
Game::~Game()
{
}

/****************************************************************************
 ** void Game::storeCoffee(int coffee)
 ** This function takes number of coffee drink in the room and store coffee
 ** energy in purse if there is room. Player can only hold 4 coffees in the
 ** purse.
 ****************************************************************************/
void Game::storeCoffee(int coffee)
{
   int j = 0;
   for ( int i = 0; i < coffee; i++)
   {
      if (purse[0] != 4) //store the energy in purse if no more than 4
      {
         purse[0]++;
         j++;
      }
   }
   cout<<"You have store "<< j <<" coffee in your purse while you are in this room."<<endl;
   cout<<endl;
}

/****************************************************************************
 ** void Game::momFaint()
 ** This function check to see if mom has enough energy. If not, check to see if
 ** there is coffee in the purse and apply energy if available. If coffee is
 ** used, check to see if it's enough to bring mom's energy back.
****************************************************************************/
 void Game::momFaint()
{
   if (hasFaint()) //if no energy
   {
      if (hasCoffee()) //check to see if there is coffee in the purse
      {
         //apply coffee energy to mom
         int i = 0; // #of coffee drink
         while (purse[0] != 0)
         {
            energyLevel ++;
            purse[0]--;
            i++;
         }
         cout<<"You used "<<i<<" cup(s) of coffe to restore your energy."<<endl;
         cout<<endl; 

         //check energy again
         if (hasFaint())
         {
            cout <<"Sorry, you are way too tired. Cofee didn't help much."<<endl;
            cout <<"Game over, mom is too tired and pass out on the floor."<<endl;
            cout <<endl;
         }
      }
      else
      {
         cout <<"Sorry, there is no coffee in your purse."<<endl;
         cout <<"Game over, mom is too tired and pass out on the floor."<<endl;
         cout <<endl;
      }
   }
}

/****************************************************************************
** bool Game::hasFaint()
** return true if there is no energy, false if there is engouh energy
****************************************************************************/
bool Game::hasFaint()
{
   if (energyLevel <= 0) //if no energy
   {
      return true;
   }
   else
   {
      return false;
   }
}

/****************************************************************************
**  bool Game::hasCoffee()
**  This function is use to see if there is coffee in the purse. Return true
**  if there is coffee, return false if not.
****************************************************************************/
bool Game::hasCoffee()
{
   if (purse[0] > 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/****************************************************************************
 ** bool Game::hasSticker()
 ** This functions use to check if there is sticker, return true if there is
 ** sticker and false if there is no sticker.
 ****************************************************************************/
bool Game::hasSticker()
{
   if (purse[1] > 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/****************************************************************************
 ** void Game::playGame()
 ** This is the function that start the game. Rooms are created as player is
 ** moving from room to room. This function will check to see if player has
 ** engouh energy and meet the requirement to go to the next room. 
 ****************************************************************************/
void Game::playGame()
{
   //start at play room
   Space *currentRoom = new PlayRoom(); //start with the play room
   currentRoom->right = new Kitchen(); //connect to the right

   currentRoom->roomIntro(); //introduction of current room
   cout <<"The room to your right is "<<currentRoom->right->getName()<<endl;
   cout <<"There is no room to your left"<<endl;
   cout <<endl;

   cout <<"Your current energy level is: "<<energyLevel<<endl;
   cout <<endl; 

   currentRoom->randomEvent(); //event happens
   cout <<"You have spend "<<currentRoom->getEnergyLost()<<" energy in this room."<<endl;

   energyLevel -= currentRoom->getEnergyLost();
   cout <<"Your energy level is "<<energyLevel<<" right now."<<endl;
   cout <<endl;

   int coffee = currentRoom->getCoffee(); //see if you drink any coffee in this room
   cout <<"You have drink "<<coffee<<" cup(s) of coffee in this room"<<endl;

   //store coffee energy in purse if not full
   storeCoffee(coffee);
   
   purse[1]++; //add 1 sticker in your purse
   cout <<"You have store "<<purse[1]<<" sticker in your purse."<<endl;
   cout <<endl;

   momFaint(); //check to see if mom has enough energy

   if (hasFaint())
   {
      delete currentRoom;
      delete currentRoom->right;
   }

   if (!hasFaint() && hasSticker() )
   {
      purse[1]--; //take away one sticker
      cout <<"Time for dinner, let's head to the kitchen."<<endl;
      cout <<"You used 1 sticker to enter the room"<<endl;

      //move to kitchen
      Space *temp = currentRoom; //have temp hold play room
      currentRoom = currentRoom->right; //current room is kitchen now
      currentRoom->left = temp; //playroom now is on left of kitchen
      currentRoom->right = new BathRoom(); //bathroom is now on right of kitchen

      currentRoom->roomIntro();//introduction of current room
      cout << "The room to your left is "<<currentRoom->left->getName()<<endl;
      cout <<"The room to your right is "<<currentRoom->right->getName()<<endl;
      cout <<endl;

      cout <<"Your current energy level is: "<<energyLevel<<endl;
      cout <<endl;

      currentRoom->randomEvent(); //event happens
      cout <<"You have spend "<<currentRoom->getEnergyLost()<<" energy in this room."<<endl;

      energyLevel -= currentRoom->getEnergyLost();
      cout <<"Your energy level is "<<energyLevel<<" right now."<<endl;
      cout <<endl;

      int coffee = currentRoom->getCoffee(); //see if you drink any coffee in this room
      cout <<"You have drink "<<coffee<<" cup(s) of coffee in this room"<<endl;

      //store coffee energy in purse if not full
      storeCoffee(coffee);

      purse[1]++; //add 1 sticker in your purse
      cout <<"You have store "<<purse[1]<<" sticker in your purse."<<endl;
      cout <<endl;

      momFaint(); //check to see if mom has enough energy

      if (hasFaint())
      {
         delete currentRoom;
         delete currentRoom->right;
         delete currentRoom->left;
      }

      //move to bathroom
      if (!hasFaint() && hasSticker() )
      {
         purse[1]--; //take away one sticker
         cout <<"You used 1 sticker to enter the next room"<<endl;

         Space *temp = currentRoom; //have temp hold kitchen room
         Space *garbage = currentRoom->left; //have garbage hold playroom
         delete garbage; //don't need play room anymore
         garbage = nullptr; //

         currentRoom = currentRoom->right; //current room is bathroom now
         currentRoom->left = temp; //kitchen now is on left of bathroom
         currentRoom->right = new KidsRoom(); //kid'sroom is now on right of kitchen

         currentRoom->roomIntro();//introduction of current room
         cout << "The room to your left is "<<currentRoom->left->getName()<<endl;
         cout <<"The room to your right is "<<currentRoom->right->getName()<<endl;
         cout <<endl;

         cout <<"Your current energy level is: "<<energyLevel<<endl;
         cout <<endl;

         currentRoom->randomEvent(); //event happens
         cout <<"You have spend "<<currentRoom->getEnergyLost()<<" energy in this room."<<endl;

         energyLevel -= currentRoom->getEnergyLost();
         cout<<"Your energy level is "<<energyLevel<<" right now."<<endl;
         cout<<endl; 

         int coffee = currentRoom->getCoffee(); //see if you drink any coffee in this room
         cout <<"You have drink "<<coffee<<" cup(s) of coffee in this room"<<endl;

         //store coffee energy in purse if not full
         storeCoffee(coffee);

         purse[1]++; //add 1 sticker in your purse
         cout <<"You have store "<<purse[1]<<" sticker in your purse."<<endl;
         cout <<endl;

         momFaint(); //check to see if mom has enough energy

         if (hasFaint())
         {
            delete currentRoom;
            delete currentRoom->right;
            delete currentRoom->left;
         }

         //move to kid's room
         if (!hasFaint() && hasSticker() )
         {
            purse[1]--; //take away one sticker
            cout <<"You used 1 sticker to enter the next room"<<endl;

            Space *temp = currentRoom; //have temp hold bathroom
            Space *garbage = currentRoom->left; //have garbage hold kitchen
            delete garbage; //don't need kitchecn anymore
            garbage = nullptr;

            currentRoom = currentRoom->right; //current room is kids room now
            currentRoom->left = temp; //bathroom now is on left of kid's room
            currentRoom->right = new ComputerRoom(); //computer room is now on right of kid's room

            currentRoom->roomIntro();//introduction of current room
            cout << "The room to your left is "<<currentRoom->left->getName()<<endl;
            cout <<"The room to your right is "<<currentRoom->right->getName()<<endl;
            cout <<endl;

            cout <<"Your current energy level is: "<<energyLevel<<endl;
            cout <<endl;

            currentRoom->randomEvent(); //event happens
            cout <<"You have spend "<<currentRoom->getEnergyLost()<<" energy in this room."<<endl;

            energyLevel -= currentRoom->getEnergyLost();
            cout<<"Your energy level is "<<energyLevel<<" right now."<<endl;

            int coffee = currentRoom->getCoffee(); //see if you drink any coffee in this room
            cout <<"You have drink "<<coffee<<" cup(s) of coffee in this room"<<endl;

            //store coffee energy in purse if not full
            storeCoffee(coffee);

            purse[1]++; //add 1 sticker in your purse
            cout <<"You have store "<<purse[1]<<" sticker in your purse."<<endl;
            cout <<endl;

            momFaint(); //check to see if mom has enough energy

            if (hasFaint())
            {
               delete currentRoom;
               delete currentRoom->right;
               delete currentRoom->left;
            }

         }

         //move to computer room
         if (!hasFaint() && hasSticker() )
         {
            purse[1]--; //take away one sticker
            cout <<"You used 1 sticker to enter the next room"<<endl;

            Space *temp = currentRoom; //have temp hold kids room
            Space *garbage = currentRoom->left; //have garbage hold bathroom
            delete garbage; //don't need bathroom anymore
            garbage = nullptr;

            currentRoom = currentRoom->right; //current room is computer room now
            currentRoom->left = temp; //kid's room now is on left of kid's room
            currentRoom->right = new MasterRoom(); //master room is now on right of kid's room

            currentRoom->roomIntro();//introduction of current room
            cout << "The room to your left is "<<currentRoom->left->getName()<<endl;
            cout <<"The room to your right is "<<currentRoom->right->getName()<<endl;
            cout <<endl;

            cout <<"Your current energy level is: "<<energyLevel<<endl;
            cout <<endl;

            currentRoom->randomEvent(); //event happens
            cout <<"You have spend "<<currentRoom->getEnergyLost()<<" energy in this room."<<endl;

            energyLevel -= currentRoom->getEnergyLost();
            cout<<"Your energy level is "<<energyLevel<<" right now."<<endl;

            int coffee = currentRoom->getCoffee(); //see if you drink any coffee in this room
            cout <<"You have drink "<<coffee<<" cup(s) of coffee in this room"<<endl;

            //store coffee energy in purse if not full
            storeCoffee(coffee);

            purse[1]++; //add 1 sticker in your purse
            cout <<"You have store "<<purse[1]<<" sticker in your purse."<<endl;
            cout <<endl;

            momFaint(); //check to see if mom has enough energy

            if (hasFaint())
            {
               delete currentRoom;
               delete currentRoom->right;
               delete currentRoom->left;
            }

         }

         //move to master room
         if (!hasFaint() && hasSticker() )
         {
            purse[1]--; //take away one sticker
            cout <<"You used 1 sticker to enter the next room"<<endl;

            Space *temp = currentRoom; //have temp hold computer room
            Space *garbage = currentRoom->left; //have garbage hold  kidsroom
            delete garbage; //don't need kids room anymore
            garbage = nullptr;

            currentRoom = currentRoom->right; //current room is master room now
            currentRoom->left = temp; //computer room now is on left of master room

            currentRoom->roomIntro();//introduction of current room
            cout << "The room to your left is "<<currentRoom->left->getName()<<endl;
            cout <<"There is no room to your right. "<<endl;
            cout <<endl;

            cout <<"Your current energy level is: "<<energyLevel<<endl;
            cout <<endl;

            currentRoom->randomEvent(); //event happens

            delete currentRoom->left; //delete the room to the left
            delete currentRoom; //game over delete current room
         }
      }
   }
}
