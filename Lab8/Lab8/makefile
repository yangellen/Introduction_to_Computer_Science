#Makefile for Ellen Yang
#Lab8_Yang_Ellen_.zip

OBJS   = main.o binarySearch.o simpleSearch.o bubbleSort.o Menu.o isDigit.o
SOURCE   = main.cpp binarySearch.cpp simpleSearch.cpp bubbleSort.cpp Menu.cpp isDigit.cpp
HEADER   = binarySearch.hpp simpleSearch.hpp bubbleSort.hpp Menu.hpp isDigit.hpp
OUT   = output
CC    = g++
FLAGS    = -g -c -std=c++0x
LFLAGS    =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

binarySearch.o: binarySearch.cpp
	$(CC) $(FLAGS) binarySearch.cpp

simpleSearch.o: simpleSearch.cpp
	$(CC) $(FLAGS) simpleSearch.cpp

bubbleSort.o: bubbleSort.cpp
	$(CC) $(FLAGS) bubbleSort.cpp

Menu.o: Menu.cpp
	$(CC) $(FLAGS) Menu.cpp

isDigit.o: isDigit.cpp
	$(CC) $(FLAGS) isDigit.cpp


clean:
	rm -f $(OBJS) $(OUT)
