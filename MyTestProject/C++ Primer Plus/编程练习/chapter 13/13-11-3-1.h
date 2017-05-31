#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
class ABC
{
private:
	char * fullname;
	int level;
public:
	ABC(const char * f = "null", int l = 0);
	ABC(const ABC & a);
	virtual ~ABC();
	ABC & operator=(const ABC & a);
	virtual void View() const = 0;
};
class baseDMA :public ABC
{
private:
	char * label;
	int rating;
public:
	baseDMA(const char * l = "null", int r = 0, const char * f = "null", int lv = 0);
	baseDMA(const baseDMA & rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	virtual void View() const;
};

class lacksDMA :public ABC
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * f = "null", int lv = 0);
	lacksDMA(const char * c, const ABC & rs);
	virtual void View() const;
};
class hasDMA :public ABC
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * f = "null", int lv = 0);
	hasDMA(const char * s, const ABC & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & rs);
	virtual void View() const;
};
#endif // !TEST_H_

