/*********************************************************************
 ** Author:       Ellen Yang
 ** Program       Building.cpp
 ** Date:         Oct 19, 2018
 ** Description: Building.cpp is the class Building implementation file, which
 **              contains member variables of buildingName, buildingSize and
 **              buildingAddress. It also contain constructors, getter and
 **              setter functions that is needed for this program to work.
 *********************************************************************/

#include "Building.hpp"
/*********************************************************************
 **               Building::Building()
 ** Description:  default contrcutor. It initilaizes the member variables,
 **               buildingName, buildingSize, buildingAddress
 *********************************************************************/
Building::Building()
{
   buildingName = "noNmae";
   buildingSize = 0; 
   buildingAddress = "noWhere";
}
/*********************************************************************
 **               Building::Building(string name, int size, string address)
 ** Description:  contrcutor that takes the member variables,
 **               buildingName, buildingSize, buildingAddress as parameter
 *********************************************************************/
Building::Building(string name, int size, string address)
{
   buildingName = name;
   buildingSize = size;
   buildingAddress = address;
}
 //getter function to get building name
string Building::getBuildingName()
{
   return buildingName;
}

//getter function to get building size
int Building::getBuildingSize()
{
   return buildingSize;
}

//getter function to get building address
string Building::getBuildingAddress()
{
   return buildingAddress;
}

//destructor
Building::~Building()
{
   
}
