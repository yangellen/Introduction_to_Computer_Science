/*********************************************************************
 **             Ellen Yang
 **             Vampire.hpp
 **             10/28/18.
 ** This is class Vampire specification file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire: public Character
{
public:
   Vampire();
   Vampire(int armor, int strength);

   int attack();
   int defense();

   bool charm(); 

};

#endif
