// Apar Pokhrel, 1001646558

#ifndef _SnackMachine_H
#define _SnackMachine_H

#include <iostream>
#include <string>


// Status of purchase transaction
enum Status 
{
    Exact, Change, insuffPayment, emptySnacks, highChange, Unknown
};


class SnackMachine
{
    public:

        SnackMachine(std::string name, int cost, int change, int inventory): machineName{name}, SnackPrice{cost},  changeLevel{change}, inventoryLevel{inventory}
        {

        }

        std::string getMachineName()
        {
            return machineName;

        }

        bool buyASnack(int payment, std::string &change, int &status)
        {
            int changeGiven = payment - SnackPrice;

            if(inventoryLevel==0)
            {
                status = emptySnacks;
                return false;
            }

            else if(payment == SnackPrice)
            {
                status = Exact;
                inventoryLevel--;
                changeLevel = changeLevel+ payment;
                return true;

            }

            else if(payment > SnackPrice)
            {
                if(changeLevel > changeGiven)
                {
                    status = Change;
                    inventoryLevel--;
                    changeLevel = changeLevel - changeGiven + payment;
                    change = displayMoney(payment - SnackPrice);
                    return true;

                }

                else
                {
                    status = highChange;
                    return false;

                }
            
            }


            else if(payment < SnackPrice)
            {
                status = insuffPayment;
                return false;

            }

            else
            {
                status = Unknown;
                return false;

            }

        }

        int getInventoryLevel()
        {
            return inventoryLevel;

        }

        int getMaxInventoryCapacity()
        {
            return maxInventoryCapacity;


        }

        bool incrementInventory(int amountToAdd)
        {
            if((amountToAdd + inventoryLevel) <= maxInventoryCapacity)
            {
                inventoryLevel+= amountToAdd;
                return true;
            }

            else
            {
                return false;
            }
            

        }

        std::string getChangeLevel()
        {
            return displayMoney(changeLevel);

        }

        bool incrementChangeLevel(int amountToAdd)
        {
            if((amountToAdd+ changeLevel) <= maxChangeCapacity)
            {
                changeLevel+= amountToAdd;
                return true;

            }

            else
            {
                return false;
            }
            

        }

        std::string getMaxChangeCapacity()
        {
            return displayMoney(maxChangeCapacity);

        }

        std::string getSnackPrice()
        {
            return displayMoney(SnackPrice);
        }


        std::string displayMoney(int amount)
        {
            std::string dollars{std::to_string(amount / 100)};
            std::string cents{std::to_string(abs(amount % 100))};
            return "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;

        }


    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity= 5000;
        int SnackPrice;
        int inventoryLevel;
        int maxInventoryCapacity= 100;

};

#endif



