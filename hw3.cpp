#include <process.h>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> make_combination_num(vector<int> combination, int num_dig_buffer) {
	//While combination vector size < number of inputted digits, fill combination vector with random integers
	while (combination.size() < num_dig_buffer) {
		combination.push_back(rand() % 10);
	}
	/*Now check to make sure each digit in combination vector isn't equal to one another.
	If 2 elements in the combination vector are unique, replace with another random number
	and check again*/
	for (int i = 0; i < combination.size(); i++) {
		for (int j = 0; j < combination.size(); j++) {
			if (combination[i] == combination[j] && i != j) {
				combination[j] = rand() % 10;
			}
		}
	}
	return combination;
}

int main() {
	vector<int> guess;
	int num_dig_buffer;

	//Code buffer is only when TA puts in 0
	int code_buffer;

	cout << "Enter number of digits in code (3, 4 or 5): ";
	while (true) {
		vector<int> combination;
		int num_dig_buffer;
		
		cin >> num_dig_buffer;
		switch (num_dig_buffer) {
		case 0:
			cout << "Enter code: ";
			cin >> code_buffer;
			//put code_buffer into combination vector 
			cout << "Enter number of digits in code: ";
			cin >> num_dig_buffer;
			cout << "Number to guess: ";
			cout << code_buffer;
			break;
		case 3:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			break;
		case 4:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			break;
		case 5:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			break;
		default:
			break;
		}
		cout << endl << "Enter number of digits in code: ";
	}
}