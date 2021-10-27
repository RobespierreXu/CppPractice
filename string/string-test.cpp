#include <iostream>
#include "mystring.h"
using namespace std;

ostream &
operator<<(ostream &os, const MyString &str)
{
	os << str.get_c_str();
	return os;
}

int main()
{
	MyString s1;
	MyString s2("hello");

	MyString *p = new MyString("hello2");
	MyString s3(s1);

	cout << s3 << endl;
	s3 = s2;
	cout << *p << endl;
	cout << s3 << endl;

	delete p;
}
