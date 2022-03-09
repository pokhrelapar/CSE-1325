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
#include "CandyHouse.h"



// member initializer list
CandyHouse::CandyHouse(std::string candyHouse,std::map<int ,std::string> CandyHouseMap): House(candyHouse,CandyHouseMap)
{

}

CandyHouse::~CandyHouse()
{
    std::cout << "CANDYHOUSE" << std::endl;
    
}





std::string CandyHouse:: ringDoorbell(std::ostringstream& output)
{

    door.lock();


    output <<"+";   // TOT rings a door bell at a house

     
    std::this_thread::sleep_for(std::chrono::seconds(3));


    int candyNum = 1 + (rand()% CandyRankingMap.size());


    door.unlock();


    return CandyRankingMap[candyNum]; // returns the name of the candy of the random number


}







