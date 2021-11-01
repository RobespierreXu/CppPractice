#include <iostream>
#include "placement_ope_new_delete.h"
using namespace std;

int main()
{

	Foo2 start;
	Foo2* p1 = new Foo2;
	Foo2* p2 = new(&start) Foo2;
	Foo2* p3 = new(100) Foo2;
	Foo2* p4 = new(100, 'a') Foo2;
	Foo2* p5 = new Foo2(1);
	Foo2* p6 = new(&start) Foo2(1);
	Foo2* p7 = new(100) Foo2(1);
	Foo2* p8 = new(100, 'a') Foo2(1);
	/* 
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
	cout << "-----------------------------------" << endl; */

	return 0;
}
