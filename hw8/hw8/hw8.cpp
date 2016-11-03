#include "Header.h"

using namespace std;

int main(int argc, char argv[], char envarg[]) {
	
	if (!argc && !argv) printUsageInfo(argv);
	
	isPalindrome();
	return 0;
}