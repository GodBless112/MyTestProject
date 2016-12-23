#pragma once
#ifndef TEST_H_
#define TEST_H_
class Plorg
{
private:
	static const int Len = 20;
	char name[Len];
	int CI;
public:
	Plorg(const char ar[Len] = "Plorga", int ci = 50);
	void showPlorg() const;
	void reset(int n = 0);
};

#endif // !TEST_H_

