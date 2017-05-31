// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include "test.h"
// constants
// function prototype
using namespace std;



int main()
{
	Cow cow1;
	Cow cow2("Mengniu", "grass", 1000);
	Cow cow3(cow2);
	cow1 = cow2;
	cout << cow1 << cow2 << cow3;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



