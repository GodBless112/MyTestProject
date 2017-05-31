// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;
void display(const Stonewt & st, int n);
// function prototype
using namespace std;
int main()
{
	Stonewt stone[6] = {10.5,12.9,9.4};
	Stonewt temp(11.0);
	for (int i = 3; i < 6; i++)
	{
		double input;
		cout << "Please input " << "#" << i + 1 << " stone weight: ";
		cin >> input;;
		stone[i] = input;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << "#" << i + 1 << ": ";
		cout << stone[i];
	}
	int count = 0;
	Stonewt max=stone[0];
	Stonewt min=stone[0];
	for (int i = 0; i < 6; i++)
	{
		if (stone[i] > max)
			max = stone[i];
		if (stone[i] < min)
			min = stone[i];
		if (stone[i] >= temp)
			count++;
	}
	cout << "Max: " << max;
	cout << "Min: " << min;
	cout << "The numbers below or equal 11 stone: " << count<<endl;

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


