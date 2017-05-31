// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<valarray>
#include<algorithm>
#include<cctype>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	vector<double> data;
	double temp;
	cout << "Enter numbers (<=0 to quit):\n";
	while (cin >> temp&&temp > 0)
		data.push_back(temp);
	sort(data.begin(), data.end());
	int size = data.size();
	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];
	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0*sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);
	for (i = 0; i < size; i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}

	
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
