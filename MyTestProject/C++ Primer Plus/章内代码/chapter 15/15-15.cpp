#include "test.h"
using std::string;
Sales::bad_index::bad_index(int ix, const string & s) :std::logic_error(s), bi(ix)
{
}

Sales::Sales(int yy)
{
	year = yy;
	for (int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
	year = yy;
	int lim = (n < MONTHS) ? n : MONTHS;
	int i;
	for (int i = 0; i < lim; i++)
		gross[i] = gr[i];
	for (int i = lim; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

double & Sales::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const std::string & lb, int ix, const std::string & s)
	:lbl(lb), Sales::bad_index(ix, s)
{
}

LabeledSales::LabeledSales(const std::string & lb, int yy) : label(lb), Sales(yy)
{
}

LabeledSales::LabeledSales(const std::string & lb, int yy, const double * gr, int n)
	: label(lb), Sales(yy, gr, n)
{
}

double LabeledSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(label, i);
	return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	if (i < 0 || i >= MONTHS)
		throw nbad_index(label, i);
	return Sales::operator[](i);
}
