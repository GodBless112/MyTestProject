#pragma once
#ifndef TEST_H_
#define TEST_H_
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };//两种表示形式：直角坐标和极坐标
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, Vector & v);
	};
}
#endif // !TEST_H_


