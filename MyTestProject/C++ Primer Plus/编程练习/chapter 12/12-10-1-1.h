#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
using namespace std;
class Cow
{
private:
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * name, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	friend ostream & operator<<(ostream & os, const Cow & c);
};
#endif // !TEST_H_

