/****************************************************************************
 **  Ellen Yang
 **  BathRoom.hpp
 **  This is the BathRoom class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef BathRoom_hpp
#define BathRoom_hpp

#include "Space.hpp"


class BathRoom: public Space
{
   public:
      BathRoom();
      void randomEvent();
      void roomIntro();
};

#endif
