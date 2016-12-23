// static.cpp -- using a static local variable
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include "test.h"
// constants

// function prototype

using namespace std;

int main(void)
{
	ostringstream outstr;
	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's ots capacity in GB? ";
	cin >> cap;
	outstr << "The hard disk " << hdisk << " has a capacity of "
		<< cap << " gigabytes.\n";
	string result = outstr.str();
	cout << result;
	outstr.str("");
	outstr << "Can I use it again?" << endl;
	result += outstr.str();
	cout << result;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



