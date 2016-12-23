#include <iostream>
#include "test.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showMove() const
{
	using namespace std;
	cout << "x = " << x << ", y = " << y<<endl;
}

Move Move::add(const Move & m) const
{
	Move temp;
	temp.x = x + m.x;
	temp.y = y + m.y;
	return temp;
}

void Move::reset(double a, double b)
{
	x = a; 
	y = b;
}
