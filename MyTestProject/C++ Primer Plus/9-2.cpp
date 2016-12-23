#include <iostream>
#include "test.h"
using namespace std;

int main()
{
	rect rplace;
	polar pplace;
	cout << "enter the x and y value: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";
	}
	cout << "BYE!.\n";
	while (1);
	return 0;
}
