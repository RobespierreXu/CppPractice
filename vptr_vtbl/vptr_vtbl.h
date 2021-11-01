#ifndef __VPTR_VTBL_H__
#define __VPTR_VTBL_H__

#include <iostream>
using namespace std;

class BaseA;
class DerivedA;
class ComponentA;
class ComponentB;

class A
{
public:
	virtual void vfunc1() {};
	virtual void vfunc2() {};
	void func1();
	void func2();

// private:
	int m_data1, m_data2;
};

class A1
{
public:
	void func1();
	void func2();

private:
	int m_data1, m_data2;
};

class B : public A
{
public:
	virtual void vfunc1() {};
	void func2();

private:
	int m_data3;
};

class C : public B
{
public:
	virtual void vfunc1() {};
	void func2();

private:
	int m_data1;
};

class C2 : public B
{
public:
	virtual void vfunc1() {};
	void func2();

private:
	int m_data1, m_data4;
};
#endif