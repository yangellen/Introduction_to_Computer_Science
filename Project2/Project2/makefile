#makefile for Ellen Yang
#Project_2_Yang_Ellen.zip

output: Menu.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o main.o isDigit.o
	g++ -std=c++0x Menu.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o main.o isDigit.o -o output

Menu.o: Menu.cpp
	g++ -std=c++0x -c Menu.cpp

Animal.o: Animal.cpp
	g++ -std=c++0x -c Animal.cpp

Penguin.o: Penguin.cpp
	g++ -std=c++0x -c Penguin.cpp

Tiger.o: Tiger.cpp
	g++ -std=c++0x -c Tiger.cpp

Turtle.o: Turtle.cpp
	g++ -std=c++0x -c Turtle.cpp

Zoo.o: Zoo.cpp
	g++ -std=c++0x -c Zoo.cpp

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

isDigit.o: isDigit.cpp
	g++ -std=c++0x -c isDigit.cpp

clean:
	rm -f *.o output
