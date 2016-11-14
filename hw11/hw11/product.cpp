#include "Product.h"

class mistake : public runtime_error {
public : mistake(string err) : runtime_error(err) {}
};
string Product::getDescription() const{
	return description;
}
void Product::setDescription(string description) {
	this->description = description;
}
string Product::getName() const{
	return productName;
}
void Product::setName(string name) {
	this->productName = name;
}
int Product::getID() const{
	return productID;
}
void Product::setID(int productID) {
	this->productID = productID;
}
int Product::getNumberSold() const{
	return numSold;
}
void Product::setNumberSold(int numSold) {
	if (numSold < 0)throw mistake("error ");
	this->numSold = numSold;
}
double Product::getTotalPaid() const{
	return Product::totalPaid;
}
void Product::setTotalPaid(double totalPaid) {
	this->totalPaid = totalPaid;
}
int Product::getInventoryCount() const{
	return Product::inventory;
}
void Product::setInventoryCount(int inventory) {
	if (inventory < 0)throw mistake("error");
	this-> inventory = inventory;
}
//hw10
void Product::addShipment(int shimpmentQuantity, double shipmentCost) {
	if (inventory < 0 || totalPaid < 0) throw mistake("negative quantity or cost ");
	inventory += shimpmentQuantity;
	totalPaid += shipmentCost;
}
void Product::reduceInventory(int purchaseQuantity) {
	if (Product::inventory < 0)throw mistake("there is not enough inventory ");
	inventory -= purchaseQuantity;
	numSold += purchaseQuantity;
}
double Product::getPrice() const{
	if (inventory + numSold == 0)return 0;
	return (totalPaid / double(inventory + numSold))*1.25;
}
ostream& operator<<(ostream& os, Product product) {
	os << "Product name: " << product.getName() << endl << "Product Description: " << product.getDescription() << endl << "Product ID: " << product.getID() << endl << "Number sold: " << product.getNumberSold() << endl << "Total amount paid: " << product.getTotalPaid() << endl << "Price: " << product.getPrice() << endl << "Inventory: " << product.getInventoryCount() << endl;
	return os;
}
