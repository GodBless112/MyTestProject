// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include "test.h"
// constants

// function prototype
using namespace std;

vector<int> lotto(int m, int n);
int main()
{
	int num_all;
	int num_ran;
	cout << "Please enter the number of the lotto spot:";
	cin >> num_all;
	cout << "Please enter the random selection number of the lotto spot:";
	cin >> num_ran;
	vector<int> winner;
	winner = lotto(num_all, num_ran);
	cout << "The winner is: \n";
	for (auto x : winner)
		cout << x << " ";
	cout << endl;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

vector<int> lotto(int m, int n)
{
	vector<int> random_list;
	for (int i = 0; i < m; i++)
		random_list.push_back(i + 1);
	random_shuffle(random_list.begin(), random_list.end());

	return vector<int>(random_list.begin(), random_list.begin() + n);
}