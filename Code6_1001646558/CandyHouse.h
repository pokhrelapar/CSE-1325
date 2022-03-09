//Apar Pokhrel, 1001646558

// Apar Pokhrel, 1001646558

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#include "House.h"



#ifndef _CANDYHOUSE_H
#define _CANDYHOUSE_H

class CandyHouse: public House
{

	public :
		CandyHouse(std::string candyHouse, std::map<int, std::string> CandyHouseMap);
        ~CandyHouse();
		std::string ringDoorbell(std::ostringstream &);



};

#endif






