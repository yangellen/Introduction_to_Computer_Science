/*********************************************************************
 ** iteration.hpp
 ** Ellen Yang
 ** 11/26/2018
 ** This is the implantation file for FibonacciNRclass, which use a
 ** uses iteration to calculate fibonacci numbers. This file includes the class,
 ** variable and function declarations.
 ** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *********************************************************************/
#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR()
{
}

FibonacciNR::FibonacciNR(const int &n):n_(&n)
{
}

FibonacciNR::~FibonacciNR()
{
}

int FibonacciNR::Fibonacci(const int &n)
{
   int first = 0;
   int second = 1;
   int counter = 2 ;

   while(counter < n)
   {
      int temp = second;
      second = first + second;
      first = temp;
      ++counter;
   }
   if(n == 0)
      return 0;
   else
      return first + second;
}

void FibonacciNR::PrintFibonacci()
{
   const int result = Fibonacci(*n_);
   std::cout << *n_ << "th fibonaci number: " << result << std::endl;
}
