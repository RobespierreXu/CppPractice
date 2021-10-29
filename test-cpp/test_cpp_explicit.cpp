#include "complex.h"
#include "test_cpp.h"
#include <iostream>
using namespace std;
using namespace exp_1_arg_ctor;

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

	Fraction f(8, 5);

	/* 不能隱式地進行轉換 對比 conv */
/* 	double d = f;         
	double d1 = 4 + f;
	Fraction d2 = f + 4;

	cout << "d:" << d << endl;

	cout << "d1:" << d1 << endl;
	cout << "d2:" << d2 << endl;	 */
	return 0;
}
