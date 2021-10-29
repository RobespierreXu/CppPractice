#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <iostream>
using namespace std;

/*　迭代器也是一个智能指针 */
template <class T>
class iterator
{
public:
	/*迭代器不需要链表的指针部分，只需要链表的data部分 */
	reference operator*() const
	{
		return (*node).data;
	}

	pointer operator->() const
	{
		return &(operator*());
	}

private:
	T *px;
	long *pn;
};

#endif