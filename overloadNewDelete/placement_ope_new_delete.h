#ifndef __PLACEMENT_NEW_DEL_H__
#define __PLACEMENT_NEW_DEL_H__

/* 重载类的new delete operator */
#include <string>
#include <iostream>
#include <exception>
using namespace std;

class Bad
{
};

class Foo2
{
public:
	Foo2()
	{
		cout << "Foo::Foo()" << endl;
	}
	Foo2(int i)
	{
		cout << "Foo::Foo(int)" << endl;
		throw Bad();
	}

	// virtual
	~Foo2() { cout << "dtor.this=" << this << endl; }

	// size是自动被填充的，无需在调用时关注
	static void *operator new(size_t size)
	{
		Foo2 *p = (Foo2 *)malloc(size);
		cout << "class operator new size = " << size << " return :" << p << endl;
		return p;
	}

	// standard placement new，在固定指针处分配空间
	static void *operator new(size_t size, void *start)
	{
		start = (Foo2 *)malloc(size);
		cout << "class operator new size = " << size << " return :" << start << endl;
		return start;
	}

	// 额外增加分配空间
	static void *operator new(size_t size, long extra)
	{
		cout << "class operator new extra size = " << size + extra << endl;
		return malloc(size + extra);
	}

	// 额外增加分配空间，并赋予初值
	static void *operator new(size_t size, long extra, char init)
	{
		cout << "class operator new extra size init = " << size + extra << endl;
		return malloc(size + extra);
	}

	static void operator delete(void *pdead, size_t size = 0)
	{
		cout << "class operator delete(void *, size_t) size = " << size << " p :" << pdead << endl;
		free(pdead);
	}

	static void operator delete(void *pdead, void *p2)
	{
		cout << "class operator delete(void *, void*) size = "
			 << " p :" << pdead << endl;
		free(pdead);
	}

	static void operator delete(void *pdead, long extra)
	{
		cout << "class operator delete(void *, long) size = "
			 << " p :" << pdead << endl;
		free(pdead);
	}

	static void operator delete(void *pdead, long extra, char init)
	{
		cout << "class operator delete(void *, long, char) size = "
			 << " p :" << pdead << endl;
		free(pdead);
	}

	// size是自动被填充的，无需在调用时关注
	static void *operator new[](size_t size)
	{
		Foo2 *p = (Foo2 *)malloc(size);
		cout << "class operator new[] size = " << size << " return :" << p << endl;
		return p;
	}

	static void operator delete[](void *pdead, size_t size = 0)
	{
		cout << "class operator delete[] size = " << size << " p :" << pdead << endl;
		free(pdead);
	}

private:
	int m_i;
};

#endif