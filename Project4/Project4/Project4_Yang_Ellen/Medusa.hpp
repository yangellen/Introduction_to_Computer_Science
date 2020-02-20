/*********************************************************************
 **             Ellen Yang
 **             Medusa.hpp
 **             10/29/18.
 ** This is class Medusa specification file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa: public Character
{
   public:
      Medusa();
      Medusa(string name,string type, int armor, int strength);

   int attack();
   int defense();

};

#endif
