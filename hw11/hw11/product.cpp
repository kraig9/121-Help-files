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
//hw10
void Product::addShipment(int shimpmentQuantity, double shipmentCost) {
	Product::inventory = Product::inventory + shimpmentQuantity;
	Product::totalPaid = Product::totalPaid + shipmentCost;
	if (Product::inventory < 0 || Product::totalPaid < 0) throw(1);
}
void Product::reduceInventory(int purchaseQuantity) {
	Product::inventory = Product::inventory - purchaseQuantity;
	Product::numSold = purchaseQuantity;
	if (Product::inventory < 0)throw(2);
}
double Product::getPrice() {
	double price;
	price = (double(totalPaid) / (double(inventory) + double(numSold)))*1.25;
	return price;
}
ostream& operator<<(ostream& os, Product product) {
	os << "Product name: " << product.getName() << endl << "Product Description: " << product.getDescription() << endl << "Product ID: " << product.getID() << endl << "Number sold: " << product.getNumberSold() << endl << "Total amount paid: " << product.getTotalPaid() << endl << "Price: " << product.getPrice() << endl << "Inventory: " << product.getInventoryCount() << endl;
	return os;
}
