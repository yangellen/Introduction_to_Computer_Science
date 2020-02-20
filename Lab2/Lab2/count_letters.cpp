/*********************************************************************
 ** Program name: Leb2_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 3, 2018
 ** Description:  the count_letters.hpp is the implementation file,
 **               which takes an input file stream varialbe, and a pointer to
 **               array of integers. The function reads the paragraph string
 **               from the input file stream, counts the letter frequencies of
 **               that paragraph, and store the frequencies in the array
 *********************************************************************/
#include "count_letters.hpp"
#include "output_letters.hpp"
#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;


void count_letters(ifstream &file, int* letterArray)
{
   string input; //variable needed to read file
   char readChar = ' '; //use to check the character
   ofstream outputFile; //use to write

   //fill array with 0
   for (int i = 0; i < 26; i++)
   {
      letterArray[i] = 0;
   }
   while(!file.eof())
   {
      file.get(readChar); //read each character in file

      if (readChar >= 'A' && readChar <= 'Z') //all capital letters
      {
         letterArray[readChar - 'A']++; //count all capital letters
      }
      else if (readChar >= 'a' && readChar <= 'z') //all small letters
      {
         letterArray[readChar - 'a']++; //count all small letters
      }
      if (readChar == '\n')
      {
         output_letters(outputFile, letterArray);//store file

         for (int i = 0; i < 26; i++) //reset array
         {
            letterArray[i] = 0;
         }
      }
   }
   if (file.eof())
   {
      output_letters(outputFile, letterArray);
   }
}

