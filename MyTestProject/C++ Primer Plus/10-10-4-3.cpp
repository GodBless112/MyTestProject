// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	using namespace SALES;
	double salesList[] = { 12.2, 11.16, 10.61, 16.24, 11.53};
	Sales salesBook(salesList,sizeof(salesList)/sizeof(salesList[0]));
	salesBook.showSales();
	Sales salesPen;
	salesPen.setSales();
	salesPen.showSales();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}


