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
namespace test
{
	class B
	{
	public:
		virtual B* foo()
		{
			return new B;
		}
	};
	class D : public B
	{
	public:
		virtual D* foo()
		{
			return new D;
		}
	};
}
#endif // !TEST_H_

