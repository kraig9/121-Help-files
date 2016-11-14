#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H


#include "main.h"

using namespace std;

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
	Product(int prodID, string prodName) : productID(prodID), productName(prodName) {
		numSold = 0;
		totalPaid = 0;
		inventory = 0;
	}

	//public functions
	string getDescription() const;
	void setDescription(string description);
	string getName()const;
	void setName(string name);
	int getID() const;
	void setID(int productID);
	int getNumberSold() const;
	void setNumberSold(int numSold);
	double getTotalPaid() const;
	void setTotalPaid(double totalPaid);
	int getInventoryCount() const;
	void setInventoryCount(int inventory);
	//hw10
	void addShipment(int shimpmentQuantity, double shipmentCost);
	void reduceInventory(int purchaseQuantity);
	double getPrice() const;
};
ostream& operator<<(ostream& os, Product product);
#endif