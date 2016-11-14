#pragma once
#ifndef STORE_H
#define STORE_H

#include "main.h"

using namespace std;

class Store {
	string name;
	list<Product> products;
	list<Customer> customers;

public:
	Store(string name) : name(name) {}

	void setName(string name);
	void addProduct(int productID, string productName);
	void addCustomer(int customerID, string customerName);

	//hw11
	Product& getProduct(int productID);
	Customer& getCustomer(int customerID);
	void takeShipment(int productID, int quantity, double cost);
	void makePurchase(int customerID, int productID, int quantity);
	void takePayment(int customerID, double amount);
	void listProducts();
	void listCustomers();

};
#endif