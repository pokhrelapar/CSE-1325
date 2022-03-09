// Apar Pokhrel, 1001646558

// Snack Library

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "SnackMachine.h"


std::string SnackMachine::getMachineName()
{
	return machineName;

}


bool SnackMachine::buyASnack(int payment, std::string &change, int &status)
{
	int changeGiven = payment - SnackPrice;

	if (inventoryLevel == 0)
	{
		status = emptySnacks;
		return false;
	}

	else if (payment == SnackPrice)
	{
		status = Exact;
		inventoryLevel--;
		changeLevel = changeLevel + payment;
		return true;
	}

	else if (payment > SnackPrice)
	{
		if (changeLevel > changeGiven)
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

	else if (payment < SnackPrice)
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

int SnackMachine::getInventoryLevel()
{
	return inventoryLevel;
}

int SnackMachine::getMaxInventoryCapacity()
{
	return maxInventoryCapacity;
}

bool SnackMachine::incrementInventory(int amountToAdd)
{
	if ((amountToAdd + inventoryLevel) <= maxInventoryCapacity)
	{
		inventoryLevel += amountToAdd;
		return true;
	}

	else
	{
		return false;
	}
}

std::string SnackMachine::getChangeLevel()
{
	return displayMoney(changeLevel);
}

bool SnackMachine::incrementChangeLevel(int amountToAdd)
{
	if ((amountToAdd + changeLevel) <= maxChangeCapacity)
	{
		changeLevel += amountToAdd;
		return true;
	}

	else
	{
		return false;
	}
}

int SnackMachine::getMaxChangeCapacity()
{
	return maxChangeCapacity;
}

std::string SnackMachine::getSnackPrice()
{
	return displayMoney(SnackPrice);
}

std::string SnackMachine::displayMoney(int amount)
{
	std::string dollars{std::to_string(amount / 100)};
	std::string cents{std::to_string(abs(amount % 100))};
	return "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
}


void SnackMachine::setMachineName(std::string newMachineName)
{
	machineName = newMachineName;
	
}


void SnackMachine::setSnackPrice(int newSnackPrice)
{
	SnackPrice = newSnackPrice;
	
}



std::ostream& operator<<(std::ostream& output,  SnackMachine &nMachine)
{
	output  << "\n"<< nMachine.getMachineName() << std::endl
			<< "\n Current Inventory Level: " << nMachine.getInventoryLevel() << std::endl
		    << "\n Max Inverntory Capacity: "  << nMachine.getMaxInventoryCapacity() << std::endl
		    << "\n Current Change Level:  "  << nMachine.getChangeLevel()<< std::endl
			<< "\n Max Change Capacity: "  << nMachine.getMaxChangeCapacity()<< std::endl
			<< "\n Current Snack price: "  << nMachine.getSnackPrice()<< std::endl;

	
	return output;

}

std::string CreateSnackOutputLine(SnackMachine nMachine)
{
	std::string printLine;
	std::ostringstream printString;

	printString << nMachine.machineName << "|" << std::to_string(nMachine.SnackPrice) << "|" <<
				std::to_string(nMachine.changeLevel) << "|" << std::to_string(nMachine.inventoryLevel) <<"\n";
	
	printLine = printString.str();
    return printLine;
}




