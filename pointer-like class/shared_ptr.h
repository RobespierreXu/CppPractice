#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include <iostream>
using namespace std;

template <class T>
class shared_ptr
{
public:


	T &operator*() const
	{
		return *px;
	}

	
	T *operator->() const
	{
		return px;
	}

	shared_ptr(T *p) : px(p) {}

private:
	T *px;
	long *pn;
};

#endif