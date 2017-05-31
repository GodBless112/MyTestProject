// static.cpp -- using a static local variable
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include "test.h"
// constants

// function prototype

using namespace std;
const int MAX = 10;
const char *file = "test.txt";
int main()
{
	abstr_emp *pc[MAX];
	ifstream fin(file);
	char ch;
	int i = 0;
	if (fin.is_open())
	{
		cout << "Here are the contents of file " << file << ":\n";
		int classtype;
		i = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case Employee:
				pc[i] = new employee;
				break;
			case Manager:
				pc[i] = new manager;
				break;
			case Fink:
				pc[i] = new fink;
				break;
			case Highfink:
				pc[i] = new highfink;
				break;
			}
			cout << classtype << endl;
			pc[i]->GetAll(fin);
			pc[i++]->ShowAll();
		}
		for (int j = 0; j < i; j++)
		{
			delete pc[j];
		}		
	}
	else
	{
		cerr << "Can't open file " << file << endl;
		exit(EXIT_FAILURE);
	}
	fin.clear();
	fin.close();
	ofstream fout(file, ios_base::out|ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open the file " << file << " to output.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Please enter the data type you want to add.\n" << left
		<< setw(15) << "e to employee" << setw(15) << "m to manager"<<endl
		<< setw(15) << "f to fink" << setw(15) << "h to highfink"<<endl
		<< "q to quit.\n" << right;
	int index = 0;
	while (cin.get(ch).get() && ch != 'q'&&index < MAX)
	{
		switch (ch)
		{
		case 'e':
			pc[index] = new employee;
			pc[index++]->SetAll();
			break;
		case 'm':
			pc[index] = new manager;
			pc[index++]->SetAll();
			break;
		case 'f':
			pc[index] = new fink;
			pc[index++]->SetAll();
			break;
		case 'h':
			pc[index] = new highfink;
			pc[index++]->SetAll();
			break;
		default:
			cout << "Try again!.\n";
			break;
		}
		if (index > MAX)
			break;
		cout << "Please enter the data type you want to add.\n" << left
			<< setw(15) << "e to employee" << setw(15) << "m to manager"<<endl
			<< setw(15) << "f to fink" << setw(15) << "h to highfink"<<endl
			<< "q to quit.\n" << right;
	}
	for (int j = 0; j < index; j++)
	{
		pc[j]->WriteAll(fout);
		delete pc[j];
	}
	fout.close();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the contents of file " << file << ":\n";
		int classtype;
		i = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case Employee:
				pc[i] = new employee;
				break;
			case Manager:
				pc[i] = new manager;
				break;
			case Fink:
				pc[i] = new fink;
				break;
			case Highfink:
				pc[i] = new highfink;
				break;
			}
			cout << classtype << endl;
			pc[i]->GetAll(fin);
			pc[i++]->ShowAll();
		}
		for (int j = 0; j < i; j++)
			delete pc[j];
	}
	else
	{
		cerr << "Can't open file " << file << endl;
		exit(EXIT_FAILURE);
	}
	fin.close();
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


