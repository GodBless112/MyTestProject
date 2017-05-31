#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<string>
#include<valarray>
using namespace std;
template<class T1, class T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	void Set(const T1 & yr,const T2 & bt);
	int Sum() const;
	void Show(int y) const;
	Pair(const T1 & aval, const T2 &bval) :year(aval), bottles(bval) {}
	Pair() {};
};
template<class T1, class T2>
inline void Pair<T1, T2>::Set(const T1 & yr, const T2 & bt)
{
	year = yr;
	bottles = bt;
}
template<class T1, class T2>
inline int Pair<T1, T2>::Sum() const
{
	return bottles.sum();
}

template<class T1, class T2>
inline void Pair<T1, T2>::Show(int y) const
{
	for (int i = 0; i < y; i++)
		cout << "\t" << year[i] << "\t" << bottles[i] << endl;
}
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
class Wine:private string,private PairArray
{
	//PairArray pa;
	int years;
public:
	Wine() {};
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	string & Label();
	void Show() const;
	int sum() const;
};
#endif // !TEST_H_

