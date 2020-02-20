
#makefile for Ellen Yang
#Project3_Yang_Ellen.zip

objects = main.o Menu.o isDigit.o Game.o Character.o Barbarian.o Die.o Vampire.o BlueMen.o Medusa.o HarryPotter.o

output: $(objects)
	g++ -std=c++0x $(objects) -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -c Menu.cpp

isDigit.o: isDigit.cpp
	g++ -std=c++0x -c isDigit.cpp

Game.o: Game.cpp
	g++ -std=c++0x -c Game.cpp

Character.o: Character.cpp
	g++ -std=c++0x -c Character.cpp

Barbarian.o: Barbarian.cpp
	g++ -std=c++0x -c Barbarian.cpp

Die.o: Die.cpp
	g++ -std=c++0x -c Die.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++0x -c Vampire.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++0x -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++0x -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++0x -c HarryPotter.cpp

clean:
	rm *.o output
