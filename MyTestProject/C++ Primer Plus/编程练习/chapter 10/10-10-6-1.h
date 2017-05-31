#pragma once
#ifndef TEST_H_
#define TEST_H_
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showMove() const;
	Move add(const Move & m) const;
	void reset(double a = 0, double b = 0);
};

#endif // !TEST_H_

