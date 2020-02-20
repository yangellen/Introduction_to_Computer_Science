/*********************************************************************
**             Ellen Yang
**            Character.hpp
**              10/25/18.
** This is class Character specification file. This is the abstract base class
** for the different character classes.
****************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Die.hpp"
#include <string>

using std::string;

class Character
{
   protected:
      int attackPoints;
      int defensePoints;
      int armor;
      int strength;
      string name;
      string playerType;



   public:
      Character();
   
      virtual ~Character();

      virtual int attack() = 0;
      virtual int defense() = 0;

      virtual int rollDie(int numRoll, int numSide);

      //update strength after being attack
      virtual void updateStrength(int damage);

      virtual int getAttack()
      {return attackPoints;}

      virtual int getDefense()
      {return defensePoints;}

      virtual int getArmor()
      {return armor;}

      virtual int getStrength()
      {return strength;}

      virtual string getName()
      {return name;}

      virtual string getPlayerType()
      {return playerType;}

      virtual void recover(int damage);
};

#endif
