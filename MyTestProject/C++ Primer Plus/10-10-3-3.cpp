// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Golf one("Tiger Woods",99);
	one.showgolf();
	Golf two;
	two.showgolf();
	two.setgolf();
	two.showgolf();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}


