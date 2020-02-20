/*********************************************************************
 **             Ellen Yang
 **             Barbarian.hpp
 **             10/25/18.
 ** This is class Barbarian specification file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character
{
   public:
      Barbarian();
      Barbarian(string name, string type, int armor, int strength);
   
      int attack();
      int defense();
   
};

#endif
