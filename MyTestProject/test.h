#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
template<typename T>
class matrix
{
private:
	vector<vector<T> > arr;
public:
	matrix(int rows, int cols) :arr(rows)
	{
		for (int i = 0; i < rows; i++)
		{
			arr[i].resize(cols);
		}
	}
	const vector<T> & operator[](int row) const
	{
		return arr[row];
	}
	vector<T> & operator[](int row)
	{
		return arr[row];
	}
	int numrows() const
	{
		return arr.size();
	}
	int numcols() const
	{
		reuturn numrows() ? arr[0].size() : 0;
	}
};
#endif // !TEST_H_

