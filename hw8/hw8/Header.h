#pragma once
#include <cstdlib>
#include <iostream>
#include <algorithm>

//Function declarations
void printUsageInfo(string s);

bool isPalindrome(string s, bool case_flag, bool space_flag);

string toLowString(string s);

bool is_punct(char c);

string removePunctuation(string s, bool punc_flag);

string removeSpace(string s, bool space_flag);