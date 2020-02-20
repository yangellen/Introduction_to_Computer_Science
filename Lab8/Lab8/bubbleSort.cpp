/*********************************************************************
 ** Ellen Yang
 ** bubbleSort.cpp
 ** 11/16/18.
 ** This function takes Vector of integers as the parameter and use bubble sort
 ** algorithm to sort vector of integers in ascending order and output the
 ** sorted values to the output files. It also print the sorted vaules in each
 ** file onto the screen. The function return the filename that was use to store
 ** the sorted numbers.

 <The bubble sort algorthm was based on textbook "Starting Out with C++ .">
 ***********************************************************************/
#include "bubbleSort.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "binarySearch.hpp"
#include "Menu.hpp"

using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


string sortVector(vector<int> &array)
{
   ofstream outputFile;
   string fileName;

   cout <<"Please enter the filename you wish to write to." <<endl;
   cin >>fileName; 

   outputFile.open(fileName);

   if (outputFile.fail())
   {
      cout << "Invalid filename!" <<endl;
   }

   //sort vector and store number
   int temp;
   bool madeAswap;

   do
   {
      madeAswap = false;
      for (int i = 0; i < (array.size() - 1); i++)
      {
         if (array[i] > array[i + 1])
         {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            madeAswap = true;
         }
      }
   }while (madeAswap);

   cout <<"Sorted array: ";
   
   for (int i = 0; i < array.size(); i++)
   {
      outputFile<<array[i];
      cout <<array[i]<<" ";
   }
   cout<<endl;
   
   outputFile.close();

   return fileName; 
}
