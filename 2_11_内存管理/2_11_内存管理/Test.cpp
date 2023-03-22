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

//class A
//{
//public:
//    A(int a = 0)
//        : _a(a)
//    {
//        cout << "A():" << this << endl;
//    }
//    ~A()
//    {
//        cout << "~A():" << this << endl;
//    }
//private:
//    int _a;
//};
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
//private:
//	int _a;
//};
//
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = new int[4];
//		_top = 0;
//		_capacity = 4;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		delete[] _a;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	// 失败了抛异常
//	int* p1 = (int*)operator new(sizeof(int*));
//
//	// 失败返回nullptr
//	int* p2 = (int*)malloc(sizeof(int*));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// 申请空间 operator new -> 封装malloc
//	// 调用构造函数
//	A* p5 = new A;
//
//	// 先调用析构函数
//	// 再operator delete p5指向的空间
//	// operator delete -> free
//	delete p5;
//
//	// 申请空间 operator new[] ->perator new-> 封装malloc
//	// 调用10次构造函数
//	A* p6 = new A[10];
//	
//	// 先调用10次析构函数
//	// 再operator delete[] p6指向的空间
//	delete[] p6;
//
//	int* p7 = new int[10];
//	free(p7);  // 正常释放，内置类型，不推荐
//	
//	A* p8 = new A;
//	//free(p8); // 少调用的析构函数
//	delete p8;
//	
//	Stack st;
//	
//	Stack* pst = new Stack;
//	delete pst;
//	//free(pst); // 少调用了析构函数 -- 有内存泄漏
//	
//	// 结论：new/malloc系列 有底层实现机制有关联交叉。不匹配使用
//	// 可能有问题，可能没问题，建议大家一定匹配使用
//	
//	A* p9 = new A[10];
//	//free(p9);
//	//delete p9;
//	delete[] p9;
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

// 泛型编程 -- 模板 typename和class都是关键字，用谁都可以
//template<typename T>
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class X,class Y>
//void Func()
//{
//
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	//Swap(a, b);
//	swap(a, b);
//	double c = 1.1, d = 2.2;
//	//Swap(c, d);
//	swap(c, d);
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double b1 = 10.22, b2 = 23.78;
//	// 实参传递给形参，自动推演模板类型
//	cout << Add(a1, a2) << endl;
//	cout << Add(b1, b2) << endl;
//	cout << Add((double)a1, b2) << endl;
//	cout << Add(a1, (int)b2) << endl;
//	
//	//Add(a1, b2);
//	cout << "------------" << endl;
//	// 显示实例化
//	cout << Add<int>(a1, b2) << endl;
//	cout << Add<double>(a1, b2) << endl;
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	//cout << "ADD" << endl;
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	//cout << "template" << endl;
//	return left + right;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(a, b); // 调用编译器特化的Add版本
//
//	Add(1.1, 2);
//
//	return 0;
//}


//typedef double STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Stack st1; // int
//	Stack st2; // double
//	// 不能同时定义两种类型
//
//	return 0;
//}

template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = new T[capacity];
		_top = 0;
		_capacity = capacity;
	}
	~Stack()
	{
		delete[] _a;
		_top = _capacity = 0;
	}
private:
	T* _a;
	size_t _top;
	size_t _capacity;
};

int main()
{
	// 类模板必须显示实例化
	Stack<int> st1; // int
	Stack<double> st2; // double
	return 0;
}