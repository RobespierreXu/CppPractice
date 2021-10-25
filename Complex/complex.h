#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <cmath>

#include <iostream>

//template <typename T>

/* 0 */
/* 前置声明区 forward declaration */
class Complex;
Complex &__doapl(Complex *, const Complex &);
ostream&
operator << (ostream& os, const Complex& x);


/* 1 */
/* 类声明区 class declaration */
class Complex
{
public:
	Complex(double r = 0, double i = 0)
		: re(r), im(i)
	{
	}

	// 操作符重载 成员函数
	Complex &operator+=(const Complex & /* 表示常数，不被改变 */);
	Complex conj();

	double real() const /* 表示函数不改变数据内容 */ { return re; }
	double imag() const /* 表示函数不改变数据内容 */ { return im; }

private:
	double re, im;

	friend Complex &__doapl(Complex *, const Complex &);
};

/* 2 */
/* 类定义区 class definition */

// 全域函数 global，沒有全局pointer

inline Complex & // 传递者callee无需知道接收者caller是以reference的形式接收的,也可以不用reference，但是慢
__doapl(Complex *ths, const Complex &r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline double
imag(const Complex &x)
{
	return x.imag();
}

inline double
real(const Complex &x)
{
	return x.real();
}

/* cout << +c1;  */
inline Complex
operator+(const Complex &x)
{
	return x;
}

/* cout << -c1; */
inline Complex
operator-(const Complex &x)
{
	return Complex(-real(x), -imag(x));
}

/* c2 = c1 + c2;
return the result of 2 Complex */
inline Complex
operator+(const Complex &x, const Complex &y)
{
	return Complex(x.real() + y.real(),
				   x.imag() + y.imag());
}

/* c2 = c1 + 5;
return the result of the sum of a Complex and a real number */
inline Complex
operator+(const Complex &x, const double &y)
{
	return Complex(x.real() + y,
				   x.imag());
}

/* c2 = 7 + c1;
return the result of the sum of a real number and a Complex */
inline Complex
operator+(const double &x, const Complex &y)
{
	return Complex(x + y.real(),
				   y.imag());
}

/* c1 == c2;  */
inline bool
operator==(const Complex &x, const Complex &y)
{
	return (real(x) == real(y)) && (imag(x) == imag(y));
}

/* c1 == 0;  */
inline bool
operator==(const Complex &x, const double &y)
{
	return (real(x) == y) && (imag(x) == 0);
}

/* 1 == c1;  */
inline bool
operator==(const double &x, const Complex &y)
{
	return (x == real(y)) && (0 == imag(y));
}

/* c1 != c2;  */
inline bool
operator!=(const Complex &x, const Complex &y)
{
	return (real(x) != real(y)) || (imag(x) != imag(y));
}

/* c1 != 0;  */
inline bool
operator!=(const Complex &x, const double &y)
{
	return (real(x) != y) || (imag(x) != 0);
}

/* 1 != c1;  */
inline bool
operator!=(const double &x, const Complex &y)
{
	return (x != real(y)) || (0 != imag(y));
}

/* 共軛複數  */
inline Complex
conj(const Complex &x)
{
	return Complex(real(x), -imag(x));
}

/* 若返回類型改爲void，就無法對應cout << c1 << c2這種連串的輸出
ostream&
operator << (ostream& os, const Complex& x)
{
	return os << '(' << real(x) << ','
			<< imag(x) << 'i)';
}

// 成員函数 global，默認帶有this
inline Complex & // 这里因为使用者有可能用法 c3 += c2 += c1;所以不能用void来作为返回值
Complex::operator+=(const Complex &r)
{
	return __doapl(this, r);
}

/* 共軛複數  */
inline Complex
Complex::conj()
{
	return Complex(this->real(), -this->imag());
}

#endif