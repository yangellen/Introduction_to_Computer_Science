/****************************************************************************
 **  Ellen Yang
 **  Kitchen.hpp
 **  This is the Kitchen class specification file. This is the child class
 **  of Space class in this game. The class has it's own introduction and
 **  random events.
 ****************************************************************************/

#ifndef Kitchen_hpp
#define Kitchen_hpp

#include "Space.hpp"

class Kitchen: public Space
{
   public:
      Kitchen();
      void randomEvent();
      void roomIntro();

};

#endif /* Kitchen_hpp */
