#include<cstring>
#include "test.h"
using namespace std;

ostream & Student::arr_out(ostream & os) const
{
	// TODO: 在此处插入 return 语句
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
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
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0.0;
}

const std::string & Student::Name() const
{
	// TODO: 在此处插入 return 语句
	return name;
}

double & Student::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	return scores[i];
}

double Student::operator[](int i) const
{
	return scores[i];
}

std::istream & operator>>(std::istream & is, Student & stu)
{
	// TODO: 在此处插入 return 语句
	is >> stu.name;
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	// TODO: 在此处插入 return 语句
	getline(is, stu.name);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	// TODO: 在此处插入 return 语句
	os << "Scores for " << stu.name << ":\n";
	stu.arr_out(os);
	return os;
}
