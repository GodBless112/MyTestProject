// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
#include<vector>
// constants
// function prototype
const int LIM = 4;
using namespace std;
int main(void)
{
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker * pw[LIM] = { &bob,&bev,&w_temp,&s_temp };
	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << endl;
	}

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

