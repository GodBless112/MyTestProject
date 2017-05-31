// static.cpp -- using a static local variable
#include<iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	cout << "Enter an integer:";
	int n;
	cin >> n;
	cout << "n		n*n\n";
	cout << n << "		" << n*n << "(decimal)\n";
	cout << hex;
	cout << n << "		";
	cout << n*n << "(hexadecimal)\n";
	cout << oct << n << "		" << n*n << "(octal)\n";
	dec(cout);
	cout << n << "		" << n*n << "(decimal)\n";
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



