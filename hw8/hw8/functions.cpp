#include "Header.h"

using namespace std;

void printUsageInfo(string s) {
	cout << "No input from command line.";
	throw(1);
}

bool isPalindrome(string s, bool case_flag, bool space_flag) {
	bool isPal = true;

	if (space_flag == true) removeSpace(s);
	if (case_flag == true) toLowString(s);
	removePunctuation(s);

	isPal = isPalindrome(s, case_flag, space_flag);
	return true;
}

string toLowString(string s) {
	for (int i = 0; i < s.size(); i++) {
		tolower(s.at(i));
	}
}

bool is_punct(char c) {
	switch (c) {
	case '.':
	case ',':
	case '\'':
	case '!':
	case  ':':
	case ';':
	case '?':
		return true;
	default:
		return false;
	}
}

string removePunctuation(string s) {
	s.erase(remove_if(s.begin(), s.end(), &is_punct), s.end());
	return s;
}

string removeSpace(string s) {
	s.erase(remove_if(s.begin(), s.end(), ' '), s.end());
	return s;
}