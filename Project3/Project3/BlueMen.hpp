/*********************************************************************
 **             Ellen Yang
 **             BlueMen.hpp
 **             10/28/18.
 ** This is class BlueMen specification file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen: public Character
{
   public:
      BlueMen();
      BlueMen(int armor, int strength);

      int attack();
      int defense();

};

#endif 
