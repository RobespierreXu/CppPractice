
#include <vector>
#include <queue>
#include <iostream>
#include "vptr_vtbl.h"

using namespace std;

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(C2) << endl;

	A* p1 = new A();
	
	// class指针同data指针不同，因为有虚指针的存在
	cout << p1 << endl;

	// 打印虚指针
	cout << (int *)(&p1) << endl;
	cout << &(p1->m_data1) << endl;
	cout << &(p1->m_data2) << endl;

	B* p2 = new B();
	C* p3 = new C();
	return 0;
}
