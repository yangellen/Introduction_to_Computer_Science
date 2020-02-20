/*********************************************************************
 ** Author:       Ellen Yang
 ** Program       Building.hpp
 ** Date:         Oct 19, 2018
 ** Description: Building.hpp is the class Building specification file, which
 **              contains member variables of buildingName, buildingSize and
 **              buildingAddress. It also contain constructors, getter and
 **              setter functions that is needed for this program to work.
 *********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <string>

using std:: string;

class Building
{
   private:
      string buildingName;// name of the building
      int buildingSize; //size of building in aqft
      string buildingAddress; // address of the building

   public:
      Building();//defult constructors
      Building(string name, int size, string address);// constructor w/parameter

      ~Building();//destructor

      string getBuildingName();
      int getBuildingSize();
      string getBuildingAddress();
};

#endif
