/*********************************************************************
 ** Program name: Leb2_Yang_Ellen.zip
 ** Author:       Ellen Yang
 ** Date:         Oct 3, 2018
 ** Description:  The output_letters.hpp is the implementation file,
 **               which takes an output file stream varialbe, and a pointer to
 **               array of integers that contains frequences of letters.
 **               The function asks user for filename the user would like to
 **               output to, then ouputs the frequencies of letters to the
 **               output file.
 *********************************************************************/
#include "output_letters.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void output_letters(ofstream &outputFile, int* letterArray)
{
   string fileName;
   char letter;

   cout <<"Please enter the filename you wish to write to." <<endl;
   getline(cin, fileName);

   outputFile.open(fileName);

   if (outputFile.fail())
   {
      cout << "Invalid filename!" <<endl;
   }

   for (int i = 0; i <26; i++)
   {
      letter = 'a' + i;
      outputFile <<letter << ":" << letterArray[i]<<endl;
   }
   outputFile.close();
}
