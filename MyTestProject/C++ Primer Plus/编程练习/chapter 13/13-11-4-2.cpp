#include<cstring>
#include "test.h"
using namespace std;

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, 19, st);
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 19, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	// TODO: 在此处插入 return 语句
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 19, p.style);
	bottles = p.bottles;
}

Port & Port::operator+=(int b)
{
	// TODO: 在此处插入 return 语句
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	// TODO: 在此处插入 return 语句
	if (bottles > b)
		bottles -= b;
	else
	{
		cout << "Subtract error, set bottles to zero.\n";
		bottles = 0;
	}
	return *this;
}

void Port::show() const
{
	cout << "Brand:    " << brand << endl;
	cout << "Kind:     " << style << endl;
	cout << "Bottles:  " << bottles << endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
	// TODO: 在此处插入 return 语句
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	// TODO: 在此处插入 return 语句
	os << (const Port &)vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) :Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	// TODO: 在此处插入 return 语句
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

void VintagePort::Show() const
{
	Port::show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year:     " << year << endl;
}
