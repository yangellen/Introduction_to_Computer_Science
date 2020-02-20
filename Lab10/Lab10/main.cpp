/*************************************************************************
**  main.cpp for Lab 10
**  Ellen Yang
**  11/26/2018
**  This is the main file for lab 10, which tests the recursive and non
**  recursive functions, measures their execution time .
***************************************************************************/
#include <ctime>
#include <ratio>
#include <chrono>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
#include <iostream>

using std::cout;
using std::endl;
using namespace std::chrono; 

int main()
{
   int n = 1;

   //recursive function

   while (n < 47)
   {
      cout <<"Calling Fibonacci recursive function"<<endl;

      FibonacciR recursive(n); //calling recursive function
      
      high_resolution_clock::time_point t1 = high_resolution_clock::now();

      recursive.PrintFibonacci();

      //time = clock() - time; //stop the timer
      high_resolution_clock::time_point t2 = high_resolution_clock::now();

      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
      n++;
      cout <<"Time to execute: "<<time_span.count()<<" second."<<endl;
      cout <<endl;
   }

   n = 1;

   while (n < 47)
   {
      //clock_t time; // time variable use to hold start time and end time
      cout <<"Calling Fibonacci iterative function"<<endl;


      FibonacciR iterative(n); //calling recursive function
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      iterative.PrintFibonacci();
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
      //stop the timer

      n++;
      cout <<"Time to execute: "<<time_span.count()<<" second."<<endl;
      cout <<endl;
   }

   return 0;
}
