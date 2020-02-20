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
#include "Queue.hpp"
#include "Stack.hpp"


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
      int teamApoints = 0;
      int teamBpoints = 0;

      int numFighter; //number of fighter per team
      numFighter = menu.numFighter();

      Queue *teamA = new Queue();
      Queue *teamB = new Queue();
      Stack *loser = new Stack ();

      Game game;

      int battle = 0; //counter for number of battle

      //set up teams
      for (int i = 0; i < numFighter; i++)
      {
         //team A set up
         cout <<"Team A: "<<endl;
         game.setPlayer(); // team pick character
         teamA->addBack(game.getPlayer()); //add to teamA Queue

         //team B set up
         cout <<"Team B: "<<endl;
         game.setPlayer();
         teamB->addBack(game.getPlayer());

      } //done set up the team

      int teamAfighter = numFighter;
      int teamBfighter = numFighter;

      //as long as there is fighter in both teams
      while (teamAfighter > 0 && teamBfighter >0)
      {
         battle ++;
         cout << "Battle "<<battle<<":";
         cout << " Team A " <<teamA->getFront()->getPlayerType()<<" ";
         cout <<teamA->getFront()->getName()<<" vs ";
         cout << "Team B " <<teamB->getFront()->getPlayerType()<<" ";
         cout <<teamB->getFront()->getName()<<endl;
         
         bool playerA = true; //use to check if player in team A survive
         bool playerB = true; //use to check if player in team B survive

         int playerAdamage = 0; //use to calculate total damage
         int playerBdamage = 0;

         while (playerA && playerB)
         {
            //team A attack
            playerBdamage += game.teamAattack(teamA->getFront(), teamB->getFront());

            //check to see if player in team B survive
            playerB = game.playerSurvive(teamB->getFront());

            if (!playerB)
            {
               teamBfighter--;

               cout <<"Team A "<<teamA->getFront()->getPlayerType()<<" ";
               cout <<teamA->getFront()->getName()<<" Won!" <<endl;

               teamApoints +=2;
               teamBpoints +=1;

               //teamA recover
               teamA->getFront()->recover(playerAdamage);
               cout<<"Recover strength: "<<teamA->getFront()->getStrength();
               cout <<endl;
               cout <<endl; 
               
               //add to the back
               // teamA->addBack(game.getPlayer());
               teamA->addBack(teamA->getFront());

               //remove front
               teamA->removeFront();

               //add to loser container
               loser->addTop(teamB->getFront());

               //teamB reomve
               teamB->removeFront();

            }

            else if (playerB)
            {
               //team B attack
               playerAdamage += game.teamBattack(teamA->getFront(), teamB->getFront());

               //check to see if player in team A survive
               playerA = game.playerSurvive(teamA->getFront());

               if (!playerA) //team B recover
               {
                  teamAfighter--;

                  cout <<"Team B "<<teamB->getFront()->getPlayerType()<<" ";
                  cout <<teamB->getFront()->getName()<<" Won!" <<endl;

                  teamBpoints +=2;
                  teamApoints +=1;

                  //teamB recover
                  teamB->getFront()->recover(playerBdamage);
                  cout<<"Recover strength: "<<teamB->getFront()->getStrength();
                  cout <<endl;
                  cout <<endl;

                  //add to the back
                  //teamB->addBack(game.getPlayer());
                  teamB->addBack(teamB->getFront());

                  //remove front
                  teamB->removeFront();

                  //player A go to loser container
                  loser->addTop(teamA->getFront());

                  //reomve player from team A
                  teamA->removeFront();
               }
            }
         }//end of round
      } //end of tournament

      //display final score
      cout <<endl;
      cout << "Final score of team A is: "<<teamApoints <<endl;
      cout << "Final score of team B is: "<<teamBpoints <<endl;
      cout <<endl;

      if (teamApoints > teamBpoints)
      {
         cout <<"Team A Won!" <<endl;
         delete teamA;
         teamA = nullptr;
      }
      else if (teamBpoints > teamApoints)

      {
         cout <<"Team B Won!"<<endl;
         delete teamB;
         teamB = nullptr;
      }

      else
      {
         cout <<"It's a tie!"<<endl;
         delete teamA;
         delete teamB;
         teamA = nullptr;
         teamB = nullptr;
      }

      // display the content of the loser pile?
      cout <<endl;
      int printLoser = menu.displayLoser();

      if (printLoser == 1)
      {
       //print loser pile
        loser->printStack();
       }

      delete loser;
      loser = nullptr;
      
      userInput = menu.combatMenu();

   } //end of user = 1

   cout <<"Goodbye, See you next time"<<endl;

   return 0;
}




