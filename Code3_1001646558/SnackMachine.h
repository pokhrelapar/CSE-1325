// Apar Pokhrel, 1001646558

#ifndef _SNACK_MACHINE_H
#define _SNACK_MACHINE_H

#include <iostream>
#include <string>


// Status of purchase transaction
enum Status 
{
    Exact, Change, insuffPayment, emptySnacks, highChange, Unknown
};


class SnackMachine
{

    friend std::ostream& operator<<(std::ostream& output,  SnackMachine &nMachine);
    
    friend std::string CreateSnackOutputLine(SnackMachine nMachine);


    public:

        SnackMachine(std::string name = "New Machine", int cost = 50, int change = 500, int inventory =100 ):machineName{name}, SnackPrice{cost},  changeLevel{change}, inventoryLevel{inventory}
        {

        }

        std::string getMachineName();

        bool buyASnack(int payment, std::string &change, int &status);

        int getInventoryLevel();

        int getMaxInventoryCapacity();

        bool incrementInventory(int amountToAdd);

        std::string getChangeLevel();

        bool incrementChangeLevel(int amountToAdd);

        int getMaxChangeCapacity();

        std::string getSnackPrice();

        std::string displayMoney(int amount);

        void setMachineName(std::string newMachineName);

        void setSnackPrice(int newSnackPrice);



    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity= 5000;
        int SnackPrice;
        int inventoryLevel;
        int maxInventoryCapacity= 100;

};

#endif



