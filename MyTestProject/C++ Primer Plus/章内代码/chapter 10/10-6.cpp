// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;

int main()
{
	{
		const Stock cc=Stock("OHMYGOD");
		cc.show();
		cout << "Using constructor to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();
		cout << "Assignment stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Niffy Foods", 10, 50.0);
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done.\n";

	}
	
	// code to keep window open for MSVC++
	//delete[]cf2; 不能删除放入指定区域的new生成的动态数组
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

