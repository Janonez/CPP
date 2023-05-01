#include <iostream>

using namespace std;

//class Base 
//{
//public:
//	virtual void func1() 
//	{ 
//		cout << "Base::func1" << endl; 
//	}
//	/*virtual void func2() 
//	{ 
//		cout << "Base::func2" << endl; 
//	}
//	void func3()
//	{
//		cout << "Base::func3" << endl;
//	}*/
//private:
//	int a;
//};
//class Derive :public Base 
//{
//public:
//	virtual void func1() 
//	{ 
//		cout << "Derive::func1" << endl; 
//	}
//	/*virtual void func4()
//	{ 
//		cout << "Derive::func4" << endl; 
//	}*/
//private:
//	int b;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)();
//
////void PrintfVFTalbe(VF_PTR table[])
//void PrintfVFTalbe(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	PrintfVFTalbe((VF_PTR*)*(long long*)&b);
//	PrintfVFTalbe((VF_PTR*)*(long long*)&d);
//
//	PrintfVFTalbe(*(VF_PTR**)&b);
//	PrintfVFTalbe(*(VF_PTR**)&d);
//
//
//	// 虚表是什么阶段生成的？          -- 编译
//	// 对象中虚表指针什么时候初始化的？ -- 构造函数的初始化列表
//	// 虚表存在哪里？                 -- 代码段（常量区）
//
//	return 0;
//}

//int main()
//{
//	Base b;
//	Derive d;
//
//	int x = 0;
//	static int y = 0;
//	int* z = new int;
//	const char* p = "xxxxxxxxxxxxxxxxxxx";
//
//	printf("栈对象：%p\n", &x);
//	printf("堆对象：%p\n", z);
//	printf("静态区对象：%p\n", &y);
//	printf("常量区对象：%p\n", p);
//	printf("b对象虚表：%p\n", *((long long*)&b));
//	printf("d对象虚表：%p\n", *((long long*)&d));
//	return 0;
//}

/// ////////////////////////////////////////////////////////////////////
//class Base1
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base1::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base1::func2" << endl;
//	}
//private:
//	int b1;
//};
//class Base2
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base2::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base2::func2" << endl;
//	}
//private:
//	int b2;
//};
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void func1()
//	{
//		cout << "Derive::func1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Derive::func3" << endl;
//	}
//private:
//	int d1;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)();
//
////void PrintfVFTalbe(VF_PTR table[])
//void PrintfVFTalbe(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Derive d;
//	PrintfVFTalbe(*(VF_PTR**)&d);
//	Base2* ptr2 = &d;
//	PrintfVFTalbe((VF_PTR*)*(long long*)ptr2);
//
//	return 0;
//}

//int main()
//{
//	Derive d;
//	Base1* ptr1 = &d;
//	Base2* ptr2 = &d;
//
//	ptr1->func1();
//	ptr2->func1();
//	return 0;
//}

//class A
//{
//public:
//	virtual void func1()
//	{}
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func3()
//	{}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func1()
//	{
//
//	}
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}
