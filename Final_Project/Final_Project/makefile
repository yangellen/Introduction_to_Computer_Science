#Ellen Yang
#FinalProject_Yang_Ellen.zip

OBJS	= main.o MasterRoom.o ComputerRoom.o KidsRoom.o BathRoom.o Kitchen.o PlayRoom.o Space.o Game.o Menu.o isDigit.o
SOURCE	= main.cpp MasterRoom.cpp ComputerRoom.cpp KidsRoom.cpp BathRoom.cpp Kitchen.cpp PlayRoom.cpp Space.cpp Game.cpp Menu.cpp isDigit.cpp
HEADER	= MasterRoom.hpp ComputerRoom.hpp KidsRoom.hpp BathRoom.hpp Kitchen.hpp PlayRoom.hpp Space.hpp Game.hpp Menu.hpp isDigit.hpp
OUT	= output
CC	 = g++
FLAGS	 = -g -c -std=c++0x
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

MasterRoom.o: MasterRoom.cpp
	$(CC) $(FLAGS) MasterRoom.cpp 

ComputerRoom.o: ComputerRoom.cpp
	$(CC) $(FLAGS) ComputerRoom.cpp 

KidsRoom.o: KidsRoom.cpp
	$(CC) $(FLAGS) KidsRoom.cpp 

BathRoom.o: BathRoom.cpp
	$(CC) $(FLAGS) BathRoom.cpp 

Kitchen.o: Kitchen.cpp
	$(CC) $(FLAGS) Kitchen.cpp 

PlayRoom.o: PlayRoom.cpp
	$(CC) $(FLAGS) PlayRoom.cpp 

Space.o: Space.cpp
	$(CC) $(FLAGS) Space.cpp 

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp 

Menu.o: Menu.cpp
	$(CC) $(FLAGS) Menu.cpp 

isDigit.o: isDigit.cpp
	$(CC) $(FLAGS) isDigit.cpp 


clean:
	rm -f $(OBJS) $(OUT)