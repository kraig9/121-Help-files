#include "main.h"

int main() {
	//testing Product class
	//testing constructor
	Product testProduct(123,"Corps Brass");
	cout << "constructor ID: " << testProduct.getID() << endl << "constructor name: " << testProduct.getName() << endl;

	//testing member functions and data members
	testProduct.setDescription("Brass given to members of the Corps that have completed Corps Brass Culmination.");

	string prodDescription = testProduct.getDescription();
	string prodName = testProduct.getName();
	int prodID = testProduct.getID();

	cout << "description: " << prodDescription << endl << "ID: " << prodID << endl << "name: " << prodName << endl;

	//testing Customer class
	//testing constructor
	Customer testCustomer(12345,"Xuan Ding", true);
	cout << "constructor name: " << testCustomer.getName() << endl << "constructor ID: " << testCustomer.getID() << endl << "constructor credit: " << testCustomer.getCredit() << endl;

	//testing member functions and data members
	testCustomer.setName("Ding Xuan");
	testCustomer.setCredit(false);

	string custName=testCustomer.getName();
	int custID = testCustomer.getID();
	bool custCredit = testCustomer.getCredit();

	cout << "name: " << custName << endl << "ID: " << custID << endl << "credit: " << custCredit << endl;

	

	return 0;
}