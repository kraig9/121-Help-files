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
	list<typename Product> productsPurchased;

public:
	//constructor
	Customer(int customerID, string name, bool credit) :name(name), customerID(customerID), credit(credit) {
		balance = 0;
		list<typename Product> productsPurchased;
	}

	//public functions
	string getName();
	void setName(string name);
	int getID();
	bool getCredit();
	void setCredit(bool hasCredit);
	double getBalance();

	//hw10
	void processPayment(double amount);
	void processPurchase(double amount, Product product);
	void listProductsPurchased(ostream& os);
};
ostream& operator<<(ostream& os, Customer customer);
#endif