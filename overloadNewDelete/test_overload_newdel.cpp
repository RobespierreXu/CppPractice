#include <iostream>
#include "overload_new_delete.h"
using namespace std;

int main()
{
	cout << "sizeof (Foo) =" << sizeof(Foo) << endl;

	cout << "	Foo *pf = new Foo;" << endl;
	Foo *pf = new Foo;
	delete pf;
	cout << "-----------------------------------" << endl;

	cout << "	Foo *pf = new Foo(7);" << endl;
	Foo *pfi = new Foo(7);
	delete pfi;
	cout << "-----------------------------------" << endl;

	cout << "	Foo *pf = new Foo[5];" << endl;
	Foo *pArray = new Foo[5];
	delete[] pArray;
	cout << "-----------------------------------" << endl;

	cout << "	Foo *pf = ::new Foo;" << endl;
	Foo *pf2 = ::new Foo;
	::delete pf2;
	cout << "-----------------------------------" << endl;

	return 0;
}
