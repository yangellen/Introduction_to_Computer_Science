/**********************************************************************
**     Ellen Yang
**     Nov. 16, 2018
**     Lab8 Searching and Sorting program that read values from files, do
**     do simple search, bubble sorting, and binary search
************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "Menu.hpp"
#include "simpleSearch.hpp"
#include "bubbleSort.hpp"
#include "binarySearch.hpp"

using std::cout;
using std::vector;
using std::ifstream;
using std::endl;



int main()
{
   //read values from files and store in vector
   vector<int>num; //create vectors to hold the numbers in txt files
   vector<int>early;
   vector<int>middle;
   vector<int>end;

   ifstream file1; //create ifstream obj
   ifstream file2;
   ifstream file3;
   ifstream file4;

   file1.open("num.txt"); //open the files
   file2.open("early.txt");
   file3.open("middle.txt");
   file4.open("end.txt");

   int number; //use to read the file

   if (file1) //num.txt
   {
      //read the file and store in vector
      while (file1 >> number) //if a value was read
      {
         num.push_back(number); //store in vector
      }

      //close the file
      file1.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (file2) //early.txt
   {
      //read the file and store in vector
      while (file2 >> number) //if a value was read
      {
         early.push_back(number); //store in vector
      }

      //close the file
      file2.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (file3) //middle.txt
   {
      //read the file and store in vector
      while (file3 >> number) //if a value was read
      {
         middle.push_back(number); //store in vector
      }

      //close the file
      file3.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (file4) //end.txt
   {
      //read the file and store in vector
      while (file4 >> number) //if a value was read
      {
         end.push_back(number); //store in vector
      }

      //close the file
      file4.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   //simple search
   Menu menu1;
   int targetValue = menu1.introMenu(); //ask for target value

   simpleSearch(num, targetValue, "num.txt");
   simpleSearch(early, targetValue, "early.txt");
   simpleSearch(middle, targetValue, "mid.txt");
   simpleSearch(end, targetValue, "end.txt");

   //bubble sort
   cout <<"Start sort"<<endl;

   string sort1 = sortVector(num);
   string sort2 = sortVector(early);
   string sort3 = sortVector(middle);
   string sort4 = sortVector(end);

   //binary search
   //read values from files and store in vector
   vector<int>newNum; //create vectors to hold the numbers in txt files
   vector<int>newEarly;
   vector<int>newMiddle;
   vector<int>newEnd;

   ifstream newfile1; //create ifstream obj
   ifstream newfile2;
   ifstream newfile3;
   ifstream newfile4;

   newfile1.open(sort1); //open the files
   newfile2.open(sort2);
   newfile3.open(sort3);
   newfile4.open(sort4);

   if (newfile1) //num.txt
   {
      //read the file and store in vector
      while (newfile1 >> number) //if a value was read
      {
         newNum.push_back(number); //store in vector
      }

      //close the file
      newfile1.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (newfile2) //early.txt
   {
      //read the file and store in vector
      while (newfile2 >> number) //if a value was read
      {
         newEarly.push_back(number); //store in vector
      }

      //close the file
      newfile2.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (newfile3) //middle.txt
   {
      //read the file and store in vector
      while (newfile3 >> number) //if a value was read
      {
         newMiddle.push_back(number); //store in vector
      }

      //close the file
      newfile3.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   if (newfile4) //end.txt
   {
      //read the file and store in vector
      while (newfile4 >> number) //if a value was read
      {
         newEnd.push_back(number); //store in vector
      }

      //close the file
      newfile4.close();
   }
   else
   {
      cout<<"Error, unable to open file"<<endl;
   }

   Menu menu2;
   targetValue = menu2.introMenu(); //ask for target value

   binarySearch(num, targetValue, sort1);
   binarySearch(early, targetValue,sort2);
   binarySearch(middle, targetValue, sort3);
   binarySearch(end, targetValue, sort4);


   return 0;
}
