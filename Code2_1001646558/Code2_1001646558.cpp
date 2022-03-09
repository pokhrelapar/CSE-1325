// Apar Pokhrel , 1001646558

/**
 * @author [Apar Pokhrel;]
 * @email [apu8467@gmail.com]
 * @create date 2019-10-07 00:55:35
 * @modify date 2019-10-07 00:55:35
 * @desc [Snack Machine]
 */

#include <iostream>
#include <string>
#include "SnackMachine.h"

using namespace std;


// Menu options
int  menuFeature(string title)
{
     cout << "\n\n";
    cout << title <<endl;
    cout << "\n\n";


    int menuChoice=0;
    
    cout << "\n Please choose from the following options: \n\n" << endl;
    cout << "0. Walk away\n"
            "1. Buy a snack\n"
            "2. Restock Machine\n"
            "3. Add change\n" 
            "4. Display Machine Info\n"<< endl;

    cout << "Choice : " ;
    cin >> menuChoice; 
    return menuChoice;

}


int main()
{

    //char buffer[256];

    SnackMachine mySnackMachine ={"CSE 1325 SnackMachine",50,500,100};
    

    string change;
    string name;

    int changeAdded;
    int snacksAdded;
    int payment;
    int status;
    int optionS; 
    int menuChoice =1;

    bool id;

    name = mySnackMachine.getMachineName();

    while(optionS!=0)
    {
        optionS = menuFeature(name);

        while(cin.fail() || (optionS <0 || optionS >4))
        {
            if(optionS <0 || optionS > 4)
            {
                cout<< "\n Enter a value between 0 and 4. Please reenter.\n"<<endl;
            }

            else
            {
                cin.clear();
                cin.ignore(50,'\n');
                cout << "\n Input must be numeric. Reenter your choice "<<endl;
                
       
            }

            cout << "Choice : ";
            cin >> optionS;  
            
        }

        switch(optionS)
        {
            case 0: 
                cout << "\n Are you sure you aren't really HUNGRY and need a Sanck?\n" <<endl;
                break;

            case  1:
                if(mySnackMachine.getInventoryLevel() == 0)
                {
                    cout << "The Snack Machine is out of inventory.\n"<< endl;
                    optionS = 0;
                    break;     // no snacks to make a purchase 
                }

                else
                {
                    cout <<"\n A snack costs ";
                    cout << mySnackMachine.getSnackPrice() << "."<<endl;

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
                        {  // Exact Change
                            cout << "\n Here is your snack. Thank you for the  exact payment.\n" << endl;

                        }

                        else if(status == Change)
                        {
                            // Change given
                            cout << "\n Here's  your snack and your change of " << change << "." <<endl;
                          
                        }
                    }

                    else
                    {
                        if(status == insuffPayment)
                        {   //Less payment

                            cout << "\n You entered an insufficient payment.....returning your payment.\n"<<endl;

                        }

                        else if(status == emptySnacks)
                        {   // No snacks remaining 

                            cout << "The machine is out of snacks.\n"<<endl;

                        }

                        else if(status == highChange)
                        {   // Change provided exceeded max change Level

                            cout << "\n Unable to give change at this time...returning your payment \n" << endl;    

                        }

                        else
                        {
                            // Undefined error
                            cout << "\n Undefined error!\n" << endl;
                        }
                    }
                    
                    
                }
            
                break;


                case 2:
                    cout << "\n How many items are you adding to the machine? " ;
                    cin >> snacksAdded;


                    if(mySnackMachine.incrementInventory(snacksAdded))
                    {
                        cout << "\n The machine has been restocked. \n"<<endl;
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
                    
                    if(mySnackMachine.incrementChangeLevel(changeAdded))
                    {
                        cout << "\n Your change has been added.\n" << endl;
                        cout << " The current change level is " << mySnackMachine.getChangeLevel() << endl;
                    }

                    else
                    {
                        cout << "\n Adding the change will exceed the machine's max capacity\n" << endl;
                        cout << "The current change level is " << mySnackMachine.getChangeLevel() << endl;

                        
                    }
                    break;



                case 4:
                    cout << "Current Inventory Level: " << mySnackMachine.getInventoryLevel() << endl;
                    cout << "Max Inverntory Capacity: " << mySnackMachine.getMaxInventoryCapacity() << endl;

                    cout << "\nCurrent Change Level: " << mySnackMachine.getChangeLevel() << endl;
                    cout << "Max Change Capacity: " << mySnackMachine.getMaxChangeCapacity() << endl;
                    cout << "\nCurrent Snack price: " << mySnackMachine.getSnackPrice()<<endl;

                    break;


        }

    }

    return 0;
}

