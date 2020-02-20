/*********************************************************************
 ** Program name: Lab3_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 10, 2018
 ** Description:  the Game.cpp that contains Game class implementation file,
 **               which implements the dice-rolling war game
 *********************************************************************/
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "isDigit.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

/*********************************************************************
 **               Game::introMenu
 ** Description: This function displays the introduction and ask if user wants
 **              to play the game and inputs, validates, and
 **              return the user's choice.
 *********************************************************************/
int Game::introMenu()
{
   cout << "Welcome to War Game!" <<endl;
   cout << "This is a 2-player game. It is played through dice." <<endl;
   cout << "Please select" <<endl;
   cout << " 1. Play game or " <<endl;
   cout << " 2. Exit game " <<endl;

   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer ||
          choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
   {
      cout << "Please enter 1 to play or 2 to quit" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer once the string contains either 1 or 2
   int answer = stoi(choice);
   introChoice = answer;

   return introChoice;
}

/*********************************************************************
 **               Game::roundMenu
 ** Description: This function ask user number of rounds during simulation and
 **              validates and return number of round as integer
 *********************************************************************/
int Game::roundMenu()
{
   const int MAX = 10;
   const int MIN = 1;

   cout << "Please enter the number of rounds for the game:" <<endl;
   cout << "minimum " << MIN << " and maximum "<<MAX <<endl;
   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer)
   {
      cout << "Please enter positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   while (answer < MIN || answer > MAX)
   {
      cout << "The number of rounds need to be at least " <<MIN <<endl;
      cout << "and less or qual to "<<MAX <<endl;
      cout << "Please enter the number of rounds for game." <<endl;
      string choice;
      //takes in everything the user type in as string
      getline (cin, choice);
      //check to see if every charater in the string are numbers
      bool integer;
      integer = isDigit(choice);

      while (!integer)
      {
         cout << "Please enter positive integer only" <<endl;
         getline (cin, choice);
         integer = isDigit(choice);
      }
      //convert the string to integer with positive numbers only
      answer = stoi(choice);
   }

   numRound = answer;

   return numRound;
}
/*********************************************************************
 **               Game::side1Menu
 ** Description: This function ask user number of sides for the dice and
 **              validates and return number of sides as integer
 *********************************************************************/
int Game::side1Menu()
{
   const int MAX = 20;
   const int MIN = 4;

   cout << "PLAYER 1: " <<endl;
   cout << "Please enter the number of sides of the dice:" <<endl;
   cout << "minimum " << MIN << " and maximum "<<MAX <<endl;
   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer)
   {
      cout << "Please enter positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   while (answer < MIN || answer> MAX)
   {
      cout << "The number of sides needs to be at least " <<MIN <<endl;
      cout << "and less or qual to "<<MAX <<endl;
      cout << "Please enter the number of sides for dice." <<endl;
      string choice;
      //takes in everything the user type in as string
      getline (cin, choice);
      //check to see if every charater in the string are numbers
      bool integer;
      integer = isDigit(choice);

      while (!integer)
      {
         cout << "Please enter positive integer only" <<endl;
         getline (cin, choice);
         integer = isDigit(choice);
      }
      //convert the string to integer with positive numbers only
      answer = stoi(choice);
   }
   numSide1 = answer;

   return numSide1;
}

/*********************************************************************
 **               Game::side2Menu
 ** Description: This function ask user number of sides for the dice and
 **              validates and return number of sides as integer for player 2
 *********************************************************************/
int Game::side2Menu()
{
   const int MAX = 20;
   const int MIN = 4;

   cout << "PLAYER 2:" <<endl;
   cout << "Please enter the number of sides of the dice:" <<endl;
   cout << "minimum " << MIN << " and maximum "<<MAX <<endl;
   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer)
   {
      cout << "Please enter positive integer only" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }

   //convert the string to integer with positive non zero numbers only
   int answer = stoi(choice);

   while (answer < MIN || answer> MAX)
   {
      cout << "PLAYER 2: " <<endl;
      cout << "The number of sides needs to be at least " <<MIN <<endl;
      cout << "and less or qual to "<<MAX <<endl;
      cout << "Please enter the number of sides for dice." <<endl;
      string choice;
      //takes in everything the user type in as string
      getline (cin, choice);
      //check to see if every charater in the string are numbers
      bool integer;
      integer = isDigit(choice);

      while (!integer)
      {
         cout << "Please enter positive integer only" <<endl;
         getline (cin, choice);
         integer = isDigit(choice);
      }
      //convert the string to integer with positive numbers only
      answer = stoi(choice);
   }
   numSide2 = answer;

   return numSide2;
}
/****************************************************************
 **               Game::player1Menu
 ** Description: This function displays the help menu and ask if player 1 wants
 **              to use help during the game, validates, and
 **              return the player 1's choice.
 *********************************************************************/
int Game::player1Menu()
{
    cout << "PLAYER 1 :" <<endl;
    cout << "Would you like some help during the game" <<endl;
    cout << "Please select" <<endl;
    cout << " 1. Yes, I would like to use loaded die " <<endl;
    cout << " 2. NO, I would like to use regular die" <<endl;

    string choice;
    getline (cin, choice); //takes in everything the user type in as string

    //check to see if every charater in the string are numbers
    bool integer;
    integer = isDigit(choice);

    while (!integer ||
           choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
    {
       cout << "Please enter 1 for loaded die or 2 for regular die" <<endl;
       getline (cin, choice);
       integer = isDigit(choice);
    }
    //convert the string to integer once the string contains either 1 or 2
    player1HelpChoice= stoi(choice);

    return player1HelpChoice;
}
/****************************************************************
 **               Game::player2Menu
 ** Description: This function displays the help menu and ask if player 2 wants
 **              to use help during the game, validates, and
 **              return the player 2's choice.
 *********************************************************************/
int Game::player2Menu()
{
   cout << "PLAYER 2 :" <<endl;
   cout << "Would you like some help during the game" <<endl;
   cout << "Please select" <<endl;
   cout << " 1. Yes, I would like to use loaded die " <<endl;
   cout << " 2. NO, I would like to use regular die" <<endl;

   string choice;
   getline (cin, choice); //takes in everything the user type in as string

   //check to see if every charater in the string are numbers
   bool integer;
   integer = isDigit(choice);

   while (!integer ||
          choice.length() !=1 || (choice[0]!= '1' && choice[0] != '2'))
   {
      cout << "Please enter 1 for loaded die or 2 for regular die" <<endl;
      getline (cin, choice);
      integer = isDigit(choice);
   }
   //convert the string to integer once the string contains either 1 or 2
   player2HelpChoice= stoi(choice);

   return player2HelpChoice;
}
/*********************************************************************
 **               Game::ExitMenu
 ** Description: This function displays the message if user doesn't want to play
 *********************************************************************/
void Game::exitMenu()
{
   cout << "Thnaks for visiting. Have a good day!" <<endl; 
}

/*********************************************************************
 **               Game::playGame()
 ** Description: This function start the game by dynamically allocate the arrays
 **              that store the numbers player rolled, intialized varialbe
 **              countRound, both player's scores, have players roll the dies,
 **              print the result after each round, decallated the array and
 **              print the final result after all rounds are play.
 *********************************************************************/
void Game::playGame()
{
   //dynamically allocate arrays that store the numbers player rolled
   int *player1Array = new int[numRound];
   for (int i = 0; i < numRound; i++)//fill the array with zero
   {
      player1Array[i] = 0;
   }
   int *player2Array = new int[numRound];
   for (int i = 0; i < numRound; i++)
   {
      player2Array[i] = 0;
   }

   //set variables
   countRound = 0;

   player1Score = 0;
   player2Score = 0;

   //play game
   for (int i = 0; i < numRound; i++)
   {
      //player 1 roll the die and store the number
      if (player1HelpChoice == 1)
      {
         LoadedDie player1(numSide1);//create LoadedDie object
       //  player1.setDie(numSide1);
       //set number of side
         player1Array[i] = player1.rollDie();//roll the die and store the number
      }
     else if (player1HelpChoice == 2)
     {
         Die player1(numSide1); //create Die object
        // player1.setDie(numSide1);
        //set number of side in Die class
         player1Array[i] = player1.rollDie();//roll the die and store the number
      }

      //player 2 roll the die and store the number
      if (player2HelpChoice == 1)
      {
         LoadedDie player2(numSide2);//create LoadedDie object
      //   player2.setDie(numSide2); //set numver of sides of die
         player2Array[i] = player2.rollDie();//roll the die and store the number
      }
      else if (player2HelpChoice == 2)
      {
         Die player2(numSide2); //create Die object
     //    player2.setDie(numSide2); //set number of side in Die object
         player2Array[i] = player2.rollDie();//roll the die and store the number
      }

      //update score
      if (player1Array[i] > player2Array[i])
      {
         player1Score++;
      }
      else if (player2Array[i] > player1Array[i])
      {
         player2Score++;
      }
      countRound++;

      //print at the end of each round
      string dice[2]; //hold type of dice for player 1 and player 2

      if (player1HelpChoice == 1)
      {
         dice[0] = "Loaded";
      }
      else if (player1HelpChoice == 2)
      {
         dice[0] = "Regular";
      }

      if (player2HelpChoice == 1)
      {
         dice[1] = "Loaded";
      }
      else if (player2HelpChoice == 2)
      {
         dice[1] = "Regular";
      }

      cout << "Round: "<<countRound<<endl;
      cout << setw(10)<<"Player"<<setw(10)<<"# side"<< setw(10) << "Die";
      cout << setw(10) << "# roll"<< setw(10) << "Score" << endl;

      //for player 1
      cout << setw(10)<<"1"<<setw(10)<<numSide1;
      cout << setw(10) << dice[0] <<setw(10)<<player1Array[i];
      cout << setw(10) << player1Score << endl;

      //for player2
      cout << setw(10)<<"2"<<setw(10)<<numSide2;
      cout << setw(10) << dice[1] <<setw(10)<<player2Array[i];
      cout << setw(10) << player2Score << endl;
      cout <<endl;
   }
   
   //deallocate array
   delete[]player1Array;
   delete[]player2Array;
}
/*********************************************************************
 **               Game:finalResult()
 ** Description: This function display the final scores of both players and
 **              display the result of the game.
 *********************************************************************/
void Game::finalResult()
{
   cout << "Player 1 final socre: "<<player1Score<<endl;
   cout << "Player 2 final score: "<<player2Score<<endl;

   if (player1Score > player2Score)
   {
      cout << "Player 1 WON!"<<endl;
   }
   else if (player2Score > player1Score)
   {
      cout << "Player 2 WON!"<<endl;
   }
   else
   {
      cout << "It's a Draw!" <<endl;
   }
}


