#include<iostream>
#include "test.h"
using namespace std;

abstr_emp::abstr_emp()
	:fname("no one"), lname("no one"), job("no one") {}

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
	: fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const
{
	cout << "Firstname: " << fname << endl;
	cout << "Lastname: " << lname << endl;
	cout << "Job is: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter firstname: ";
	getline(cin, fname);
	cout << "Enter lastname: ";
	getline(cin, lname);
	cout << "Enter position: ";
	getline(cin, job);
}

abstr_emp::~abstr_emp() {}

void abstr_emp::WriteAll(ofstream & ofs)
{
	ofs << fname << endl;
	ofs << lname << endl;
	ofs << job << endl;
}

void abstr_emp::GetAll(ifstream & ifs)
{
	getline(ifs, fname);
	getline(ifs, lname);
	getline(ifs, job);
}

ostream & operator<<(ostream & os, const abstr_emp & e)
{
	// TODO: �ڴ˴����� return ���
	os << e.fname << " " << e.lname << ", " << e.job << endl;
	return os;
}

employee::employee() :abstr_emp() {}

employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::WriteAll(ofstream & ofs)
{
	ofs << Employee << endl;
	abstr_emp::WriteAll(ofs);
}

void employee::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
}

manager::manager()
	: abstr_emp(), inchargeof(0) {}

manager::manager(const string & fn, const string & ln, const string & j, int ico)
	: inchargeof(ico), abstr_emp(fn, ln, j) {}

manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m)
	: abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	(cin >> inchargeof).get();
}

void manager::WriteAll(ofstream & ofs)
{
	ofs << Manager << endl;
	abstr_emp::WriteAll(ofs);
	ofs << inchargeof << endl;
}

void manager::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	ifs >> inchargeof;
}

fink::fink()
	:abstr_emp() {}

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const string & rpo)
	: abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e)
	: abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	(cin >> reportsto).get();
}

void fink::WriteAll(ofstream & ofs)
{
	ofs << Fink << endl;
	abstr_emp::WriteAll(ofs);
	ofs << reportsto << endl;
}

void fink::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	ifs >> reportsto;
}

highfink::highfink() :abstr_emp(), manager(), fink() {}

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink & h)
	: abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << manager::InChargeOf() << endl;
	cout << "Reportsto: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> manager::InChargeOf();
	cout << "Enter reportsto:";
	(cin >> fink::ReportsTo()).get();
}

void highfink::WriteAll(ofstream & ofs)
{
	ofs << Highfink << endl;
	abstr_emp::WriteAll(ofs);
	manager::writeinchargeof(ofs);
	fink::writereportsto(ofs);
}

void highfink::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	manager::getinchargeof(ifs);
	fink::getreportsto(ifs);
}


