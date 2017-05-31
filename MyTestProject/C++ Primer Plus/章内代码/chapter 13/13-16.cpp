// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	baseDMA shirt("Portablely", 8);
	lacksDMA balloon("red","Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	cout << shirt << endl;
	cout << "Displaying lacksDMA object:\n";
	cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result od hasDMA assinment:\n";
	cout << map2 << endl;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


