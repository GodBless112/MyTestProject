#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
class StringBad
{
private:
	char * str;
	int len;
	static int num_strings;
public:
	StringBad(const char * s);
	StringBad();
	~StringBad();
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);

};
#endif // !TEST_H_

