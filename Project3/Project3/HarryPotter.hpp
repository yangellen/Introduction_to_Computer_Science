/*********************************************************************
 **             Ellen Yang
 **             HarryPotter.hpp
 **             10/29/18.
 ** This is class HarryPotter specification file, which has defalut constructor,
 ** constructor that takes paramters, modified attack () and defense ().
 ****************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character
{
   private:
      int Hogwarts; //help to check if Hogwarts has been used

   public:
      HarryPotter();
      HarryPotter(int armor, int strength);

      int attack();
      int defense();

      //update strength after being attack
      void updateStrength(int damage);
};

#endif
