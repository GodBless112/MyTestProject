#pragma once
#ifndef TEST_H_
#define TEST_H_
#include <string>
using std::string;
class Golf
{
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf();
	Golf(const char * name, int hc);
	void setgolf();
	void hdicap(int hc);
	void showgolf() const;
};
#endif // !TEST_H_
