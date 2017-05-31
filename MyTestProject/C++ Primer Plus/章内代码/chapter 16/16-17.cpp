// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
#include "test.h"
// constants
// function prototype

int main(void)
{
	using namespace std;
	string letters;
	cout << "Enter the letter grouping(quit to quit): ";
	while (cin >> letters&&letters != "quit")
	{
		cout << "Permutations of " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))
			cout << letters << endl;
		cout << "Enter next letter grouping(quit to quit): ";
	}
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



