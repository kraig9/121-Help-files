#pragma once
#include "main.h"

class Product{
	//data members
	int productID;
	int numSold;
	int totalPaid;
	int inventory;
	string productName;
	string description;

public:
	//constructor
	Product(int productID, string productName) : productID(productID), productName(productName) {
		numSold = 0;
		totalPaid = 0;
		inventory = 0;
	}

	//public functions
	string getDescription();
	void setDescription(string description);
	string getName();
	int getID();
	int getNumberSold();
	double getTotalPaid();
	int getInventoryCount();
};
