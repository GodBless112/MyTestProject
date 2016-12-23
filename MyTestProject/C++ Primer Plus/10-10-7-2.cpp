#include <iostream>
#include "test.h"

Plorg::Plorg(const char ar[Len], int n)
{
	strcpy_s(name, ar);
	CI = n;
}

void Plorg::showPlorg() const
{
	using namespace std;
	cout << "name: " << name << ", CI: " << CI << endl;
}

void Plorg::reset(int n)
{
	CI = n;
}
