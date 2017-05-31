#include <iostream>
#include "test.h"

const int Mems = 5;
using namespace std;
int main()
{
	golf group[Mems];
	cout << "请输入" << Mems << "个数据" << endl;
	int i;
	for (i = 0; i < Mems; i++)
	{
		if (setgolf(group[i]) == 0)
			break;
	}
	for (int j = 0; j < i; j++)
		showgolf(group[j]);
	setgolf(group[0], "NewMainBuiding", 666);
	showgolf(group[0]);
	handicap(group[0], 999);
	showgolf(group[0]);
	while (1);
	return 0;
}
