#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <cmath>
#include <iostream>

//template <typename T>

class Complex
{
public:
	Complex	(double r = 0, double i = 0)
		: re(r), im(i)
	{ }

	Complex& operator += (const Complex& /* 表示常数，不被改变 */);

	double real () const /* 表示函数不改变数据内容 */ { return re; }
	double imag () const /* 表示函数不改变数据内容 */ { return im; }

private:
	double re, im;

	friend Complex& __doapl (Complex*, const Complex&);
};

 

#endif