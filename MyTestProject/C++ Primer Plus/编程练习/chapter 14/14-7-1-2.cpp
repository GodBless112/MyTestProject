#include<iostream>
#include "test.h"
using namespace std;

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	:string(l), years(y), pa(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char * l, int y)
	:string(l),years(y)
{
}

void Wine::GetBottles()
{
	ArrayInt yr(years), bot(years);
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> yr[i];
		cout << "Enter bottles for that year: ";
		cin >> bot[i];
	}
	while (cin.get() != '\n')
		continue;
	pa.Set(yr,bot);
}

string & Wine::Label()
{
	// TODO: 在此处插入 return 语句
	return (string &)*this;
}

void Wine::Show() const
{
	cout << "Wine: " << ((string &)*this) << endl;
	cout << "\tYear\tBottles\n";
	pa.Show(years);
}

int Wine::sum() const
{
	return pa.Sum();
}
