#include <iostream>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//	return a / b;
//}
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ�-- ֱ�ӳ�ȥ
//	// 2�����p2����new ���쳣����Σ�-- �ͷŵ�һ��
//	// 3�����div���������ֻ����쳣����Σ� -- �ͷ�ǰ����
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
//		throw; //���쳣
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
//		throw; //���쳣
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
// ��ָ��һ��ʹ��
// ��������

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
		throw invalid_argument("��0����");
	return a / b;
}

void Func()
{
	// 1�����p1����new ���쳣����Σ�-- ֱ�ӳ�ȥ
	// 2�����p2����new ���쳣����Σ�-- �ͷŵ�һ��
	// 3�����div���������ֻ����쳣����Σ� -- �ͷ�ǰ����
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
//	// ����ԭ��: û��ʵ�ֿ������죬ͬһ��ռ��ͷ�������
//	return 0;
//}

#include "SmartPtr.h"
#include <memory>

void test_auto()
{
	auto_ptr<int> ap1(new int(1));
	auto_ptr<int> ap2(ap1);

	*ap1 = 10; // ����Ȩת�Ƶ���ap1���գ����ܷ���
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