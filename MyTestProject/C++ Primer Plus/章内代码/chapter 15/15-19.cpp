// static.cpp -- using a static local variable
#include<iostream>
#include "test.h"
// constants
// function prototype
using namespace std;
void change(const int* pt, int n);
int main(void)
{
	int pop1 = 38383;
	const int pop2 = 2000;
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

	cout << "Bye.\n";

	// code to keep window open for MSVC++
	 cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void change(const int * pt, int n)
{
	int * pc;
	pc = const_cast<int*>(pt);
	*pc += n;
}
