#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<stdexcept>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;
class bad_mean :public logic_error
{
private:
	double v1;
	double v2;
public:
	explicit bad_mean(double a = 0, double b = 0, const string & s = "Error in ") :v1(a), v2(b), logic_error(s) {};
	virtual void mesg() const;
	virtual ~bad_mean() throw() = 0 {}
};
inline void bad_mean::mesg() const
{
	cout << "(" << v1 << ", " << v2 << ")";
}
class bad_hmean :public bad_mean
{
private:
	string funcname;
public:
	explicit bad_hmean(double a = 0, double b = 0, const string & s = "hmean", const string & n = "Error in ") : bad_mean(a, b, n), funcname(s) {};
	void mesg()const;
	virtual ~bad_hmean() throw() {}
};

inline void bad_hmean::mesg() const
{
	cout << what() << funcname << endl;
	cout << funcname;
	bad_mean::mesg();
	cout <<"invalid argument: a = -b\n";
}
class bad_gmean :public bad_mean
{
private:
	string funcname;
public:
	explicit bad_gmean(double a = 0, double b = 0,const string & s = "gmean",  const string & n = "error in ") :bad_mean(a, b, n), funcname(s) {};
	virtual ~bad_gmean() throw() {}
	void mesg()const;
};

inline void bad_gmean::mesg() const
{
	cout << what() << funcname << endl;
	cout << funcname;
	bad_mean::mesg();
	cout << "invalid argument: a = -b\n";
}
#endif // !TEST_H_

