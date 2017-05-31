// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
using namespace std;
// constants


// function prototype

int main(void)
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int years;
	cin >> years;
	Wine holding(lab, years);
	holding.GetBottles();
	holding.Show();
	
	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label()
		<< ": " << more.sum() << endl;
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

