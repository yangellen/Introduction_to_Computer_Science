#makefile for Ellen Yang
#Project1_Yang_Ellen_.zip

output: main.o Ant.o Menu.o
	g++ -std=c++0x main.o Ant.o Menu.o -o output
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++0x -c Ant.cpp
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp

clean:
	rm *.o output 
