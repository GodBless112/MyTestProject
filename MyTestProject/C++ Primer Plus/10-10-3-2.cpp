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
	cout << "���������֣� ";
	cin.getline(name, Len);
	if (fullname[0] == '\0')
		cout << "Wrong!";
	cout << "��������ֵ�� ";
	while (!(cin >> hc))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "��磬�������ְ���" << endl;
	}
	while (cin.get() != '\n')
		continue;
	*this = Golf(name, hc);

	// TODO: �ڴ˴����� return ���
}

void Golf::hdicap(int hc)
{
	handicap = hc;
}

void Golf::showgolf() const
{
	cout << "Golfer: " << fullname << endl << "Handicap: " << handicap << endl;
}