#include <iostream>
#include "test.h"
using std::cout;
void Stonewt::set_stn()
{
	stone = int(pounds) / Lbs_per_stn;
	pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);
}

void Stonewt::set_pds()
{
	pounds = stone*Lbs_per_stn + pds_left;
}

void Stonewt::set_int_pds()
{
	int_pounds = int(pounds);
}

Stonewt::Stonewt(double lbs, Mode form)
{
	mode = form;
	if (form == STN)
	{
		stone = int(lbs) / Lbs_per_stn;
		pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
		set_pds();
		set_int_pds();
	}
	else if (form == INTPD)
	{
		int_pounds = (int)lbs;
		pounds = lbs;
		set_stn();
	}
	else if (form == FPD)
	{
		pounds = lbs;
		set_int_pds();
		set_stn();
	}
	else
	{
		cout << "Incorrect 3rd argument to Stonewt()--";
		cout << "Stonewt set to 0\n";
		stone = pounds = pds_left = 0;
		mode = STN;
	}
}

Stonewt::Stonewt(int stn, double lbs, Mode form)
{
	mode = form;
	if (form == STN)
	{
		stone = stn;
		pds_left = lbs;
		set_pds();
		set_int_pds();
	}
	else if (form == INTPD)
	{
		int_pounds = int(stn*Lbs_per_stn + lbs);
		pounds = stn*Lbs_per_stn + lbs;
		set_stn();
	}
	else if (form == FPD)
	{
		pounds = stn*Lbs_per_stn + lbs;
		set_int_pds();
		set_stn();
	}
	else
	{
		cout << "Incorrect 3rd argument to Stonewt()--";
		cout << "Stonewt set to 0\n";
		stone = pounds = pds_left = 0;
		mode = STN;
	}
}


Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode = STN;
}

Stonewt::~Stonewt()
{
}

void Stonewt::stn_mode()
{
	mode = STN;
}

void Stonewt::pds_mode()
{
	mode = FPD;
}

void Stonewt::int_pds_mode()
{
	mode = INTPD;
}

Stonewt Stonewt::operator+(const Stonewt & s) const
{
	return Stonewt(pounds+s.pounds,mode);
}

Stonewt Stonewt::operator-(const Stonewt & s) const
{
	return Stonewt(pounds-s.pounds,mode);
}

Stonewt Stonewt::operator*(double n) const
{
	return Stonewt(pounds*n,mode);
}
Stonewt operator*(double n, const Stonewt & s)
{
	return Stonewt(s.pounds*n, s.mode);
}

std::ostream & operator<<(std::ostream & os, const Stonewt s)
{
	// TODO: 在此处插入 return 语句
	if (s.mode == Stonewt::STN)
		os << s.stone << " stone, " << s.pds_left << " pounds\n";
	else if (s.mode == Stonewt::INTPD)
		os << s.int_pounds << " pounds(int)\n";
	else if (s.mode == Stonewt::FPD)
		os << s.pounds << " pounds(double)\n";
	else
		os << "Error in type\n";
	return os;
}
Stonewt::operator int() const
{
	return pounds + 0.5;
}

Stonewt::operator double() const
{
	return pounds;
}




