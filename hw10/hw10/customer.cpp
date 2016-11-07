#include "customer.h"

string Customer::getName() {
	return Customer::name;
}
void Customer::setName(string name) {
	Customer::name = name;
}
int Customer::getID() {
	return Customer::customerID;
}
bool Customer::getCredit() {
	return Customer::credit;
}
void Customer::setCredit(bool hasCredit) {
	Customer::credit = hasCredit;
}
double Customer::getBalance() {
	return Customer::balance;
}
//hw10
void Customer::processPayment(double amount) {
	balance = amount + balance;
	if (Customer::balance < 0)throw(1);
}
void Customer::processPurchase(double amount, Product product) {
	if (credit == true) {
		balance = balance - amount;
	}
	else if (credit != true && balance >= amount) {
		balance = balance - amount;
	}
	else {
		throw(2);
	}
	productsPurchased.push_back(product);
}
void Customer::listProductsPurchased(ostream& os) {
	for (list<Product>::iterator it = productsPurchased.begin(); it != productsPurchased.end();++it) {
		cout << *it;
	}
}
ostream& operator<<(ostream& os, Customer customer) {
	os << "Customer name: " << customer.getName() << endl << "Customer ID: " << customer.getID() << endl << "Customer credit: " << customer.getCredit() << "Customer balance: " << customer.getBalance() << endl;

	return os;
}
