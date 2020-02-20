/*********************************************************************
 ** iteration.hpp
 ** Ellen Yang
 ** 11/26/2018
 ** This is the specification file for FibonacciNR class, which use a
 ** uses iteration to calculate fibonacci numbers. This file includes the class,
 ** variable and function declarations.
 ** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *********************************************************************/

#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR
{
   public:
      FibonacciNR(const int &n);
      virtual ~FibonacciNR();
      void PrintFibonacci();
   private:
      FibonacciNR();
      int Fibonacci(const int &n);
      const int* n_;
};

#endif
