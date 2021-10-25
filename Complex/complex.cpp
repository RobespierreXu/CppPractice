#include "complex.h"
#include <iostream>
using namespace std;

/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/
Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

inline Complex&    // 传递者callee无需知道接收者caller是以reference的形式接收的,也可以不用reference，但是慢
__doapl (Complex* ths, const Complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;

}

inline Complex&    // 这里因为使用者有可能用法 c3 += c2 += c1;所以不能用void来作为返回值
Complex::operator+= (const Complex& r)
{
	return __doapl (this, r);
}

ostream& 
operator << (ostream& os, const Complex& x)
{
	return os << '(' << x.real () << ',' << x.imag () << ')';
}

int main()
{
	cout<< "hello cpp"<< endl;
	
	Complex c1(2,1);
	Complex c2;
	Complex* p = new Complex(4);

	string a;
	a.find()

	cout << c1.real() << endl;
	cout << c1.imag() << endl;

	c2 += c1;
	c2 += c1;

 	cout << c1 << endl;
	cout << c2 << endl;

/*	c2 = c1 + 5;
	c2 = 7 + c1;
	c2 = c1 + c2;
	c2 += c1;
	c2 += 3;
	c2 = -c1;

	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	cout << conj(c1) << endl; */

	return 0;
}
//};