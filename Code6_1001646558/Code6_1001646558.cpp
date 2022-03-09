// Apar Pokhrel , 1001646558

/**
 * @author [Apar Pokhrel;]
 * @email [apu8467@gmail.com]
 * @create date 2019-12-04 21:32:55
 * @modify date 2019-12-04 21:32:55
 * @desc [description]
 */



#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <mutex>
#include <thread>
#include <iomanip>

#include <chrono>

#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"


using namespace std;


// gets command line arguments from the screen
void get_command_line_params(int argc, char *argv[], string &nameFile, string &houseFile, string &candyFile)
{
    
        if (argc == 1)
        {
            throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
        }

        else if (argc != 4)
        {
            throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");

        }

        
        else
        {
            nameFile = argv[1];
            houseFile = argv[2];
            candyFile = argv[3];

        }
    
}




int main(int argc , char* argv[])
{
    srand(time(NULL));

    int rank;
	int houseType;

    string nameFile;
    string houseFile;
    string candyFile;
	
	
    string candyNames;
    string trickCandy;
	string houseLines;
	string firstTOT;
	
	ostringstream outputLines;
    
   
    ifstream candyInput;
    ifstream houseInput;
    ifstream nameInput;

    char *token;
	
	

    map <int, string> myCandyMap;   // candy Ranking map ... key:# rank | value: candyName
	
    vector<House*> myHousePtr; 
    vector <TrickOrTreater> TOTs;
	
    // House* tempHouse;
	

    try
    {

        get_command_line_params(argc, argv, nameFile, houseFile, candyFile);

    }


    catch (invalid_argument& say)
    {

        cerr << " Exiting the program...... :\n";

        cout << say.what() << endl;

        exit(0);


    }


    candyInput.open(candyFile);
    houseInput.open(houseFile);
    nameInput.open(nameFile);


    // opening the candy File
    
    if(candyInput.is_open())
    {
        while(getline(candyInput,candyNames))
        {
            char tempCandy[1200];

            strcpy(tempCandy,candyNames.c_str());

            token = strtok(tempCandy,"|");
            trickCandy = tempCandy;

            token = strtok(NULL,"|");
            rank = atoi(token);

            myCandyMap.insert(pair<int,string> (rank,trickCandy) );


        }


    }


    // opens the HOUSE.txt
    if(houseInput.is_open())
    {
        outputLines << setw(10) << " ";


        while(getline(houseInput,houseLines))
        {
			houseType = 1 + rand()% 10;
			
			if(houseType < 5)
			{
				myHousePtr.push_back(new CandyHouse(houseLines,myCandyMap));
				
			}
			
			else
			{
				myHousePtr.push_back(new ToothbrushHouse(houseLines,myCandyMap));

			}
			
            outputLines << left << setw(11) << houseLines;

        }


    }

    // opens the TOT.txt
    if(nameInput.is_open())
    {
        while(getline(nameInput,firstTOT))
        {
            TOTs.push_back(TrickOrTreater (firstTOT,myHousePtr));

        }
    }



    // starting the execution of the threads
    for(auto& trickItem : TOTs)
    {
        trickItem.startThread();
    }



    while (TrickOrTreater::ImDone != TOTs.size() )
    {
        // print enough new lines to the screen
        for(int i = 0 ; i < 40 ; i++ )
        {
            cout << "\n";

        }

        cout << outputLines.str() << endl;


        for(auto& trickPath : TOTs)
        {

            cout << trickPath.getPath();
            cout << trickPath.getName();

            cout <<"\n";


        }


        this_thread::sleep_for(chrono::milliseconds(5));


    }



    for(auto& trickJoin : TOTs)
    {
        trickJoin.joinThread();

    }

     
	cout << "\n\n\n";
	

    for(auto& it : TOTs)
    {
        cout << it ;
    }
	
	cout << "\n\n\n";
	
	
	
    // delete pointers of house
    for(auto& houseit: myHousePtr )
    {
        delete houseit;

    }



    candyInput.close();
    houseInput.close();
    nameInput.close();

    return 0;


}






