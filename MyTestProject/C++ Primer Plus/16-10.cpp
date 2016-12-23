// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	cout << "Bye.\n";
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ri++)
		cout << *ri << " ";
	cout << endl;

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

