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
	Stonewt incognito(275,Stonewt::FPD);
	Stonewt wolfe(285.7,Stonewt::STN);
	Stonewt taft(21, 8,Stonewt::INTPD);
	Stonewt temp;
	cout << "The celebrity weighted ";
	cout<<incognito;
	cout << "The detective weighted ";
	cout << wolfe;
	cout << "The president weighted ";
	cout << taft;
	temp = incognito + wolfe;
	cout << "incognito + wolfe = " << temp;
	temp = taft * 10.0;
	cout << "taft * 10 = " << temp;
	temp = 10.0 * taft;
	cout << "10 * taft = " << temp;
	cout << "No stone left unearned\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}




