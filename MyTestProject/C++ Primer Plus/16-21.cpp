// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<valarray>
#include<algorithm>
#include<cstdlib>
#include "test.h"
// constants
// function prototype
using namespace std;
const int SIZE = 12;
typedef valarray<int> vint;
void Show(const vint &, int cols);
int main(void)
{
	int i;
	vint valint(SIZE);
	for (i = 0; i < SIZE; ++i)
		valint[i] = rand() % 10;
	cout << "Original array:\n";
	Show(valint, 3);
	vint vcol(valint[slice(1, 4, 3)]);
	cout << "Second column:\n";
	Show(vcol, 1);
	vint vrow(valint[slice(3, 3, 1)]);
	cout << "Second row:\n";
	Show(vrow, 3);
	valint[slice(2, 4, 3)] = 10;
	cout << "Set last column to 10:\n";
	Show(valint, 3);
	cout << "Set fisrt column to sum of next two:\n";
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
	Show(valint, 3);
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void Show(const vint & v, int cols)
{
	int lim = v.size();
	for (int i=0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if (i%cols == cols - 1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim%cols != 0)
		cout << endl;
}
