// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	using std::cout;
	using std::endl;
	Plorg p1;
	Plorg p2("useless", 20);
	p1.showPlorg();
	p2.showPlorg();
	p1.reset(415);
	p1.showPlorg();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

