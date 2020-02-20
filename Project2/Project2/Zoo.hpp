/*********************************************************************
 ** Program name: Zoo.hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:
 *********************************************************************/
#ifndef Zoo_hpp
#define Zoo_hpp

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Zoo
{
   private:
      int bankAccunt; //$ in account, everyone start with $100,000

      Animal **tigerArray; //pointer pointer
      Animal **turtleArray;
      Animal **penguinArray;

      int tigerCapacity; //size of array, start with 10
      int tigerTotal;  //number of tigers in array

      int turtleCapacity; //size of array, start with 10
      int turtleTotal;  //number of tigers in array

      int penguinCapacity; //size of array, start with 10
      int penguinTotal;  //number of tigers in array

      int feedingChoice; //user input for type of feed
   
   public:
      Zoo(); //
      ~Zoo();
      int welcomeMenu();// welcome menu and return userChoice

      //function to purchase animal,subtract $ from bank, add number of animal,
      //check for capacity, resize array if needed, add animal obj to array
      void buyTiger();
      void buyPenguin();
      void buyTurtle();

      //function to subtract money from back accout and return account balance
      int subtractMoney(int);

      //get account balance
      int getAccountBalance();

      //to resize the array
      void resizeAnimal(Animal **& animal, int &size);

      //take capacity and number of animal in array as parameter, return true
      //if it does have engough capacity,return false if it needs resize
      bool checkCapacity(int capacity, int animalTotal);

      //aged animaals
       void addAge(); //all animals get 1 day older

      //feed the animals, update back accunt, return feeding choice
      int feedAnimals();

      //pick random event
      void randomEvent();
      void sickAnimal();
      void boomTiger();
      void bornBaby();
      void noEvent();

      //a function check if there is adult, yes return true, no return false
      // takes Animial pointer to animal array, num of animal as parameter
      bool adultAnimal(Animal**, int);

      //calculate payoff of the animals at the end of the day
      void payOff();

      //purchase adult animal
      void buyAdultAnimal();

      // ask if user want to start another day, return 1 yes, 2 no
      int playAgain();

      //delete animal arrays after after the end of game
      void deleteArray();


};

#endif
