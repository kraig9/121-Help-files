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