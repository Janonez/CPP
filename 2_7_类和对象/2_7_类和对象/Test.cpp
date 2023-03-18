#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// const成员
// 将const修饰的“成员函数”称之为const成员函数，const修饰类成员函数，实际修饰该成员函数
// 隐含的this指针，表明在该成员函数中不能对类的任何成员进行修改。
class A
{
public:
	// 如果不用const修饰成员函数的话，*this 拥有了修改的权限，权限被放大
	// const 修饰 *this
	// this的类型变成 const A*
	// 内部不改变成员变量的成员函数
	// 最好加上const，const对象和普通对象都可以调用
	void Print() const
	{
		cout << _a << endl;
	}
private:
	int _a = 10;
};
void Func(const A& x)
{
	x.Print();
}
int main()
{
	A aa;
	aa.Print();

	A bb;
	bb.Print();

	Func(aa);

	cout << &aa << endl;
	cout << &bb << endl;
	return 0;
}