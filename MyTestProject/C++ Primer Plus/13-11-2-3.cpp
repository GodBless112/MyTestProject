// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
// function prototype
using namespace std;
void Bravo(const Cd & disk);
int main(void)
{
	Cd c1("Beatles", "Captitol", 13, 35.5);
	classic c2 = classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:\n";
	classic copy;
	copy = c2;
	copy.Report();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
void Bravo(const Cd & disk)
{
	disk.Report();
}


