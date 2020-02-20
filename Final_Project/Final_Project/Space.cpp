/****************************************************************************
 **  Ellen Yang
 **  Space.cpp
 **  This is the Space class implantation file. This is the abstrate class for
 **  6 spaces in this game. The class contain 4 Space pointers to different
 **  directions. The class also has protectd varialbes, protected friend class,
 **  public pure functions, vitural functions to help player go through each
 **  room and play the game.
 ****************************************************************************/
#include "Space.hpp"

/****************************************************************************
 **  Space::Space()
 **  default constructor for Space class. 
 ****************************************************************************/
Space::Space()
{
   this->top = nullptr;
   this->right = nullptr;
   this->left = nullptr;
   this->bottom = nullptr;

   this->spaceName = "There is no room"; //name of space
   this->energylost = 0;
   this->coffee = 0; 
}

//
Space::~Space()
{
   
}


