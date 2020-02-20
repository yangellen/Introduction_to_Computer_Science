/*********************************************************************
 ** Program name: Animal hpp
 ** Author:       Ellen Yang
 ** Date:         Oct 15, 2018
 ** Description:  Animal hpp is a animal class specification. It is the
 **               base class for other animals. It has member variable of
 **               age, cost, numOfBabies, baseFoodCost and payOff.
 *********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal //Base class
{
   protected:
      int age; //adult if age >= 3 days, baby if age < 3 days
      int cost; //cost of animals 
      int numOfbabies; //number of babies of animal
      int baseFoodCost; // food cost of animal $10
      int payOff; //payoff per day for animal
   
   public:
      Animal();//default constructor
      Animal (int age); //constructor that takes age as parameters
      virtual ~Animal();
   
      virtual int getAge();
      virtual int getCost();
      virtual int getNumOfBabies();
      virtual int getBaseFoodCost();
      virtual int getPayOff();
      virtual void increaseAge();
};


#endif
