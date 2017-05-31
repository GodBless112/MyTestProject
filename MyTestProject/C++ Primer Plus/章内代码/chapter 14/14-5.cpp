#include<cstring>
#include "test.h"
using namespace std;

ostream & Student::arr_out(ostream & os) const
{
	// TODO: �ڴ˴����� return ���
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0.0;
}

const std::string & Student::Name() const
{
	// TODO: �ڴ˴����� return ���
	return (const string &)*this;
}

double & Student::operator[](int i)
{
	// TODO: �ڴ˴����� return ���
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

std::istream & operator>>(std::istream & is, Student & stu)
{
	// TODO: �ڴ˴����� return ���
	is >> (string &)stu;
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	// TODO: �ڴ˴����� return ���
	getline(is, (string &)stu);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	// TODO: �ڴ˴����� return ���
	os << "Scores for " << (string &)stu << ":\n";
	stu.arr_out(os);
	return os;
}
