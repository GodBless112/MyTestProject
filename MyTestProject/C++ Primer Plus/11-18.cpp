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
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	cout << "The celebrity weighted ";
	incognito.show_stn();
	cout << "The detective weighted ";
	wolfe.show_stn();
	cout << "The president weighted ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;
	cout << "After dinner, the celebrity weighted ";
	incognito.show_stn();
	cout << "After dinner, the President weighted ";
	taft.show_lbs();
	display(422, 2);
	cout << "No stone left unearned\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}
