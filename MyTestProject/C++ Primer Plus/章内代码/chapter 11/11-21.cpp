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
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int =>";
	cout << "Poppins: " << int(poppins) << " pounds.\n";
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
