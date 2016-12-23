#include <cstring>
#include<cstdlib>
#include<ctime>
#include "test.h"
using std::cout;
Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy_s(name, 20, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	strcpy_s(name, 20, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	// TODO: 在此处插入 return 语句
	if (this == &c)
		return *this;
	strcpy_s(name, 20, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}
ostream & operator<<(ostream & os, const Cow & c)
{
	// TODO: 在此处插入 return 语句
	os << "Cow name:   " << c.name << endl;
	os << "Cow hobby:  " << c.hobby << endl;
	os << "Cow weight: " << c.weight << endl;
	return os;
}
