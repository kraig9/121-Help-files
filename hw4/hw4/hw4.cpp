#include <process.h>
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <string>

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

int GetNumberOfDigits(int i)
{
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void game(vector<int> combo) {
	while (true) {
		vector<int> guess;

		int bulls = 0;
		int cows = 0;
		//guess_buffer will be stored digit by digit into guess
		int guess_buffer;

		cout << endl << "Enter guess: ";
		cin >> guess_buffer;

		if (GetNumberOfDigits(guess_buffer) > combo.size()) {
			cout << "You can only enter " << combo.size() << " number of digits.";
			continue;
		}

		while (guess_buffer > 0)
		{
			int digit = guess_buffer % 10;
			guess.push_back(digit);
			guess_buffer /= 10;
		}
		while (guess.size() != combo.size()) {
			guess.push_back(0);
		}
		reverse(begin(guess),end(guess));

		//Finding bulls and cows
		for (int i = 0; i < guess.size(); i++) {
			if (guess[i] == combo[i]) {
				bulls++;
			}
			for (int j = 0; j < guess.size(); j++) {
				if (guess[i] == combo[j] && i != j) {
					cows++;
				}
			}
		}
		if (bulls == guess.size()) {
			cout << endl << bulls << " bulls - ";
			for (int i = 0; i < guess.size(); i++) {
				cout << guess[i];
			}
			cout << " is correct!" << endl << endl << endl;
			return;
		}
		else {
			cout << endl << bulls << " bulls";
			cout << endl << cows << " cows";
		}
	}
}

int main() {
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
			while (code_buffer > 0)
			{
				int digit = code_buffer % 10;
				combination.push_back(digit);
				code_buffer /= 10;
			}
			while (combination.size() != num_dig_buffer) {
				combination.push_back(0);
			}
			reverse(begin(combination), end(combination));
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			//hw4
			game(combination);
			break;
		case 3:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			//hw4
			game(combination);
			break;
		case 4:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			//hw4
			game(combination);
			break;
		case 5:
			combination = make_combination_num(combination, num_dig_buffer);
			cout << "Number to guess: ";
			for (int i = 0; i < combination.size(); i++) {
				cout << combination[i];
			}
			//hw4
			game(combination);
			break;
		default:
			break;
		}
		cout << endl << "Enter number of digits in code: ";
	}
}