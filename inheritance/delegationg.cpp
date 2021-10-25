using namespace std;

#include <vector>
#include <queue>
#include <iostream>

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


class A
{
public:
	A():a(1){};
	void printA(){cout<<a<<endl;}
	int a;
};
 
class B : public A
{
};
 
class C : public A
{
};
 
class D :  public B ,  public C
{
};
 
class E1 : virtual public A
{
};
 
class E2 : virtual public A
{
};
 
class D2:  public E1 ,  public E2
{
};
 

int main()
{
	cout<< "hello cpp"<< endl;
	
	A a;
	B b;
	C c;
	D d;
	D2 d2;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<sizeof(c)<<endl;
	cout<<sizeof(d)<<endl;
	cout<<sizeof(d2)<<endl;

	d.B::a = 10;
	d.C::printA();

	d2.printA();

}
//};