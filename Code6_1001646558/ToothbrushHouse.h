//Apar Pokhrel, 1001646558


#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#include "House.h"


#ifndef _TOOTHBRUSHHOUSE_H
#define _TOOTHBRUSHHOUSE_H

class ToothbrushHouse: public House
{

	public :
		ToothbrushHouse(std::string, std::map<int, std::string>);
        ~ToothbrushHouse();
		std::string ringDoorbell(std::ostringstream &);

};

    
	

#endif











