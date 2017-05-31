// static.cpp -- using a static local variable
#include<iostream>
#include<iomanip>
#include<cmath>
#include<exception>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers: ";
	int sum = 0;
	int input;
	try {
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure & bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";
	}
	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



