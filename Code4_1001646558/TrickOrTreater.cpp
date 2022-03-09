// Apar Pokhrel, 1001646558


#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "TrickOrTreater.h"


int TrickOrTreater::ImDone = 0;


// member initializer list
TrickOrTreater::TrickOrTreater(std::string hName , std::vector<House*> HousePtr):name{hName},ListOfHouses{HousePtr}
{

}

std::ostream& operator<<(std::ostream& output, TrickOrTreater& Tricks)
{


    output << Tricks.getName()<< "'s - ";


    for( auto bucket : Tricks.Bucket)
    {
        output << bucket.second << " "  <<  bucket.first << ",";
    
    }


    output << "\n";


    return output;

}



std::string TrickOrTreater :: getName()
{
    return name;


}


void TrickOrTreater::startThread()
{
    TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);



}


void TrickOrTreater::joinThread()
{


    this->TOTThreadPtr->join();


    delete TOTThreadPtr;


}

void TrickOrTreater::GoTrickOrTreating()
{


    int speed;
    std::string sweetCandy;


    for( auto it : ListOfHouses)
    {

        speed = 1 + (rand()% 500);
        TrickOrTreater::Walk(speed);


        std::string sweetCandy = it->ringDoorbell(path);


        Bucket[sweetCandy]++;
  

    }


    // increment ImDone adter a given candy  
    TrickOrTreater::ImDone++;

}



void TrickOrTreater::Walk(int speed)
{

    for(int i = 0; i < 10; i++)
    {
        path << ".";


        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        
    }

}




std::string TrickOrTreater:: getPath()
{
    return path.str();


}



