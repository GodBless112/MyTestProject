// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Person one;
	Person two("Kingslayer");
	Person three("Lannister", "Imp");
	one.Show();
	one.FormalShow();
	two.Show();
	two.FormalShow();
	three.Show();
	three.FormalShow();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}


