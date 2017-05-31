// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
const int STKS = 4;
int main()
{
	Stock stocks[STKS] = {
		Stock("NanoSmart",12,20.0),
		Stock(),
		Stock("Moonlithic",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};
	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	top->show();
	// code to keep window open for MSVC++
	//delete[]cf2; 不能删除放入指定区域的new生成的动态数组
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

