#include "store.h"

void Store::setName(string name) {
	Store::name = name;
}
void Store::addProduct(int productID, string productName) {
	Product temp_prod(productID, productName);
	Store::products.push_back(temp_prod);
}
void Store::addCustomer(int customerID, string customerName) {
	Customer temp_cust(customerID, customerName, true);
	Store::customers.push_back(temp_cust);
}