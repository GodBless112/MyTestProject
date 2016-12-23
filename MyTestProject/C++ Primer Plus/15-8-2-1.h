#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<stdexcept>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;
class bad_hmean:public logic_error
{
private:
	string funcname;
public:
	explicit bad_hmean(const string & s="hmean",const string & n="Functionname: hmean, error in hmean: invalid argument: a = -b") : logic_error(n),funcname(s){};
	string mesg();
	virtual ~bad_hmean() throw(){}
};
inline string bad_hmean::mesg()
{
	return "hmean: invalid argument: a = -b\n";
}
class bad_gmean:public logic_error
{
private:
	string funcname;
public:
	explicit bad_gmean(const string & s = "hmean", const string & n = "error in hmean") :logic_error(n), funcname(s) {};
	virtual ~bad_gmean() throw() {}
	string mesg();
};
inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}
#endif // !TEST_H_

