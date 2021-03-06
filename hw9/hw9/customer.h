#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "main.h"
using namespace std;

class Customer {
	//data members
	int customerID;
	bool credit;
	double balance;
	string name;
	vector<string> productsPurchased;

public:
	//constructor
	Customer(string name, int customerID, bool credit) :name(name), customerID(customerID), credit(credit) {
		balance = 0;
	}

	//public functions
	string getName();
	void setName(string name);
	int getID();
	bool getCredit();
	void setCredit(bool hasCredit);
	double getBalance();
};
#endif