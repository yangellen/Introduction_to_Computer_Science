/****************************************************************************
 **  Ellen Yang
 **  ComputerRoom.hpp
 **  This is the ComputerRoom class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef ComputerRoom_hpp
#define ComputerRoom_hpp

#include "Space.hpp"


class ComputerRoom: public Space
{
   public:
      ComputerRoom();
      void randomEvent();

      void roomIntro();
};

#endif
