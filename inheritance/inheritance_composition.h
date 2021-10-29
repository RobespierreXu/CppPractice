#ifndef __INHER_COMP_H__
#define __INHER_COMP_H__

#include <iostream>
using namespace std;

class BaseA;
class DerivedA;
class ComponentA;
class ComponentB;

class ComponentA
{
public:
	ComponentA()
	{
		cout << "Component A ctor()" << endl;
	}
	~ComponentA()
	{
		cout << "Component A dtor()" << endl;
	}
private:
	int b;
};

class ComponentB
{
public:
	ComponentB()
	{
		cout << "Component B ctor()" << endl;
	}
	~ComponentB()
	{
		cout << "Component B dtor()" << endl;
	}};

class BaseA
{
public:
	BaseA()
	{
		cout << "Base A ctor()" << endl;
	}
~BaseA()
	{
		cout << "Base A dtor()" << endl;
	}
	void OnFileOpen()
	{
		cout << "dialog..." << endl;
		cout << "check file status..." << endl;
		cout << "open file ..." << endl;

		Serialize();

		cout << "close file" << endl;
		cout << "update all views..." << endl;
	}

	virtual void Serialize(){};

private:
	ComponentA a;
};

class DerivedA : public BaseA
{
public:
	DerivedA()
	{
		cout << "Derived A ctor()" << endl;
	}
	~DerivedA()
	{
		cout << "Derived A dtor()" << endl;
	}
	virtual void Serialize()
	{
		cout << "CDoc::Serialize()" << endl;
	}

private:
	ComponentB b;
};

#endif