using namespace std;

#include "shared_ptr.h"

struct Foo
{
	void method(void){}
};

int main()
{
	shared_ptr<Foo> sp(new Foo);
	/* *符号使用掉以后就消耗掉了 */
	Foo f(*sp);

	/* 箭头符号得到的东西要用箭头符号继续作用下去 */
	sp->method();
}
