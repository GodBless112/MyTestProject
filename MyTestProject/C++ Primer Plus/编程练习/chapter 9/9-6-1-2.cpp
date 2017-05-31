#include <iostream>
#include <cstring>
#include "test.h"
using namespace std;

void setgolf(golf & g, const char *name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}
int setgolf(golf &g)
{
	cout << "请输入名字： ";
	cin.getline(g.fullname, Len);
	if (g.fullname[0] == '\0')
		return 0;
	cout << "请输入数值： ";
	while (!(cin >> g.handicap))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "大哥，输入数字啊！"<<endl;
	}
	while (cin.get() != '\n')
		continue;
	return 1;
}
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}
void showgolf(const golf & g)
{
	cout <<"Golfer: "<< g.fullname << endl <<"Handicap: "<< g.handicap << endl;
}