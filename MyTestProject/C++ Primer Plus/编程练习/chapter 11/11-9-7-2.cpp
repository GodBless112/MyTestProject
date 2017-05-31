#include <iostream>
#include "test.h"
using std::cout;

Complex::Complex(double n1)
{
	real = n1;
	imaginary = 0.0;
}

Complex::Complex(double n1, double n2)
{
	real = n1;
	imaginary = n2;
}

Complex::Complex()
{
	real = imaginary = 0.0;
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex & c) const
{
	return Complex(real + c.real, imaginary + c.imaginary);
}

Complex Complex::operator-(const Complex & c) const
{
	return Complex(real - c.real, imaginary - c.imaginary);
}

Complex Complex::operator*(const Complex & c) const
{
	return Complex(real * c.real - imaginary*c.imaginary, real*c.imaginary + imaginary*c.real);
}

Complex Complex::operator*(double n) const
{
	return Complex(n*real, n*imaginary);
}

Complex Complex::operator~() const
{
	return Complex(real, -imaginary);
}
Complex operator*(double n, const Complex & c)
{
	return Complex(n*c.real, n*c.imaginary);
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	// TODO: 在此处插入 return 语句
	os << "(" << c.real << ", " << c.imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	// TODO: 在此处插入 return 语句
	cout << "Please input real: ";
	if (is >> c.real)
	{
		cout << "Please input imaginary: ";
		is >> c.imaginary;
	}
	return is;
}
