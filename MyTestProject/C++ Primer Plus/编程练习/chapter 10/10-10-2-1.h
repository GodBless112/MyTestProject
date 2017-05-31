#pragma once
#ifndef TEST_H_
#define TEST_H_
#include <string>
using std::string;
class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string & ln, const char * fn = "HeyYou");
	void Show() const;
	void FormalShow() const;
};
#endif // !TEST_H_
