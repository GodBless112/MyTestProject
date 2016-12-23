// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "weeding time = ";
	weeding.Show();
	cout << "waxing time = ";
	waxing.Show();
	total = weeding + waxing;
	cout << "total work time = ";
	total.Show();
	diff = weeding - waxing;
	cout << "weeding - waxing = ";
	diff.Show();
	adjusted = total*1.5;
	cout << "adjusted = ";
	adjusted.Show();
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
