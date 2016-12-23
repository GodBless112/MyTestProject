#include<cstring>
#include "test.h"
using namespace std;
baseDMA::baseDMA(const char * l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label,strlen(l)+1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	label = new char(strlen(rs.label) + 1);
	strcpy_s(label, strlen(rs.label)+1, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	// TODO: 在此处插入 return 语句
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label)+1, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Label: " << rs.label << endl;
	os << "Rating:" << rs.rating << endl;
	return os;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r) :baseDMA(l, r)
{
	strcpy_s(color,40, c);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) :baseDMA(rs)
{
	strcpy_s(color, 40, c);
	color[39] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
	os << (const baseDMA &)rs;
	os << "Color: " << rs.color << endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
	// TODO: 在此处插入 return 语句
	os << (const baseDMA &)rs;
	os << "Style: " << rs.style;
	return os;
}

hasDMA::hasDMA(const char * s, const char * l, int r) :baseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s)+1, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) :baseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s)+1, s);
}

hasDMA::hasDMA(const hasDMA & hs) :baseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style)+1, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	// TODO: 在此处插入 return 语句
	if (this == &rs)
		return *this;
	baseDMA::operator=(rs);
	delete[] style;
	style = new char[strlen(rs.style) + 1];
	strcpy_s(style, strlen(rs.style)+1, rs.style);
	return *this;
}
