// static.cpp -- using a static local variable
#include <cstdlib>
#include<iostream>
#include<new>
#include "test.h"
// constants
// function prototype
using namespace std;
struct Big
{
	double stuff[20000];
};
int main(void)
{
	Big * pb;
	try {
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[10000];
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc & ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



