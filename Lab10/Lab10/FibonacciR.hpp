/*********************************************************************
 ** FibonacciR.hpp
 ** Ellen Yang
 ** 11/26/2018
 ** This is the specification file for a FibonacciR
 ** class, which use a recursive function to calculate fibonacci
 ** numbers. This file includes the class, variable and function declarations.
 ** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *********************************************************************/

#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR
{
   private:
      FibonacciR();
      int Fibonacci(const int &n);
      const int *n_;

   public:
      FibonacciR(const int &n);
      virtual ~FibonacciR();
      void PrintFibonacci();

};

#endif
