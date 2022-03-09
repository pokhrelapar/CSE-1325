// Apar Pokhrel, 1001646558

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <mutex>
#include <thread>
#include <ctime>
#include <chrono>
#include <sstream>


#include "House.h"
#include "ToothbrushHouse.h"



// member initializer list
ToothbrushHouse::ToothbrushHouse(std::string toothHouse,std::map<int ,std::string> toothMap):House(toothHouse,toothMap)
{


}


ToothbrushHouse::~ToothbrushHouse()
{
    std::cout << "TOOTHBRUSHHOUSE" << std::endl;
    
}




std::string ToothbrushHouse:: ringDoorbell(std::ostringstream& output)
{

    door.lock();

    output <<"-";   // TOT rings a door bell at a house

    std::string value = "TOOTHBRUSH";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    door.unlock();

    return value;

}







