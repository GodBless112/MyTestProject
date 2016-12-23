﻿// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include "test.h"
// constants
const int MIN_PER_HR = 60;
// function prototype
using namespace std;

bool newcustomer(double x);

int main()
{
	srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximun size of quene: ";
	int qs;
	cin >> qs;
	Quene line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR*hours;
	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double  min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enquene(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequene(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.quenecount();
	}
	//reporting results
	if (customers > 0)
	{
		cout << "Customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average quene size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}