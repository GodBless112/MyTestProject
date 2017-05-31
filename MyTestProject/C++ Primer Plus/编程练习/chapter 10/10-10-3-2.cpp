#include <iostream>
#include "test.h"
#include<cstring>
using namespace std;
Golf::Golf()
{
	strcpy_s(fullname, "no name");
	handicap = 0;
}

Golf::Golf(const char * name, int hc)
{
	strcpy_s(fullname, name);
	handicap = hc;
}

void Golf::setgolf()
{
	char name[Len];
	int hc;
	cout << "请输入名字： ";
	cin.getline(name, Len);
	if (fullname[0] == '\0')
		cout << "Wrong!";
	cout << "请输入数值： ";
	while (!(cin >> hc))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "大哥，输入数字啊！" << endl;
	}
	while (cin.get() != '\n')
		continue;
	*this = Golf(name, hc);

	// TODO: 在此处插入 return 语句
}

void Golf::hdicap(int hc)
{
	handicap = hc;
}

void Golf::showgolf() const
{
	cout << "Golfer: " << fullname << endl << "Handicap: " << handicap << endl;
}