#include "Product.h"

string Product::getDescription() {
	return Product::description;
}
void Product::setDescription(string description) {
	Product::description = description;
}
string Product::getName() {
	return Product::productName;
}
int Product::getID() {
	return Product::productID;
}
int Product::getNumberSold() {
	return Product::numSold;
}
double Product::getTotalPaid() {
	return Product::totalPaid;
}
int Product::getInventoryCount() {
	return Product::inventory;
}


