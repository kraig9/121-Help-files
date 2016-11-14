#include "store.h"

void Store::setName(string name) {
	Store::name = name;
}
void Store::addProduct(int productID, string productName) {
	for (list<Product>::iterator it = products.begin(); it != products.end(); ++it) {
		if (*it->getID == productID) throw(1);
	}
	Product temp_prod(productID, productName);
	Store::products.push_back(temp_prod);
}
void Store::addCustomer(int customerID, string customerName) {
	for (list<Product>::iterator it = customers.begin(); it != customers.end(); ++it) {
		if (*it->getID == customerID) throw(2);
	}
	Customer temp_cust(customerID, customerName, true);
	Store::customers.push_back(temp_cust);
}

//hw11
Product& Store::getProduct(int productID) {
	int*  it;
	it=std::find(products.begin(), products.end(), productID);
}
Customer& Store::getCustomer(int customerID) {

}
void Store::takeShipment(int productID, int quantity, double cost) {

}
void Store::makePurchase(int customerID, int productID, int quantity) {

}
void Store::takePayment(int customerID, double amount) {

}
void Store::listProducts() {

}
void Store::listCustomers() {

}

catch (1) {
	cout << "bad ID";
}
catch (2) {

}