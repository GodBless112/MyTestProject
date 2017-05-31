#include<iostream>
#include "test.h"
using namespace std;

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	:string(l), years(y)//, PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
	PairArray::operator=(PairArray(ArrayInt(yr, y), ArrayInt(bot, y)));
}

Wine::Wine(const char * l, int y)
	:string(l),years(y)
{
	PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));
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
	PairArray::Set(yr,bot);
}

string & Wine::Label()
{
	// TODO: 在此处插入 return 语句
	return (string &)*this;
}

void Wine::Show() const
{
	cout << "Wine: " << ((const string &)*this) << endl;
	cout << "\tYear\tBottles\n";
	PairArray::Show(years);
}

int Wine::sum() const
{
	return PairArray::Sum();
}
