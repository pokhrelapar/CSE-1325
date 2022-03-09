// Apar Pokhrel , 1001646558


/**
 * @author [Apar Pokhrel]
 * @email [apu8467@gmail.com]
 * @create date 2019-09-10 21:35:04
 * @modify date 2019-09-18 20:43:32
 * @desc [Pencil Dispenser program that displays inventory, change level and prompts and processes purchase 
]
 */


#include <iostream>
#include <string>
using namespace std;
#define pencilPrice 60    // Cost price of a single pencil ($0.60)


bool buyPencils(int &changeLevel, int &Inventory, int payment, int finalCost, int nPencils, int &order);
string displayMoney(int amount);
void menuFeature(int &menuOption);



// Status of purchase transaction
enum Status 
{
    Exact, Change, insuffPayment, emptyPencils, highChange, Unknown
};




int main()
{
    int Inventory = 100; // starting number of pencils
    int changeLevel = 500;  // starting value of change 
    bool id = true;
    int nPencils=0;
    int payment=0;
    int amount=0;
    int menuOption =-1; // counter
    int order = 1;
    int finalCost;

    
    cout << "\n\n Welcome to my Pencil Machine!\n" << endl;
   

    while(menuOption!=0)
    {
        menuFeature(menuOption);
        
        //cout << "\n Invalid menu option\n\n" ;
        //menuFeature(menuOption);
        
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "\n Input must be numeric. Please reenter.\n\n";
            cout << "Choice : " ;
            cin>> menuOption;
    
        }

                         
    
        switch(menuOption)
        {
            case 0: 
                break;

            case  1:
                if(Inventory==0)
                {
                    cout << "This Pencil Dispenser is out of inventory.\n"<< endl;
                    menuOption = 0;
                    break;     // no penicls to make a purchase 
                }

                else
                {
                    cout <<"\n A pencil costs ";
                    cout << displayMoney(pencilPrice) << "."<<endl;

                    cout << "\n\n How many pencils would you like to purchase? ";
                    cin >> nPencils;

                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "\n Input must be numeric. Please reenter.";
                        cout << "\n\n How many pencils would you like to purchase? ";
                        cin >> nPencils;
                    }
                    
                }

                if (nPencils<= 0)
                {
                    cout << "\n You must purchase at least one pencil.\n" <<endl;

                }

                else
                {
                    if(nPencils > Inventory)
                    {
                        // status 
                        id =  buyPencils(changeLevel, Inventory, payment, finalCost,  nPencils, order);

                    }

                    else
                    {
                        finalCost = nPencils*pencilPrice;
                        cout << "\n\n Your total is " ;
                        cout << displayMoney(finalCost)<< "."<< endl;
                        cout << "\n\n Enter your payment (in cents): ";
                        cin >> payment;

                        while (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(50, '\n');
                            cout << "\n Input must be numeric. Please reenter.\n\n";
                            cout << "Enter your payment (in cents): ";
                            cin >> payment;
                        }
                        
                        // status 
                        id =  buyPencils(changeLevel, Inventory, payment, finalCost,  nPencils, order);

                    }

                    if (id)
                    {
                        

                         if (order == Exact)
                        {
                            cout << "\n Here are your pencils. Thank you for the  exact payment.\n" << endl;

                        }

                        else if(order == Change)
                        {
                            cout << "\n Here are your penicls and your change of " <<
                             displayMoney(payment-(nPencils*pencilPrice)) << ".\n"<<endl;
                             
                        
                        }
                    }

                    else
                    {
                        if(order == insuffPayment)
                        {
                            cout << "\n You entered an insufficient payment. No pencils for you.\n"<<endl;

                        }

                        else if(order == emptyPencils)
                        {
                            cout << "\n The machine does not have that many pencils. Buy " << Inventory << " or fewer pencils.\n" << endl;

                        }

                        else if(order == highChange)
                        {
                            cout << "\n The machine does not have enough change and cannot acccept the payment. \n" << endl;    

                        }

                        else
                        {
                            cout << "\n Undefined error!\n" << endl;
                        }
                    }
                    
                    
                }
            
                    break;


                case 2:
                    cout << "The current inventory level is " << Inventory << endl;
                    break;

                
                case 3:
                    cout << "The current change level is " << changeLevel << endl;
                    break;

                default:
                    cout << "Invalid menu option. Reenter your choice again." << endl;





                //cin.clear();
                 //cin.ignore(50, '\n');
                // cout << "\n Input must be numeric. Please reenter.";
                    

        }

    }
    
    
    return 0;  
}




// Pennies to dollar 
string displayMoney(int amount)
{
    string dollars{to_string(amount / 100)};
    string cents{to_string(abs(amount % 100))};
    return "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
}



// Menu options
void menuFeature(int &menuOption)
{
    
    cout << "\n Please choose from the following options: \n\n" << endl;
    cout << "0. No pencils for me today\n"
            "1. Purchase pencils\n"
            "2. Check inventory level\n"
            "3. Check change level \n" << endl;

    cout << "Choice : " ;
    cin >> menuOption; 

}

// bool function to determine transaction
bool buyPencils(int &changeLevel, int &Inventory, int payment, int finalCost, int nPencils, int &order)
{   

    int valueChange = payment - finalCost;

    // not enough inventory
    if (Inventory < nPencils)
    {
        order = emptyPencils;
        return false;

    }

    else if (payment > finalCost)
    {
        //transaction complete 
        if(changeLevel > valueChange)
        {
            order = Change;
            Inventory = Inventory - nPencils;
            changeLevel = changeLevel - valueChange + payment;
            return true;
            
        }

        // not enough change to complete purchase
        else
        {
            order = highChange;
            return false;
        }
        
    }

    //transaction complete 
    else if (payment == finalCost)
    {
        order = Exact;
        Inventory -= nPencils;
        changeLevel += payment;
        return true;
        
    }

    

    // insufficient payment was given
    else if (payment < finalCost)
    {
        order = insuffPayment;
        return false;
    }

    else
    {
        order = Unknown;
        return false;
    }

}


    






