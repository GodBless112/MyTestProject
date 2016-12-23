#include<cstring>
#include "test.h"
using namespace std;

ABC::ABC(const char * f, int l)
{
	fullname = new char[strlen(f) + 1];
	strcpy_s(fullname, strlen(f) + 1, f);
	level = l;
}

ABC::ABC(const ABC & a)
{
	fullname = new char[strlen(a.fullname) + 1];
	strcpy_s(fullname, strlen(a.fullname) + 1, a.fullname);
	level = a.level;
}

ABC::~ABC()
{
	delete[] fullname;
}

ABC & ABC::operator=(const ABC & a)
{
	// TODO: 在此处插入 return 语句
	if (this == &a)
		return *this;
	delete[] fullname;
	fullname = new char[strlen(a.fullname) + 1];
	strcpy_s(fullname, strlen(a.fullname) + 1, a.fullname);
	level = a.level;
}

void ABC::View() const
{
	cout << "Fullname: " << fullname << endl;
	cout << "Level:    " << level << endl;
}

baseDMA::baseDMA(const char * l, int r, const char * f, int lv) :ABC(f, lv)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs) :ABC(rs)
{
	label = new char(strlen(rs.label) + 1);
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
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
	ABC::operator=(rs);
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

void baseDMA::View() const
{
	ABC::View();
	cout << "Label:    " << label << endl;
	cout << "Rating:   " << rating << endl;
}

lacksDMA::lacksDMA(const char * c, const char * f, int lv) :ABC(f, lv)
{
	strcpy_s(color, 39, c);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const ABC & rs) :ABC(rs)
{
	strcpy_s(color, 39, c);
	color[39] = '\0';
}

void lacksDMA::View() const
{
	ABC::View();
	cout << "Color:    " << color << endl;
}

hasDMA::hasDMA(const char * s, const char * f, int lv) :ABC(f, lv)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char * s, const ABC & rs) :ABC(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA & hs) :ABC(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
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
	ABC::operator=(rs);
	delete[] style;
	style = new char[strlen(rs.style) + 1];
	strcpy_s(style, strlen(rs.style) + 1, rs.style);
	return *this;
}

void hasDMA::View() const
{
	ABC::View();
	cout << "Style:    " << style << endl;
}
