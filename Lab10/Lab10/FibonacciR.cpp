/*********************************************************************
 ** FibonacciR.cpp
 ** Ellen Yang
 ** 11/26/2018
 ** This is the implantation  file for a FibonacciR class, which use a
 ** recursive function to calculate fibonacci numbers. This file includes
 ** the class, variable and function declarations.
 ** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *********************************************************************/

#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR()
{
}

FibonacciR::FibonacciR(const int &n):n_(&n)
{
}

FibonacciR::~FibonacciR()
{
}

int FibonacciR::Fibonacci(const int &n)
{
   if(n==0)
      return 0;
   else if(n==1)
      return 1;
   return Fibonacci(n-1) + Fibonacci(n-2);
}

void FibonacciR::PrintFibonacci()
{
   unsigned long long int FibonaciNum=Fibonacci(*n_);
   std::cout << *n_ << "the fibonaci number: "<< FibonaciNum << std::endl;
}
