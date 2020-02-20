#Makefile for Ellen Yang
#Lab3_Yang_Ellen_.zip

output: Die.o  Game.o  isDigit.o  LoadedDie.o  main.o
	g++ -std=c++0x Die.o  Game.o  isDigit.o  LoadedDie.o  main.o -o output
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
Die.o: Die.cpp Die.hpp
	g++ -std=c++0x -c Die.cpp
Game.o: Game.cpp Game.hpp
	g++ -std=c++0x -c Game.cpp
isDigit.o:isDigit.cpp isDigit.hpp
	g++ -std=c++0x -c isDigit.cpp
LoadedDie.o:LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++0x -c LoadedDie.cpp

clean:
	rm *.o output


	