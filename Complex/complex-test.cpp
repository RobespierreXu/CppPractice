#include "complex.h"
#include <iostream>
using namespace std;

/* 操作符重載的是os的操作符 */
/* 若返回類型改爲void，就無法對應cout << c1 << c2這種連串的輸出 */
ostream&
operator << (ostream& os, const Complex& x)
{
	return os << '(' << real(x) << ','
			<< imag(x) << "i)";
}

int main()
{
	std::cout<< "hello cpp"<< std::endl;
	
	Complex c1(2,1);
	Complex c2;
	Complex* p = new Complex(4);


	cout << imag(c1) << endl;
	cout << real(c1) << endl;

	cout << c1.real() << endl;
	cout << c1.imag() << endl;

	c2 += c1;
	c2 += c1;

 	cout << c1 << endl;
	cout << c2 << endl;

/*	c2 = c1 + 5;
	c2 = 7 + c1;
	c2 = c1 + c2;
	c2 += c1;
	c2 += 3;
	c2 = -c1; */

	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	cout << conj(c1) << endl;
	cout << c1 << conj(c1) << endl;


	return 0;
}
//};