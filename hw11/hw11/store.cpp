#include "store.h"
class error :public runtime_error {
public:error(string err) :runtime_error(err) {}
};
void Store::setName(string name) {
	this->name = name;
}
string Store::getName() {
	return name;
}
void Store::addProduct(int productID, string productName) {
	for (int i = 0; i < products.size(); i++) {
		if (productID == products[i].getID())throw error("ID belongs to another product already");
	}
	products.push_back(Product(productID, productName));
}
void Store::addCustomer(int customerID, string customerName) {
	for (int i = 0; i < customers.size(); i++) {
		if (customerID == customers[i].getID()) throw error("id belongs to another customer already");
	}
	Store::customers.push_back(Customer(customerName,customerID,false));
}

//hw11
Product& Store::getProduct(int productID) {
	for (int i = 0; i < products.size(); i++) {
		if (productID == products[i].getID()) return products[i];
	}
	throw error("no products match ");
}
Customer& Store::getCustomer(int customerID) {
	for (int i = 0; i < customers.size(); i++) {
		if (customerID == customers[i].getID()) return customers[i];
	}
	throw error("no customers match ");
}
void Store::takeShipment(int productID, int quantity, double cost) {
	Product &p = getProduct(productID);
	p.addShipment(quantity, cost);
}
void Store::makePurchase(int customerID, int productID, int quantity) {
	Customer &c = getCustomer(customerID);
	Product &p = getProduct(productID);
	c.processPurchase(quantity, p);
	p.reduceInventory(quantity);
}
void Store::takePayment(int customerID, double amount) {
	Customer &c = getCustomer(customerID);
	c.processPayment(amount);
}
void Store::listProducts() {
	for (int i = 0; i < products.size(); i++) {
		cout << products[i];
	}
}
void Store::listCustomers() {
	for (int i = 0; i < customers.size() < i++) {
		cout << customers[i];
	}
}