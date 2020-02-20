/****************************************************************************
 **  Ellen Yang
 **  PlayRoom.hpp
 **  This is the PlayRoom class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef PLAYROOM_HPP
#define PLAYROOM_HPP
#include "Space.hpp"


class PlayRoom: public Space
{
   public:
      PlayRoom();
      void randomEvent();
      void roomIntro();
};


#endif
