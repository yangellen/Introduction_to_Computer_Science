#Lab10_Yang_Ellen.zip
#makefile

OBJS	= FibonacciNR.o FibonacciR.o main.o
SOURCE	= FibonacciNR.cpp FibonacciR.cpp main.cpp
HEADER	= FibonacciNR.hpp FibonaccR.hpp
OUT	= output
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

FibonacciNR.o: FibonacciNR.cpp
	$(CC) $(FLAGS) FibonacciNR.cpp 

FibonacciR.o: FibonacciR.cpp
	$(CC) $(FLAGS) FibonacciR.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)
