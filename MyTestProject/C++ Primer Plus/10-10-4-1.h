#pragma once
#ifndef TEST_H_
#define TEST_H_
#include <string>
using std::string;
namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(const double ar[], int n);
		void setSales();
		void showSales() const;
	};
}
#endif // !TEST_H_
