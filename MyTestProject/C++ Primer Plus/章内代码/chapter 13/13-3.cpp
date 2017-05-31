// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
const int MIN_PER_HR = 60;
// function prototype
using namespace std;

bool newcustomer(double x);

int main(void)
{
	using std::endl;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}