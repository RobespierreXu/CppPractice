#include "complex.h"
#include "test_cpp.h"
#include <iostream>
using namespace std;

using namespace nexp_1_arg_ctor;
/* 操作符重載的是os的操作符 */
/* 若返回類型改爲void，就無法對應cout << c1 << c2這種連串的輸出 */
ostream &
operator<<(ostream &os, const Fraction &x)
{
	return os << x.get_num() << '/'
			  << x.get_den();
}

int main()
{
	std::cout << "hello cpp" << std::endl;

	Fraction f(3, 5);
	Fraction d2 = f + 4;
	cout << d2 << endl;

	return 0;
}