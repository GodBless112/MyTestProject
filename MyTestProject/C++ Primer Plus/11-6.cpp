// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << "coding time = ";
	coding.Show();
	cout << "fixing time = ";
	fixing.Show();
	total = coding + fixing;
	cout << "coding + fixing = ";
	total.Show();
	Time morefixing(3, 28);
	cout << "morefixing = ";
	morefixing.Show();
	total = morefixing.operator+(total);
	cout << "morefixing.operator+(total) = ";
	total.Show();
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
