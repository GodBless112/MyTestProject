// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
// constants
const int NUM = 2;
const int MAXLINE = 50;
// function prototype
using namespace std;

int main(void)
{
	ABC * p_DMA[NUM];
	hasDMA map;
	char temp[MAXLINE];
	int templv;
	char kind;
	for (int i = 0; i < NUM; i++)
	{
		cout << "Enter DMA's fullname: ";
		cin.getline(temp, MAXLINE);
		cout << "Enter DMA's level: ";
		cin >> templv;
		cout << "Enter 1 for baseDMA or "
			 << "2 for lacksDMA or "
			 << "3 for hasDMA: ";
		while (cin >> kind && (kind != '1'&&kind != '2'&&kind!='3'))
			cout << "Enter either 1 or 2 or 3: ";
		if (kind == '1')
		{
			char templabel[MAXLINE];
			int temprating;
			cout << "Enter baseDMA's label: ";
			cin.get();
			cin.getline(templabel, MAXLINE);
			cout << "Enter baseDMA's rating: ";
			cin >> temprating;
			p_DMA[i] = new baseDMA(templabel, temprating, temp, templv);
		}
		else if(kind=='2')
		{
			char tempcolor[MAXLINE];
			cout << "Enter lacksDMA's color: ";
			cin.get();
			cin.getline(tempcolor, MAXLINE);
			p_DMA[i] = new lacksDMA(tempcolor, temp, templv);
		}
		else
		{
			char tempstyle[MAXLINE];
			cout << "Enter hasDMA's style: ";
			cin.get();
			cin.getline(tempstyle, MAXLINE);
			p_DMA[i] = new hasDMA(tempstyle, temp, templv);
			map=hasDMA(tempstyle, temp, templv);
		}
	/*	while (cin.get() != '\n')
			continue;*/
	}
	cout << endl;
	for (int i = 0; i < NUM; i++)
	{
		p_DMA[i]->View();
		cout << endl;
	}
	hasDMA tempDMA = map;
	tempDMA.View();
	for (int i = 0; i < NUM; i++)
		delete p_DMA[i];
	cout << "Done.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}