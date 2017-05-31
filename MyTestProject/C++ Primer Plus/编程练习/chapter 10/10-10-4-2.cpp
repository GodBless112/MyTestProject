#include <iostream>
#include "test.h"
#include<cstring>
namespace SALES
{
	double calAverage(const double ar[], unsigned arrsize)
	{
		double sum = 0.0;
		for (int i = 0; i < arrsize; i++)
		{
			sum += ar[i];
		}
		return sum / arrsize;
	}
	double calMax(const double ar[], unsigned arrsize)
	{
		double max = ar[0];
		for (int i = 1; i < arrsize; i++)
		{
			if (ar[i] > max)
				max = ar[i];
		}
		return max;
	}
	double calMin(const double ar[], unsigned arrsize)
	{
		double min = ar[0];
		for (int i = 1; i < arrsize; i++)
		{
			if (ar[i] < min)
				min = ar[i];
		}
		return min;
	}
	Sales::Sales()
	{
		max = min = average = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			sales[i] = 0;
		}
	}
	Sales::Sales(const double ar[], int n)
	{
		unsigned times = n > QUARTERS ? QUARTERS : (unsigned)n;
		for (int i = 0; i < times; i++)
		{
			sales[i] = ar[i];
		}
		for (int i = times; i < QUARTERS; i++)
		{
			sales[i] = 0;
		}
		average = calAverage(sales, times);
		max = calMax(sales, times);
		min = calMin(sales, times);
	}
	void Sales::showSales() const
	{
		using namespace std;
		for (int i = 0; i < QUARTERS; i++)
			cout << sales[i] << endl;
		cout << "max; " << max << ", ";
		cout << "min; " << min << ", ";
		cout << "average; " << average << endl;
	}
	void Sales::setSales()
	{
		using namespace std;
		int flag = 0;
		int i;
		cout << "请输入4个数";
		for (i = 0; i < 4; i++)
		{
			cout << "请输入第" << i + 1 << "个数(q to quit)" << endl;
			while (!(cin >> sales[i]))
			{
				cin.clear();
				char ch = cin.get();
				if (ch == 'q' || ch == 'Q')
				{
					flag = 1;
					break;
				}

				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "请输入数字:";
			}
			if (flag == 1)
				break;
		}
		*this = Sales(sales, i);
	}
}