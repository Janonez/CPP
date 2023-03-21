#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
//int main()
//{
//	int* pp1 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	free(pp1);
//	delete p1;
//
//	int* pp2 = (int*)malloc(sizeof(int)*10);
//	int* p2 = new int[10];
//	free(pp2);
//	delete[] p2;
//
//	A* pp3 = (A*)malloc(sizeof(A));
//	free(pp3);
//
//	A* p3 = new A(10);
//	delete p3;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//
//	return 0;
//}

//int main()
//{
//	//int* p1 = new int;// 不会初始化
//	//int* pp1 = new int(0);
//
//	//int* p2 = (int*)malloc(sizeof(int));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//    // 动态申请一个int类型的空间
//    int* ptr4 = new int;
//    // 动态申请一个int类型的空间并初始化为10
//    int* ptr5 = new int(10);
//    // 动态申请10个int类型的空间
//    int* ptr6 = new int[10];
//    // 动态申请10个int类型的空间,并初始化前4个
//    int* ptr7 = new int[10] {1, 2, 3, 4};
//
//    delete ptr4;
//    delete ptr5;
//    delete[] ptr6;
//    delete[] ptr7;
//
//	return 0;
//}

class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }
private:
    int _a;
};
//int main()
//{
//    // new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//    A* p1 = (A*)malloc(sizeof(A));
//    A* p2 = new A(1);
//    free(p1);
//    delete p2;
//    // 内置类型是几乎是一样的
//    int* p3 = (int*)malloc(sizeof(int)); 
//    int* p4 = new int;
//    free(p3);
//    delete p4;
//    A* p5 = (A*)malloc(sizeof(A) * 10);
//    A* p6 = new A[10];
//    free(p5);
//    delete[] p6;
//    return 0;
//}

int main()
{
	// 失败了抛异常
	int* p1 = (int*)operator new(sizeof(int*));

	// 失败返回nullptr
	int* p2 = (int*)malloc(sizeof(int*));
	if (p2 == nullptr)
	{
		perror("malloc fail");
	}

	// 申请空间 operator new -> 封装malloc
	// 调用构造函数
	A* p5 = new A;

	// 先调用析构函数
	// 再operator delete p5指向的空间
	// operator delete -> free
	delete p5;

	// 申请空间 operator new[] ->perator new-> 封装malloc
	// 调用10次构造函数
	A* p6 = new A[10];
	
	// 先调用10次析构函数
	// 再operator delete[] p6指向的空间
	delete[] p6;

	return 0;
}