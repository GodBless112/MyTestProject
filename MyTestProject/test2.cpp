//#include<iostream>
//#include "test.h"
//using namespace std;
//
//IntCell::IntCell(int initialValue)
//{
//	storeValue = new int(initialValue);
//}
//
//IntCell::IntCell(const IntCell & rhs)
//{
//	storeValue = new int(*rhs.storeValue);
//}
//
//IntCell::~IntCell()
//{
//	delete storeValue;
//}
//
//IntCell & IntCell::operator=(const IntCell & rhs)
//{
//	// TODO: 在此处插入 return 语句
//	if (this == &rhs)
//		return *this;
//	*storeValue = *rhs.storeValue;
//	return *this;
//}
//
//int IntCell::read() const
//{
//	return *storeValue;
//}
//
//void IntCell::write(int x)
//{
//	*storeValue = x;
//}
//
//ostream & operator<<(ostream & os, const IntCell & rhs)
//{
//	// TODO: 在此处插入 return 语句
//	os << *rhs.storeValue << endl;
//	return os;
//}
//
//bool operator<(const IntCell & r1, const IntCell & r2)
//{
//	if (*r1.storeValue < *r2.storeValue)
//		return true;
//	else
//		return false;
//}
