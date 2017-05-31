// static.cpp -- using a static local variable
#include <iostream>
#include <string>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;

int main()
{
	using namespace SALES;
	double ar[3] = { 1.1,2.2,3.3 };
	Sales s1, s2;
	setSales(s1);
	setSales(s2, ar, 3);
	showSales(s1);
	showSales(s2);
	// code to keep window open for MSVC++
	//delete[]cf2; 不能删除放入指定区域的new生成的动态数组
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

