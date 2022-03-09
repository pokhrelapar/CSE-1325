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


// member initializer list
House::House(std::string scaryHouse,std::map<int ,std::string> myCandyMap): houseName{scaryHouse}, CandyRankingMap{myCandyMap}
{

}

House::~House()
{
    std::cout << "HOUSE" << std::endl;
    
}



std::string House:: ringDoorbell(std::ostringstream& output)
{

}







