#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <vector>
// #include <stl_vector.h>

using namespace std;

class Observer
{
public:
	virtual void update(Subject *sub, int value) = 0;

}; 

class Subject
{
	int m_value;
	vector<Observer *> m_views;

public:
	/* 注册观察者 */
	void attach(Observer * obs)
	{
		// m_views.push_back(obs);
		// m_views.insert(m_views.size(),obs);
		m_views.push_back(obs);
	}

	void set_value(int value)
	{
		m_value = value;
		notify();
	}


	void notify()
	{
		for (auto &&i : m_views)
		{
			i->update(this, m_value);
		}
		
		cout << "Component A dtor()" << endl;
	}


};

#endif