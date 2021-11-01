#ifndef __NEW_DEL_H__
#define __NEW_DEL_H__

/* 重载类的new delete operator */
#include <string>
#include <iostream>
using namespace std;

class Foo
{
public:
	int _id;
	long _data;
	string _str;

public:
	Foo() : _id(0)
	{
		cout << "default ctor.this=" << this << " id = " << _id << endl;
	}
	Foo(int i) : _id(i)
	{
		cout << "ctor.this=" << this << " id = " << _id << endl;
	}

	// virtual
	~Foo() { cout << "dtor.this=" << this << " id=" << _id << endl; }

	// size是自动被填充的，无需在调用时关注
	static void *operator new(size_t size)
	{
		Foo *p = (Foo *)malloc(size);
		cout << "class operator new size = " << size << " return :" << p << endl;
		return p;
	}

	static void operator delete(void* pdead, size_t size = 0)
	{
		cout << "class operator delete size = " << size << " p :" << pdead << endl;
		free(pdead);
	}

	// size是自动被填充的，无需在调用时关注
	static void *operator new[](size_t size)
	{
		Foo *p = (Foo *)malloc(size);
		cout << "class operator new[] size = " << size << " return :" << p << endl;
		return p;
	}
	
	static void operator delete[](void* pdead, size_t size = 0)
	{
		cout << "class operator delete[] size = " << size << " p :" << pdead << endl;
		free(pdead);
	}

};


#endif