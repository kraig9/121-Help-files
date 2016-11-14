#include "customer.h"

class problem :public runtime_error {
public:problem(string prob) :runtime_error(prob) {}
};

string Customer::getName() const{
	return name;
}
void Customer::setName(string name) {
	this->name = name;
}
void Customer::setID(int customerID) {
	this->customerID = customerID;
}
int Customer::getID() const{
	return customerID;
}
bool Customer::getCredit() const{
	return credit;
}
void Customer::setCredit(bool hasCredit) {
	this->credit = hasCredit;
}
double Customer::getBalance() const{
	return balance;
}
//hw10
void Customer::processPayment(double amount) {
	if (amount < 0) throw problem("amount is negative. ");
	balance += amount;
}
void Customer::processPurchase(double amount, Product product) {
	bool b = false;
	for (int i = 0; i < productsPurchased.size(); i++) {
		if (product.getID() == productsPurchased[i].getID()) {
			b = true;
		}
	}
	if (b == false)productsPurchased.push_back(product);
	if (amount < 0)throw problem("amount is negative ");
	if (credit)balance -= amount;
	else if (balance >= amount)balance -= amount;
	else throw problem("credit is negative, so balance can't be negative. ");
}
void Customer::listProductsPurchased(ostream& os) {
	for (int i = 0; i < productsPurchased.size(); i++) {
		os << productsPurchased[i] << endl;
	}
}
ostream& operator<<(ostream& os, Customer customer) {
	os << "Customer name: " << customer.getName() << endl << "Customer ID: " << customer.getID() << endl << "Customer credit: " << customer.getCredit() << "Customer balance: " << customer.getBalance() << endl;
	return os;
}
