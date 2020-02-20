/*********************************************************************
 ** Program name: Lab2_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 2, 2018
 ** Description:  the main file that contains main function that reads a file
 **               filled with letters, count the letter frequencies in the
 **               file, and write the results to a new file.
 *********************************************************************/
#include <iostream>
#include <fstream> //needed to use files
#include <string>

#include "count_letters.hpp"
#include "output_letters.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
   ifstream inputFile; //file stream object
   string fileName; //holds the user entered file name
   int letterArray[26]; // array that holds the frequencies of letters

   //prompt the user to enter the data file name
   cout <<" Please enter the file you would like to read" <<endl;
   getline(cin, fileName);

   inputFile.open(fileName);// open the input file

   if (!inputFile) //can't open file
   {
      cout << "File open error!" <<endl;

      return 0;
   }
   else //start reading, counting and store
   {
      count_letters(inputFile, letterArray);
   }

   inputFile.close(); //close the file

   return 0;
}
