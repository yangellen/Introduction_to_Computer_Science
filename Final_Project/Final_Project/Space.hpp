/****************************************************************************
**  Ellen Yang
**  Space.hpp
**  This is the Space class specification file. This is the abstrate class for
**  6 spaces in this game. The class contain 4 Space pointers to different
**  directions. The class also has protectd varialbes, protected friend class,
**  public pure functions, vitural functions to help player go through each
**  room and play the game.
****************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Game.hpp"


using std::string;

class Space
{
   protected:
      Space *top;
      Space *right;
      Space *left;
      Space *bottom;

      string spaceName; //name of space
      int energylost; //engergy lost during game
      int coffee; //number of coffee

      friend class Game;

   public:
      Space();
      virtual ~Space();

      virtual void randomEvent() = 0; //random event happen in different room

      virtual string getName()
      {return spaceName;}

      virtual void roomIntro() = 0; //introduction of each room

      virtual int getEnergyLost()
      {return energylost;}

      virtual int getCoffee()
      {return coffee;}

};
#endif
