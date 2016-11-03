#pragma once

#ifndef STORE_H
#define STORE_H

#include "main.h"

using namespace std;

class Store {
	string name;
public:
	//constructor
	Store(string name) : name(name) {}

	string getName();
	void setName(string name);
	void addProduct(int productID, string productName);
	void addCustomer(int customerID, string customerName);

};

#endif