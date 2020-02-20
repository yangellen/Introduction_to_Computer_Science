#makefile for Ellen Yang
#Lab9_Yang_Ellen.zip


OBJS   = isDigit.o main.o Menu.o Queue.o Stack.o
SOURCE   = isDigit.cpp main.cpp Menu.cpp Queue.cpp Stack.cpp
HEADER   = isDigit.hpp Menu.hpp Queue.hpp Stack.hpp
OUT   = output
CC    = g++
FLAGS    = -g -c --std=c++0x
LFLAGS    =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

isDigit.o: isDigit.cpp
	$(CC) $(FLAGS) isDigit.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Menu.o: Menu.cpp
	$(CC) $(FLAGS) Menu.cpp

Queue.o: Queue.cpp
	$(CC) $(FLAGS) Queue.cpp

Stack.o: Stack.cpp
	$(CC) $(FLAGS) Stack.cpp


clean:
	rm -f $(OBJS) $(OUT)
