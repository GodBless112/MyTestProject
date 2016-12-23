// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "aida and tosca:\n";
	cout << aida << tosca;
	temp = aida + tosca;
	cout << "aida+tosca:\n" << temp;
	temp = aida*1.17;
	cout << "aida*1.17:\n" << temp;
	cout << "10.0*Tosca:\n" << 10.0*tosca;

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
