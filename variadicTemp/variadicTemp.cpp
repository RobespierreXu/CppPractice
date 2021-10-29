
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

/* 数量不定的模板参数
*/

void print()
{
}

template <typename T, typename... Types>
void print(const T &firstArg, const Types &..._args)
{
	cout << firstArg << endl;
	print(args...);
}
class A
{
public:
	static A &getInstance();
	//setup() {cout<<a<<endl;}

private:
	A();
	A(const A &rhs);
};

A &A::getInstance()
{
	static A a;
	return a;
}
class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

class E1 : virtual public A
{
};

class E2 : virtual public A
{
};

class D2 : public E1, public E2
{
};

void getmemory(char *p)
{
	p = (char *)malloc(100);

	strcpy(p, "hello world");
}

struct S
{
	char t : 4;
	char k : 4;
	unsigned short i : 8;
	//	unsigned long m;
};

int main()
{
	cout << "hello cpp" << endl;
	int *k1[10];
	int(*k2)[10];
	int (*k3)(int);
	int (*k4[10])(int);

	char *str = NULL;
	//	getmemory(str);

	S s;
	cout << sizeof(S);
	str = (char *)malloc(100);

	strcpy(str, "hello world");
	printf("%s/n", str);
	free(str);
}
//};