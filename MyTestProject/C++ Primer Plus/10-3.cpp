// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;

int main()
{
	Stock cc;
	cc.acquires("Apple", 30, 66.90);
	cc.show();
	cc.buy(20, 70.10);
	cc.show();
	cc.sell(400, 80.9);
	cc.show();
	cc.buy(30000, 40.125);
	cc.show();
	cc.sell(30000, 0.125);
	cc.show();
	// code to keep window open for MSVC++
	//delete[]cf2; 不能删除放入指定区域的new生成的动态数组
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

