#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
class String
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char * s);
	String();
	~String();
	String(const String & st);
	int length() { return len; }
	String & operator=(const String & st);
	String & operator=(const char * s);
	String & operator+(const char * s);
	void Stringlow();
	void Stringup();
	int has(const char s) const;
	friend String operator+(const char *s, const String st);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);
	friend bool operator<(const String &st1, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st1, const String &st2);
	friend String operator+(const String & st1, const String & st2);
	char & operator[](int i);
	const char & operator[](int i) const;
	static int HowMany();
};
#endif // !TEST_H_

