#include <iostream>
#include <cstring>
#include "test.h"
using namespace std;
namespace SALES
{
	void setSales(Sales &s, const double ar[], int n)
	{
		memset(s.sales, 0.0f, 4 * sizeof(double));
		double min = ar[00], max = ar[0], avg = 0;
		int i;
		for (i = 0; i < ((n < 4) ? n : 4); i++)
		{
			s.sales[i] = ar[i];
			avg += ar[i];
		}
		max = min = s.sales[0];
		for (int j=1; j < 4; j++)
		{
			if (ar[j] > max)
				max = s.sales[j];
			if (ar[j] < min)
				min = s.sales[j];
		}
		avg /= i;
		s.max = max;
		s.min = min;
		s.average = avg;
	}
	void setSales(Sales &s)
	{
		double max=0, min=0, avg=0;
		int i, flag=0;
		memset(s.sales, 0.0f, 4*sizeof(double));
		for (i = 0; i < 4; i++)
		{
			cout << "请输入第" << i + 1 << "个数(q to quit)" << endl;
			while (!(cin >> s.sales[i]))
			{
				cin.clear();
				char ch = cin.get();
				if (ch == 'q'||ch == 'Q')
				{
					flag = 1;
					break;
				}

				while (cin.get()!='\n')
				{
					continue;
				}
				cout << "请输入数字:";
			}
			if (flag == 1)
				break;
			avg += s.sales[i];			
		}
		max = min = s.sales[0];
		for (int j = 1; j < 4; j++)
		{
			if (s.sales[j] > max)
				max = s.sales[j];
			if (s.sales[j] < min)
				min = s.sales[j];
		}
		if (i == 0)
			s.average = 0;
		else
			s.average = avg/i;
		s.max = max;
		s.min = min;
	}
	void showSales(const Sales &s)
	{
		int n = sizeof(s.sales) / sizeof(double);
		for (int i = 0; i < n; i++)
			cout << s.sales[i] << endl;
		cout << "max; " << s.max<<", ";
		cout << "min; " << s.min<<", ";
		cout << "average; " << s.average<<endl;
	}
}
