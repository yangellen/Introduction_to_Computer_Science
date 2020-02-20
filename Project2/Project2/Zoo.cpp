/*********************************************************************
 ** Program name: Zoo.cpp
 ** Author:       Ellen Yang
 ** Date:         Oct. 15, 2018
 ** Description:  This is class Zoo implenmentation file. This is where most
 **               actions are taking. It contains functions to intilized arrays,
 **               buying animails, substract money from back, update number of
 **               animals, capacity of arry, resize array function, random
 **               events.
 *********************************************************************/
#include "Zoo.hpp"
#include "Menu.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


/***********************************************************
 **       Zoo::Zoo()
 **       zoo default contractor, initilze bank accout, dynamicall allocate
 **       different animal array, fill the arrays with zero, initil member
 **       variables.
 **************************************************************************/
Zoo::Zoo()
{
   bankAccunt = 100000;

   //dynamical allocate different animal objects
   tigerArray = new Animal* [10];
   turtleArray = new Animal* [10];
   penguinArray = new Animal* [10];

   //initilized array
   for (int i = 0; i < 10; i++)
   {
      tigerArray[i] = 0;
      turtleArray[i] = 0;
      penguinArray[i] = 0;
   }
   
   turtleCapacity = 10;
   turtleTotal = 0;
   tigerCapacity = 10;
   tigerTotal = 0;
   penguinCapacity = 10;
   penguinTotal = 0;
}

/***********************************************************************
 **         int Zoo::welcome menu ()
 ** A function that welcome the user, info user requirement to start the game
 ** ask if user wants to play. Return user's choice as integer.
 *********************************************************************/
int Zoo::welcomeMenu()
{
   Menu menu; //create menu object
   menu.addString("Welcome to Zoo Tycoon!");// add string to menu
   menu.addString("You have $100,000 to start your zoo business.");
   menu.addString("To start your business,");
   menu.addString("You need to buy three types of animals:" );
   menu.addString("Tiger,Penguins,Turtle");
   menu.addString("Each type should have a quantity of either 1 or 2");
   menu.addString("Please enter");
   menu.addString(" 1. Play");
   menu.addString(" 2. Quit");

   return menu.userInput(1, 2);
}

/**********************************************************************
 **     Zoo::buyTiger()
 ** A function to  ask user to purchase Tigers to start the zoo,
 ** update tiger total, subtract $ from bank, add tiger to tiger array
 * ********************************************************************/
void Zoo::buyTiger()
{
   Menu menu;
   menu.addString("How many Tigers would you like to buy?");
   menu.addString("Each tiger cost $ 10000");
   menu.addString(" 1 Tiger");
   menu.addString(" 2 Tigers");
   int userChoice = menu.userInput(1, 2);

   if (userChoice == 1)
   {
      cout <<"You purchase one tiger." <<endl;

      subtractMoney(Tiger().getCost()); //subtract money from bank

      tigerArray[tigerTotal] = new Tiger();//add tiger obj to tigerArray
      tigerTotal++; //increase number of tigers by 1
   }

   else if (userChoice == 2)
   {
      cout <<"You purchase two tigers." <<endl;

      subtractMoney(Tiger().getCost()); //subtract money from bank
      subtractMoney(Tiger().getCost()); //subtract money from bank

      tigerArray[tigerTotal] = new Tiger();// add tiger obj to tigerArray
      tigerTotal ++; //increase number of tiger by 1

      tigerArray[tigerTotal] = new Tiger();//add another tiger obj to tigerArray
      tigerTotal++; //update #tiger total
   }

   cout << "You have " <<tigerTotal <<" tiger(s) in the zoo" <<endl;
   cout <<"You have $ "<<bankAccunt<< " in the bank" <<endl;
   cout <<endl; 
}

/******************************************************************
**      bool Zoo::checkCapacity(int capacity, int totalAnimal)
** Take number of capacity and number of animal as parameter to check
** if there is enough capacity. Return bool true if there is enough capacity
** else return false.
 ***************************************************************************/
bool Zoo::checkCapacity(int capacity, int totalAnimal)
{
   if (capacity >= totalAnimal)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/**********************************************************************
 **     Zoo::buyTurtle()
 ** A function to  ask user to purchase Turtle to start the zoo,
 ** update tiger total, subtract $ from bank, add tiger to turtle array
 * ********************************************************************/
void Zoo::buyTurtle()
{
   Menu menu;
   menu.addString("How many Turtles would you like to buy?");
   menu.addString("Each turtle cost $ 100");
   menu.addString(" 1 Turtle");
   menu.addString(" 2 Turtles");
   int userChoice = menu.userInput(1, 2);

   if (userChoice == 1)
   {
      cout <<"You purchase one turlte." <<endl;

      subtractMoney(Turtle().getCost()); //subtract money from bank

      turtleArray[turtleTotal] = new Turtle(); //assign tutle obj
      turtleTotal++; //increase number of turtle by 1

   }

   else if (userChoice == 2)
   {
      cout<<"You purchase two turtles." <<endl;

      subtractMoney(Turtle().getCost()); //subtract money from bank
      subtractMoney(Turtle().getCost()); //subtract money from bank

      turtleArray[turtleTotal] = new Turtle(); //assign turtle obj to array
      turtleTotal++; //increase number of turtle by 1

      turtleArray[turtleTotal] = new Turtle(); //assign turtle obj to array
      turtleTotal++; //increase number of turtle by 1
   }

   cout << "You have "<<turtleTotal<<" turtle(s) in the zoo" <<endl;
   cout <<"You have $ "<<bankAccunt<< " in the bank."<<endl;
   cout <<endl;
}

/**********************************************************************
 **     Zoo::buyPenguin()
 ** A function to  ask user to purchase Penguin to start the zoo
 ** update penguin total, subtract $ from bank, add penguin to penguin array
 * ********************************************************************/
void Zoo::buyPenguin()
{
   Menu menu;
   menu.addString("How many Penguins would you like to buy?");
   menu.addString("Each penguin cost $ 1000");
   menu.addString(" 1 Penguin");
   menu.addString(" 2 Penguins");
   int userChoice = menu.userInput(1, 2);

   if (userChoice == 1)
   {
      cout <<"You purchase 1 penguin." <<endl;

      subtractMoney(Penguin().getCost()); //subtract money from bank

      penguinArray[penguinTotal] = new Penguin();
      penguinTotal++; //increase number of penguin by 1

   }

   else if (userChoice == 2)
   {
      cout <<"You purchase two penguins in the zoo" <<endl;

      subtractMoney(Penguin().getCost()); //subtract money from bank
      subtractMoney(Penguin().getCost()); //subtract money from bank

      penguinArray[penguinTotal] = new Penguin();
      penguinTotal++; //increase number of penguin by 1

      penguinArray[penguinTotal] = new Penguin();
      penguinTotal++; //increase number of penguin by 1

   }

   cout <<"You have " <<penguinTotal <<" penguin(s) in the zoo"<<endl;
   cout <<"You have $ "<<bankAccunt <<" in the bank" <<endl;
   cout <<endl;
}

/**************************************************************************
 **   int Zoo::subtractMoney(int animalCost)
 **   A function take cost of animal as parameter to subtract money from back
 **  accout then return account balance.
*****************************************************************************/
int Zoo::subtractMoney(int animalCost)
{
   return bankAccunt -= animalCost;
}

//getter function tha return account balance
int Zoo::getAccountBalance()
{
   return bankAccunt;
}

/*************************************************************************
 **        void Zoo::resizeAnimal(Animal **&, int &size)
 *This function double the size of array. Create a new array, copy old to new,
 **  delete the old array , then have new array become old array.
 ************************************************************/
void Zoo::resizeAnimal(Animal **& animal, int &size)
{
   //create an entirely new array
   Animal **tempArray = new Animal* [size * 2]; //double capacity

   //initilized new array
   for (int i = 0; i < (size * 2); i ++)
   {
      tempArray[i] = 0;
   }

   //copy the data from old array to new array
   for (int i = 0; i < size; i++)
   {
      tempArray[i] = animal[i];
   }

   delete [] animal;

   animal = tempArray; //change pointer

   size *= 2; //update Capcity
}

/*******************************************************************
 **   void Zoo::addAge()
 **   all animals get 1 day older
 *******************************************************************/
void Zoo::addAge()
{
   //All tigers get older
   for (int i = 0; i < tigerTotal; i++)
   {
      tigerArray[i]->increaseAge(); // add one day old to each tiger
   }
   //All turtle get older
   for (int i = 0; i < turtleTotal; i++)
   {
      turtleArray[i]->increaseAge(); // add one day old to each turtle
   }
   //All penguin gets older
   for (int i = 0; i < penguinTotal; i++)
   {
      penguinArray[i]->increaseAge(); // add one day old to each tiger
   }
}

/**************************************************************************
 **    int Zoo::feedAnimals()
 **    A function ask user to choose type of food to feed the animals,
 **    back accunt is updated according to type of food. The function return
 **    user's choice as interger
 *****************************************************************************/
int Zoo::feedAnimals()
{
   Menu menu;
   menu.addString("It's feeding time!");
   menu.addString("Please pick type of food to feed your animals.");
   menu.addString("1. Cheap: half as expensive for all animals");
   menu.addString("          sickness becomes twice as likely to occur");
   menu.addString("2. Generic: behaves normally");
   menu.addString("3. Premium: twice as expensive for all animals,");
   menu.addString("   sickness becomes half as likely to occur");
   feedingChoice = menu.userInput(1, 3);

   if (feedingChoice == 1) //cheap food, 1/2 of generic food
   {
      int feedTiger = tigerTotal * Tiger().getBaseFoodCost() * .5;
      bankAccunt -= feedTiger; //sub $ from bank

      int feedTurtle = turtleTotal * Turtle().getBaseFoodCost() * .5;
      bankAccunt -= feedTurtle; //sub $ from bank

      int feedPenguin = penguinTotal * Penguin().getBaseFoodCost() * .5;
      bankAccunt -= feedPenguin;

      cout <<"After feeding your animals with cheap food, "<<endl;
      cout <<"you have $"<<bankAccunt<<" in your bank"<<endl;
      cout <<endl;

   }

   else if (feedingChoice == 2) //gerneric food
   {
      int feedTiger = tigerTotal * Tiger().getBaseFoodCost(); //feed tiger
      bankAccunt -= feedTiger; //sub $ from bank
      cout <<"You spent $"<<feedTiger<<" to feed your tiger(s)."<<endl;

      int feedTurtle = turtleTotal * Turtle().getBaseFoodCost(); //feed turtle
      bankAccunt -= feedTurtle; //sub $ from bank
      cout<<"You spent $"<<feedTurtle<<" to feed your turtle(s)."<<endl;

      int feedPenguin = penguinTotal * Penguin().getBaseFoodCost();//feed penguin
      bankAccunt -= feedPenguin;
      cout<<"You spend $"<<feedPenguin<<" to feed your penguin(s)"<<endl;

      cout <<"After feeding your animals with gerneric food, "<<endl;
      cout <<"you have $"<<bankAccunt<<" in your bank"<<endl;
      cout <<endl;
   }

   else if (feedingChoice == 3) //premium food, twice expensive
   {
      int feedTiger = tigerTotal * Tiger().getBaseFoodCost() * 2;
      bankAccunt -= feedTiger; //sub $ from bank

      int feedTurtle = turtleTotal * Turtle().getBaseFoodCost() *2;
      bankAccunt -= feedTurtle; //sub $ from bank

      int feedPenguin = penguinTotal * Penguin().getBaseFoodCost() *2;
      bankAccunt -= feedPenguin;

      cout <<"After feeding your animals with premium food, "<<endl;
      cout <<"you have $"<<bankAccunt<<" in your bank"<<endl;
      cout <<endl;
   }
   return feedingChoice;
}

/**************************************************************************
 **   Zoo:: randomEvent()
 **   Randomly select event according to type of feed.
****************************************************************************/
void Zoo::randomEvent()
{
   //random select event according type of feed
   int event = 0; //either 1, 2, 3 or 4
   int random;// to hold a random number from range of number

   if (feedingChoice == 1) // twice likely to get sick (50%)
   {
      random = (rand() % 12 )+ 1; //get number range from 1-12

      if (random >= 1 && random <= 6)
      {
         event = 1; //sick
      }
      else if (random >= 7 && random <= 8)
      {
         event = 2; //bonus
      }
      else if (random >= 9 && random <= 10)
      {
         event = 3; //born
      }
      else if (random >= 11 && random <= 12)
      {
         event = 4; //nothing happen
      }
   }

   else if (feedingChoice == 2) //equl chance (25%)
   {
      event = (rand() % 4 )+ 1;
   }

   else if (feedingChoice == 3) //less likely to be sick
   {
      random = (rand() % 24 )+ 1; //get number range from 1-24

      if (random >= 1 && random <= 3) //1/8 of chance of getting sick
      {
         event = 1; //sick
      }
      else if (random >= 4 && random <= 10)
      {
         event = 2; //bonus
      }
      else if (random >= 11 && random <= 17)
      {
         event = 3; //born
      }
      else if (random >= 18 && random <= 24)
      {
         event = 4; //nothing happen
      }
   }
   
   // what happen at each event

   if (event == 1) //animal sick
   {
      sickAnimal();
   }

   else if (event == 2) //bonus
   {
      boomTiger();
   }

   else if (event == 3) //baby born
   {
      bornBaby();
   }

   else if (event == 4) //nothing happen
   {
      noEvent();

   }
}

/************************************************************************
 **               void Zoo::sickAnimal()
 ** print a text file to let user know one of the animal is sick. Random pick
 ** a type of animal , if there is animal,delete last animal from particular
 ** type of animal array, update number of animals.
 ***************************************************************************/
void Zoo::sickAnimal()
{
   ifstream inputFile; //file stream object
   string msg;

   inputFile.open("sick.txt");
   if (inputFile)
   {
      while (inputFile >> msg)
      {
         cout <<msg <<" ";
      }
      cout <<endl;
   }
   inputFile.close(); //close file

   int dieRandom = (rand() % 3) + 1; // 1 tiger 2 turtle 3 penguin

   if (dieRandom == 1) //tiger
   {
      if (tigerTotal >= 1) //check to see if there is tiger
      {
         delete tigerArray[tigerTotal - 1]; //delete tiger obj
         tigerArray[tigerTotal - 1] = 0; //put it to zero

         tigerTotal -= 1; //a tiger die, decrease # of tiger by 1
         cout << "A tiger say good bye!" <<endl;
      }
      else
      {
         cout << "my mistake, no animal die today"<<endl;
      }
   }

   else if (dieRandom == 2) //turtle is sick
   {
      if (turtleTotal >= 1) //check to see if there is turtle
      {
         delete turtleArray[turtleTotal - 1];
         turtleArray[turtleTotal - 1] = 0; //put it back to zero
         turtleTotal -= 1; //a turtle die, decrease # of turtle by 1
         cout << "Goodbye! turtle." <<endl;
      }
      else
      {
         cout << "my mistake, no animal die today"<<endl;
      }
   }

   else if (dieRandom == 3) //Penguin
   {
      if (penguinTotal >= 1) //check to see if there is penguin
      {
         delete penguinArray[penguinTotal - 1];
         penguinArray[penguinTotal - 1] = 0; //put it back to zero
         penguinTotal -= 1; //a penguin die, decrease # of penguin by 1
         cout << "A penguin pass away" <<endl;
      }
      else
      {
         cout << "my mistake, no animal die today"<<endl;
      }
   }
   cout <<endl;
}

/************************************************************************
 **               void Zoo::boomTiger()
 ** print a text file to let user know it's national tiger's day, Each tiger
 ** will earn $250, update bank accout
 ***************************************************************************///boom tiger
void Zoo::boomTiger()
{
   ifstream inputFile; //file stream object
   string msg;

   inputFile.open("boom.txt");
   if (inputFile)
   {
      while (inputFile >> msg)
      {
         cout <<msg <<" ";
      }
      cout <<endl;
   }

   inputFile.close(); //close file

   int tigerBonus = 0;
   tigerBonus = tigerTotal * 250; //each tiger get $250 bonus
   bankAccunt += tigerBonus; // add the bonus to bank account
   cout <<"You earn $"<<tigerBonus<<" today!" <<endl;
   cout <<"You have $"<<bankAccunt<<" in your back accout."<<endl;
   cout <<endl;
}

/************************************************************************
 **               void Zoo::bornBaby()
 ** print a text file to let user know one of the animal is going to have baby.
 ** Check to see if there is any adult animal old engouh to have baby.
 **  If so, randomly pick a adult animal to have baby.
 ***************************************************************************/
void Zoo::bornBaby()
{
   ifstream inputFile; //file stream object
   string msg;

   inputFile.open("born.txt");
   if (inputFile)
   {
      while (inputFile >> msg)
      {
         cout <<msg <<" ";
      }
      cout <<endl;
   }

   inputFile.close(); //close file

   //pick which animal will have baby!!!!
   int bornChoice = 0; // 1 Tiger, 2 Turtle, 3 Penguin

   //check to see if there is adult animals
   bool tigerAdult = adultAnimal(tigerArray, tigerTotal);
   bool turtleAdult = adultAnimal(turtleArray, turtleTotal);
   bool penguinAdult = adultAnimal(penguinArray, penguinTotal);

   if ( !tigerAdult && !turtleAdult && !penguinAdult) //if no adults
   {
      cout <<" Oops! There is no adult animal to make babies."<<endl;
   }

   if ( tigerAdult && turtleAdult && penguinAdult) //all types have adults
   {
      bornChoice = (rand() % 3) + 1;
   }

   if ( tigerAdult && turtleAdult && !penguinAdult )
   {
      int random = rand() % 2; // 0 tiger, 1 turtle
      if ( random == 0)
      {
         bornChoice = 1; //tiger
      }
      else
      {
         bornChoice = 2; //turtle
      }
   }

   if ( tigerAdult && !turtleAdult && penguinAdult )
   {
      int random = rand() % 2; // 0 tiger, 1 penguin
      if ( random == 0)
      {
         bornChoice = 1; //tiger
      }
      else
      {
         bornChoice = 3; //penguin
      }
   }

   if ( tigerAdult && !turtleAdult && !penguinAdult )
   {
         bornChoice = 1; //tiger
   }

   if ( !tigerAdult && turtleAdult && penguinAdult )
   {
      int random = rand() % 2; // 0 turtle, 1 penguin
      if ( random == 0)
      {
         bornChoice = 2; //turtle
      }
      else
      {
         bornChoice = 3; //penguin
      }
   }

   if ( !tigerAdult && turtleAdult && !penguinAdult )
   {
      bornChoice = 2; //turtle
   }

   if ( !tigerAdult && !turtleAdult && penguinAdult )
   {
      bornChoice = 3; //penguin
   }

   //baby animail born!
   if (bornChoice == 1) //Hello tiger!
   {
      cout<<"One of your adult tiger is going to have 1 tiger baby."<<endl;

      tigerTotal++; //increase #tiger by one

      if (!checkCapacity(tigerCapacity,tigerTotal)) //check capacity
      {
         resizeAnimal(tigerArray, tigerCapacity); //resize if need to
      }
      
      tigerArray[tigerTotal - 1] = new Tiger(0); //set age 0

      cout <<"You have "<<tigerTotal<<" tiger(s) in the zoo."<<endl;
      cout <<endl;
   }

   else if (bornChoice == 2) //Hello turtle!
   {
      cout <<"One of your adult turtle is going to have"<<endl;
      cout <<Turtle().getNumOfBabies()<<" babies."<<endl;

      for (int i = 0; i <Turtle().getNumOfBabies(); i++)
      {
         turtleTotal ++;
         if (!checkCapacity(turtleCapacity, turtleTotal)) //check capacity
         {
            resizeAnimal(turtleArray, turtleCapacity); //make it bigger
         }

         turtleArray[turtleTotal - 1 ] = new Turtle(0);
      }

      cout <<"You have "<<turtleTotal<<" turtle(s) in the zoo." <<endl;
      cout <<endl;
   }

   else if (bornChoice == 3) //Hello Penguin
   {
      cout <<"One of your adult penguin is going to have" <<endl;
      cout <<Penguin().getNumOfBabies()<<" babies"<<endl;

      for ( int i = 0; i < Turtle().getNumOfBabies(); i++)
      {
         if (!checkCapacity(penguinCapacity, penguinTotal))
         {
            resizeAnimal(penguinArray, penguinCapacity);
         }
         penguinArray[penguinTotal - 1 ] = new Penguin(0);
      }
      cout << "You have "<<penguinTotal<<" penguins in the zoo."<<endl;
      cout <<endl;

   }
}

/*********************************************************************
 **              bool Zoo::adultAnimal(Animal **array, int numAnimal)
 ** Description:a function take pointer of animal array and number of
 ** animal as parameter, and check the number of adult animals,
 ** return bool. (True = has adult)
 *************************************************************/
bool Zoo::adultAnimal(Animal **array, int numAnimal)
{
   int numAdult = 0; //hold number of adult animals

   for (int i = 0; i < numAnimal; i ++)
   {
      if (array[i]->getAge() >= 3) //adult age >= 3 days
      {
         numAdult++;
      }
   }
   if (numAdult > 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/************************************************************************
 **               void Zoo::noEvent()
 ** print a text file to let user know no event happen today.
 ***************************************************************************/
void Zoo::noEvent()
{
   ifstream inputFile; //file stream object
   string msg;

   inputFile.open("nothing.txt");
   if (inputFile)
   {
      while (inputFile >> msg)
      {
         cout <<msg <<" " ;
      }
      cout <<endl;
   }

   inputFile.close(); //close file
   cout<<endl;
}

/*********************************************************************
 **               void Zoo::payOff()
 ** Description: calculate the payoff of each type of animal at the end of the
 **             day and update bank accout.
 *********************************************************************/
void Zoo::payOff()
{
   bankAccunt += tigerTotal * Tiger().getPayOff();
   bankAccunt += turtleTotal * Turtle().getPayOff();
   bankAccunt += penguinTotal * Penguin().getPayOff();

   cout<<"Payoff: "<<endl;
   cout <<"Tiger: "<<tigerTotal * Tiger().getPayOff()<<endl;
   cout <<"Turtle: "<<turtleTotal * Turtle().getPayOff()<<endl;
   cout <<"Penguin: "<<penguinTotal * Penguin().getPayOff()<<endl;
   cout <<"Bank balance: "<<bankAccunt<<endl;
   cout <<endl;
}
/*********************************************************************
 **              void Zoo::buyAdultAnimal()
 ** Description: A function ask if user wants to buy One adult animal at the end
 **              of the day, and update number of animals, bank account dpends
 **              on user choice.
 *********************************************************************/
void Zoo:: buyAdultAnimal()
{
   Menu menu;
   menu.addString("Would you like to buy an adult animal?");
   menu.addString("1 Yes");
   menu.addString("2 NO ");
   int buy = menu.userInput(1, 2);
   if (buy == 1)
   {
      Menu submenu;
      submenu.addString("Which adult animal would you like to buy? ");
      submenu.addString(" 1. Tiger");
      submenu.addString(" 2. Turtle");
      submenu.addString(" 3. Penguin");
      int whichAnimal = submenu.userInput(1, 3);

      if (whichAnimal == 1) //Tiger
      {
         cout<<"Thanks for buying 1 adult tiger." <<endl;

         bankAccunt -= Tiger().getCost(); //pay for tiger

         tigerTotal ++; //add 1 tiger

         if (!checkCapacity(tigerCapacity,tigerTotal)) //check capacity
         {
            resizeAnimal(tigerArray, tigerCapacity);
         }

         tigerArray[tigerTotal - 1 ] = new Tiger(3); //add 1 adult tiger age 3
      }

      else if (whichAnimal == 2) //Turtle
      {
         cout <<"Thanks for buying 1 adult turtle." <<endl;

         bankAccunt -= Turtle().getCost(); //pay for turtle

         turtleTotal ++; //add 1 turtle

         if (!checkCapacity(turtleCapacity,turtleTotal)) //check capacity
         {
            resizeAnimal(turtleArray, turtleCapacity);
         }

         turtleArray[turtleTotal - 1] = new Turtle(3); //add 1 adult turtle age 3
      }

      else if (whichAnimal == 3)//Penguin
      {
         cout <<"Thanks for buying 1 adult penguin."<<endl;

         bankAccunt -= Penguin().getCost(); //pay for penguin

         penguinTotal ++; //add 1 penguin

         if (!checkCapacity(penguinCapacity,penguinTotal)) //check capacity
         {
            resizeAnimal(penguinArray, penguinCapacity);
         }
         penguinArray[penguinTotal - 1 ] = new Penguin(3); //add 1 adult penguin 
      }
   }
   cout<<"You have;" <<endl;
   cout <<tigerTotal<<" tiger(s)"<<endl;
   cout <<turtleTotal<<" turtle(s)"<<endl;
   cout <<penguinTotal<<" penguin(s)"<<endl;
   cout <<"$"<<bankAccunt<<" in your bank account."<<endl;
   cout <<endl;
}
/*********************************************************************
 **              int Zoo::playAgain()
 ** Description: a function ask if user wants to start another day and return
 **              user choice as integer.
 *********************************************************************/
int Zoo::playAgain()
{
   Menu menu;
   menu.addString("Would you like to start another day? ");
   menu.addString(" 1. Yes");
   menu.addString(" 2. No ");

   return menu.userInput(1, 2);
}

/**************************************************************************
 **       void Zoo::deleteArray()
 ** delete dynamically allocate arrays of different animals at the end of the
 ** program.
**************************************************************************/
void Zoo::deleteArray()
{

   for (int i = 0; i < tigerCapacity; i++) //delete tigerArray at the end
   {
      if (tigerArray[i] != 0)   //every new needs delete
      {
         delete tigerArray[i];
      }
   }
   delete []tigerArray;


   for (int i = 0; i < turtleCapacity; i++) //delete tutleArray at the end
   {
      if (turtleArray[i] != 0)
      {
         delete turtleArray[i];
      }
         delete []turtleArray;
   }

   for (int i = 0; i < penguinCapacity; i++) //delete penguinArray at the end
   {
      if ( penguinArray[i] != 0)
      {
         delete penguinArray[i];
      }
   }
   delete []penguinArray;

   cout <<"delete array call"<<endl;
   
}

//default destructor
Zoo::~Zoo()
{
   /*{
      for (int i = 0; i < tigerCapacity; i++) //delete tigerArray at the end
      {
            delete tigerArray[i];
      }
      delete []tigerArray;


      for (int i = 0; i < turtleCapacity; i++) //delete tutleArray at the end
      {
                     delete turtleArray[i];
      }
         delete []turtleArray;

      for (int i = 0; i < penguinCapacity; i++) //delete penguinArray at the end
      {
            delete penguinArray[i];
      }
      delete []penguinArray;
      }*/
   cout <<"Destructor Here"<<endl;
}

