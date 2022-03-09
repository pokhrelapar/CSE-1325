// Apar Pokhrel , 1001646558

/**
 * @author [Apar Pokhrel;]
 * @email [apu8467@gmail.com]
 * @create date 2019-10-17 23:56:31
 * @modify date 2019-10-17 23:56:31
 * @desc [Updated Snack Machine]
 */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

#include "SnackMachine.h"
#include "SnackLib.h"

using namespace std;

// Menu options
int menuFeature()
{
    cout << "\n\n";

    int menuChoice = 0;

    cout << "\n Please choose from the following options: \n\n"
         << endl;
    cout << "0. Walk away\n\n"
            " 1. Buy a snack\n\n"
            " 2. Restock Machine\n\n"
            " 3. Add change\n\n"
            " 4. Display Machine Info\n\n"
            " 5. Update Machine Name\n\n"
            " 6. Enter a new Snack price\n\n"
         << endl;

    cout << "Choice : ";
    cin >> menuChoice;
    return menuChoice;
}

void get_command_line_params(int argc, char *argv[], string &inputFile, string &outputFile)
{
    //while(argc<4)
    //{

        if (argc == 1)
        {
            throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
        }

        else if (argc != 3)
        {
            throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");

        }

        
        else
        {
            inputFile = argv[1];
            outputFile = argv[2];
        }
        
    //}
}

int main(int argc, char *argv[])
{

    //char buffer[256];

    SnackMachine mySnackMachine;

    vector<SnackMachine> SetOfSnackMachines;
    vector<string> ConstructorValues(4);

    string change;
    string name;
    string printLine;
    string newMachineName;
    string SnackMachineLine;
    string inputFile;
    string outputFile;

    int changeAdded;
    int snacksAdded;
    int payment;
    int status;
    int optionS = -1; // flag for second menu
    //int menuChoice = 1;

    int newSnackPrice = 0;
    int loop = 0;

    int optionT = 0; // new menu option choice

    

    bool id;

    try
    {
        get_command_line_params(argc, argv, inputFile, outputFile);
    }

    catch (invalid_argument &say)
    {
        cout << "Exiting the program......" << endl;
        cerr << "Exception: " << say.what() << "\n\n";
        exit(EXIT_FAILURE);
    }

    ifstream SnackInputFile{inputFile};
    ofstream SnackOutputFile{outputFile, ios::out};

    if (SnackInputFile.is_open())
    {
        while (getline(SnackInputFile, SnackMachineLine))
        {

            if (ParseSnackLine(SnackMachineLine, ConstructorValues))
            {
                SnackMachine tempMachine{ConstructorValues[0], stoi(ConstructorValues[1]), stoi(ConstructorValues[2]), stoi(ConstructorValues[3])};
                SetOfSnackMachines.push_back(tempMachine);
            }
        }
    }

    else
    {
        cerr << "\n Unable to open file\n"
             << endl;

        exit(EXIT_FAILURE);
    }


    do
    {
        int counter = 0;

        cout << "\n Pick a Snack Machine\n\n"
            << endl;

        cout << counter << ".Exit\n" << endl;

        for (counter = 1; counter <= SetOfSnackMachines.size(); counter++)
        {
            cout << counter << "." << SetOfSnackMachines[counter - 1].getMachineName() << "\n"
                << endl;
        }

        cout << counter << ". Add a new machine\n"
            << endl;

        cout << "Enter choice : ";
        cin >> optionT;

        if (optionT == 0)
        {

            for(loop =0; loop < SetOfSnackMachines.size(); loop++)
            {
                printLine = CreateSnackOutputLine(SetOfSnackMachines[loop]);
                SnackOutputFile << printLine;
            }
            
            return 0;
        }

        else if (optionT == counter)
        {
            SnackMachine tempMachine{};
            SetOfSnackMachines.push_back(tempMachine);
            cout << "New machine has been added.\n"<<endl;
            optionS = 0;   
            
        }

        else
        {
            mySnackMachine = SetOfSnackMachines[optionT-1];
            name = SetOfSnackMachines[optionT-1].getMachineName();
            cout << endl <<endl;
            cout << name <<"\n\n"<<endl;
        }
        

        while (optionS != 0)
        {
            cout << "\n";

            optionS = menuFeature();

            while (cin.fail() || (optionS < 0 || optionS > 6))
            {
                if (optionS < 0 || optionS > 6)
                {
                    cout << "\n Enter a value between 0 and 6. Please reenter.\n"
                        << endl;
                }

                else
                {
                    cin.clear();
                    cin.ignore(50, '\n');
                    cout << "\n Input must be numeric. Reenter your choice " << endl;
                }

                cout << "Choice : ";
                cin >> optionS;
            }

            switch (optionS)
            {
                case 0:
                    cout << "\n Are you sure you aren't really HUNGRY and need a Sanck?\n"<< endl;
                    break;

                case 1:
                    if (mySnackMachine.getInventoryLevel() == 0)
                    {
                        cout << "The Snack Machine is out of inventory.\n"
                            << endl;
                        
                        break; // no snacks to make a purchase
                    }

                    else
                    {
                        cout << "\n A snack costs ";
                        cout << mySnackMachine.getSnackPrice() << "." << endl;

                        cout << "\n\n Please insert your payment (cents) : ";
                        cin >> payment;

                        while (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(50, '\n');
                            cout << "\n Input must be numeric. Please reenter.";
                            cout << "\n\n Reenter your payment (cents) : ";
                            cin >> payment;
                        }

                        id = mySnackMachine.buyASnack(payment, change, status);

                        if (id)
                        {

                            if (status == Exact)
                            { // Exact Change
                                cout << "\n Here is your snack. Thank you for the  exact payment.\n"
                                    << endl;
                            }

                            else if (status == Change)
                            {
                                // Change given
                                cout << "\n Here's  your snack and your change of " << change << "." << endl;
                            }
                        }

                        else
                        {
                            if (status == insuffPayment)
                            { //Less payment

                                cout << "\n You entered an insufficient payment.....returning your payment.\n"
                                    << endl;
                            }

                            else if (status == emptySnacks)
                            { // No snacks remaining

                                cout << "The machine is out of snacks.\n"
                                    << endl;
                            }

                            else if (status == highChange)
                            { // Change provided exceeded max change Level

                                cout << "\n Unable to give change at this time...returning your payment \n"
                                    << endl;
                            }

                            else
                            {
                                // Undefined error
                                cout << "\n Undefined error!\n"
                                    << endl;
                            }
                        }
                    }

                    break;

                case 2:

                    cout << "\n How many items are you adding to the machine? ";
                    cin >> snacksAdded;

                    if (mySnackMachine.incrementInventory(snacksAdded))
                    {
                        cout << "\n The machine has been restocked.\n"
                            << endl;
                        cout << "The current inventory level is " << mySnackMachine.getInventoryLevel() << endl;
                    }

                    else
                    {
                        cout << "\n Adding the items will exceed the machine's max capacity" << endl;
                        cout << "\n The current inventory level is " << mySnackMachine.getInventoryLevel() << endl;
                    }

                    break;

                case 3:

                    cout << "\n How much change are you adding? : ";
                    cin >> changeAdded;

                    if (mySnackMachine.incrementChangeLevel(changeAdded))
                    {
                        cout << "\n Your change has been added.\n"
                            << endl;
                        cout << " The current change level is " << mySnackMachine.getChangeLevel() << endl;
                    }

                    else
                    {
                        cout << "\n Adding the change will exceed the machine's max capacity\n"
                            << endl;
                        cout << "The current change level is " << mySnackMachine.getChangeLevel() << endl;
                    }
                    break;

                case 4:

                    cout << mySnackMachine;
                    break;

                case 5:

                    cout << "\n Enter a new machine name : ";
                    cin.clear();
                    cin.ignore(50, '\n');
                    getline(cin, newMachineName);

                    mySnackMachine.setMachineName(newMachineName);
                    cout << " \nMachine name has been updated\n"
                        << endl;
                    break;

                case 6:

                    cout << "\n Enter a new Snack price : ";
                    cin >> newSnackPrice;
                    mySnackMachine.setSnackPrice(newSnackPrice);
                    cout << "\n Snack price has been updated.\n"
                        << endl;
            }

            SetOfSnackMachines[optionT-1] = mySnackMachine;
        }

        optionS = 1; // goes to first menu option

    }while(optionT!=0);
    
    SnackInputFile.close();  // inputfile closed
    SnackOutputFile.close(); // outputfile closed

    return 0;
}





