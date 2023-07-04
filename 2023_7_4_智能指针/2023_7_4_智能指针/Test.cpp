#include <iostream>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？-- 直接出去
//	// 2、如果p2这里new 抛异常会如何？-- 释放第一个
//	// 3、如果div调用这里又会抛异常会如何？ -- 释放前两个
//	int* p1 = new int;
//
//	int* p2 = nullptr;
//	try
//	{
//		p2 = new int;
//	}
//	catch (...)
//	{
//		delete p1;
//		throw; //抛异常
//	}
//
//	try
//	{
//		cout << div() << endl;
//	}
//	catch (...)
//	{
//		delete p1;
//		delete p2;
//		throw; //抛异常
//	}
//
//	delete p1;
//	delete p2;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

// RAII
// 像指针一样使用
// 拷贝问题

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		: _ptr(ptr)
	{}
	~SmartPtr()
	{
		cout << "delete: " << _ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}

void Func()
{
	// 1、如果p1这里new 抛异常会如何？-- 直接出去
	// 2、如果p2这里new 抛异常会如何？-- 释放第一个
	// 3、如果div调用这里又会抛异常会如何？ -- 释放前两个
	SmartPtr<int> sp1(new int(2));
	SmartPtr<int> sp2(new int(3));

	cout << div() << endl;	

	*sp1 = 10;
	cout << *sp1 << endl;
	cout << *sp2 << endl;
}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main()
//{
//	SmartPtr<int> sp1(new int(1));
//	SmartPtr<int> sp2(sp1);
//	// 报错原因: 没有实现拷贝构造，同一块空间释放了两次
//	return 0;
//}

#include "SmartPtr.h"
#include <memory>

void test_auto()
{
	auto_ptr<int> ap1(new int(1));
	auto_ptr<int> ap2(ap1);

	*ap1 = 10; // 管理权转移导致ap1悬空，不能访问
	*ap2 = 20;
}

void test_unique()
{
	unique_ptr<int> up1(new int(1));
	//unique_ptr<int> up2(up1);
}

int main()
{
	// Janonez::test1();
	// test_auto();
	// Janonez::test_unique();
	// test_unique();
	// Janonez::test_shared();
	Janonez::test_shared_safe();
	return 0;
}