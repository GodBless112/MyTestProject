#pragma once
#ifndef TEST_H_
#define TEST_H_
#include <iostream>
class Stonewt
{
public:
	enum Mode { STN, INTPD, FPD };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	int int_pounds;
	Mode mode;
	void set_stn();
	void set_pds();
	void set_int_pds();
public:
	Stonewt(double lbs,Mode form);
	Stonewt(int stn, double lbs,Mode form);
	Stonewt();
	~Stonewt();
	void stn_mode();
	void pds_mode();
	void int_pds_mode();
	Stonewt operator+(const Stonewt & s) const;
	Stonewt operator-(const Stonewt & s) const;
	Stonewt operator*(double n) const;
	operator int() const;
	operator double() const;
	friend Stonewt operator*(double n, const Stonewt & s);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt s);
};
#endif // !TEST_H_

