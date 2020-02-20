/****************************************************************************
 **  Ellen Yang
 **  MasterRoom.hpp
 **  This is the MasterRoom class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef MasterRoom_hpp
#define MasterRoom_hpp

#include "Space.hpp"


class MasterRoom: public Space
{
   public:
      MasterRoom();
      void randomEvent();
      void roomIntro();

};

#endif
