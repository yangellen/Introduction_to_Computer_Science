/****************************************************************************
 **  Ellen Yang
 **  KidsRoom.hpp
 **  This is the KidsRoom class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef KidsRoom_hpp
#define KidsRoom_hpp

#include "Space.hpp"


class KidsRoom: public Space
{
   public:
      KidsRoom();
      void randomEvent();
      void roomIntro();
};

#endif
