/*********************************************************************
 ** Program name: main cpp for Project2_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Zoo Tycoon game that allowes the player to be a virtual zoon
 **               owner.The player will be able run a zoo usiness with
 **               different types of animals cost different prcies, have
 **               different maintenance cost and different profit at the end of
 **               each day.
 *********************************************************************/ //
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Menu.hpp"
#include "Zoo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


using std::cout;
using std::endl;



int main()
{
   Zoo zoo; //create zoo object
   int userChoice; //variable to hold user input
   int countDay = 0; //count for number of day

   userChoice = zoo.welcomeMenu(); //ask if uers wants to play

   if (userChoice == 1) //if user wants to play
   {
      //buy animals, sub $ from bank, increase number of animal, add animal
      //obj to array.
      
      zoo.buyTiger();
      zoo.buyTurtle();
      zoo.buyPenguin();


      while (userChoice == 1)
      {
         countDay ++; 

         cout << "Day "<< countDay <<endl;
         //Start Day
         zoo.addAge(); //All animal increase age by 1
         zoo.feedAnimals(); //Feed the animals

         //random event
         unsigned seed;
         seed = time(0); //use the time function to get a "seed" value for srand
         srand(seed); // use for random event

         zoo.randomEvent(); //pick random event
         zoo.payOff(); //add $ to account
         zoo.buyAdultAnimal(); //buy adult animal??

         //check balance at the end of day
         if (zoo.getAccountBalance() <= 0)
         {
            cout <<"You have no money left in your account." <<endl;
            cout << "Game Over!" <<endl;

            userChoice = 2;
         }
         else //ask if user want to keep on playing
         {
            userChoice = zoo.playAgain();
         }
      } //repeat if user wants to play

     // zoo.deleteArray(); //delete arrays no longer use
   }

   else if (userChoice == 2) //user doesn't want to play
   {
      std::cout <<"Thanks for playing! Hope to see you soon!"<<std::endl;
   }


   return 0;
}
