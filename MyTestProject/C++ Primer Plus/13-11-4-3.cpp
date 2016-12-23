// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
// constants
const int NUM = 2;
const int MAXLINE = 50;
// function prototype
using namespace std;

int main(void)
{
	Port wine1("Gallo", "tawny", 20);
	VintagePort wine2("Romance Conti", 10, "The Noble", 1876);
	VintagePort wine3("Merlot", 30, "Old Velvet", 1888);
	cout << "Displaying Port object:\n";
	wine1.show();
	cout << wine1 << endl;
	cout << "Displaying VintagePort object:\n";
	wine2.show();
	cout << wine2 << endl;
	cout << "Displaying VintagePort object:\n";
	wine3.show();
	cout << wine3 << endl;
	cout << "Gallo add ten bottles:\n";
	wine2 += 10;
	cout << wine1 << endl;
	cout << "Romance Conti add ten bottles:\n";
	wine2 += 10;
	cout << wine2 << endl;
	cout << "Meilot minus ten bottles:\n";
	wine3 -= 100;
	cout << wine3 << endl;
	Port wine4(wine2);
	cout << "Result of Port copy:\n";
	cout << wine4 << endl;
	VintagePort wine5;
	wine5 = wine3;
	cout << "Result of VintagePort assignment:\n";
	cout << wine5 << endl;


	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

