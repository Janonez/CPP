#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <assert.h>
//using namespace std;

// const成员
// 将const修饰的“成员函数”称之为const成员函数，const修饰类成员函数，实际修饰该成员函数
// 隐含的this指针，表明在该成员函数中不能对类的任何成员进行修改。
//class A
//{
//public:
//	// 如果不用const修饰成员函数的话，*this 拥有了修改的权限，权限被放大
//	// const 修饰 *this
//	// this的类型变成 const A*
//	// 内部不改变成员变量的成员函数
//	// 最好加上const，const对象和普通对象都可以调用
//	void Print() const
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a = 10;
//};
//void Func(const A& x)
//{
//	x.Print();
//}
////int main()
////{
////	A aa;
////	aa.Print();
////
////	A bb;
////	bb.Print();
////
////	Func(aa);
////
////	cout << &aa << endl;
////	cout << &bb << endl;
////	return 0;
////}
//
//class Array
//{
//public:
//	int& operator[](int i)
//	{
//		assert(i < 10);
//		return _a[i];
//	}
//	// 函数重载 i 和 const i
//	const int& operator[](int i) const
//	{
//		assert(i < 10);
//		return _a[i];
//	}
//private:
//	int _a[10];
//	int _size;
//};
//
//void Func1(const Array& a)
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << a[i] << " ";
//	}
//}
//int main()
//{
//	Array a;
//	for (int i = 0; i < 10; ++i)
//	{
//		a[i] = i;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << a[i] << " ";
//		
//	}
//	cout << endl;
//
//	Func1(a);
//
//	return 0;
//}

//---------构造函数——初始化列表------------------------------------------------
//class B
//{
//public:
//	B(int b)
//		:_b(0)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _b;
//};
//class A
//{
//public:
//	
//	// 如果在类成员处声明，就是用声明处的数据，
//	// 如果初始化列表中有定义，则使用初始化列表中的数据
//	A()
//		:_x(1)
//		,_a1(1) // 初始化列表
//		,_ref(_a1)
//		, _bb(10)
//	{
//		_a1++;
//		_a2++;
//	}
//private:
//	// 这里声明定义的是缺省值
//	int _a1 = 2;
//	int _a2 = 1;
//
//	// 必须初始化
//	const int _x;
//	int& _ref;
//	B _bb;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		cout << "Stack(size_t capacity = 10)" << endl;
//
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		memcpy(_array, st._array, sizeof(DataType)*st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType *_array;
//	size_t    _size;
//	size_t    _capacity;
//};
//
//class MyQueue
//{
//public:
//	//MyQueue(int pushN, int popN)
//	//	:_pushST(pushN)
//	//	, _popST(popN)
//	//{}
//
//	MyQueue()
//	{}
//
//private:
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};
//
//
//int main()
//{
//	A aa;
//	return 0;
//}

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////构造函数不仅可以构造与初始化对象，对于单个参数或者除第一个参数无默认值其余均有默认值的构造函数，还具有类型转换的作用
//class A
//{
//public:
//	//单个参数:没有使用explicit修饰，具有类型转换作用
//	A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	// explicit修饰构造函数，禁止类型转换
//	/*explicit A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}*/
//	A(int a1,int a2)
//		: _a1(a1)
//		, _a2(a2)
//	{
//		cout << "A(int a1,int a2)" << endl;
//	}
//	// 拷贝构造
//	A(const A& aa)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main()
//{
//	// 整体定义对象，但成员没有定义
//	// 初始化列表才是类成员的定义 
//	//Date d1(2001,1,1);
//	
//	// 单参数构造函数 C++98
//	A aa1(1); // 构造函数
//	A aa2 = 1;// 隐式类型转换,但是编译器会进行优化，直接构造
//
//	//A& ref = 10;// 这是错误的，在这里发生了隐式类型转换，生成了临时拷贝，但是临时拷贝是具有常性的，这样权限被放大
//	const A& ref = 10;
//
//	// 多参数构造函数 C++11
//	A aa3(1, 1);
//	A aa4 = { 2,2 };
//
//	int i = 1;
//	double d = i;// 隐式类型转换
//	return 0;
//}

// 面试题：实现一个类，计算程序中创建出了多少个类对象。
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//	A(const A& aa)
//	{
//		++count;
//	}
//	// 静态成员函数 -- 没有this指针，可以直接在类中调用
//	static int GetCount()
//	{
//		// _a++; 不可访问非静态成员
//		return count;
//	}
//private:
//	// 不属于某个对象，属于所有对象，属于整个类
//	static int count;// 这里是声明
//	// static int count = 0; 
//	// 这属于缺省值，在 构造函数 中的 初始化列表 使用，
//	// 初始化列表 初始的是非静态成员（类的对象）
//
//	int _a = 0;
//};
//int A::count = 0;// 这里是定义
//
//void func(A aa)
//{}
//
//int main()
//{
//	A aa1(1);
//	A aa2(aa1);
//	func(aa1);
//	A aa3 = 1;
//	A aa4[10];
//
//	cout << A::GetCount() << endl;
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int _h = 1;
//public:
//	// 内部类 -- 跟A是独立的，只是受A的类域限制
//	// 如果放在private中，则不能访问B类
//	class B // B天生是A的有源，B可以访问A类
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;
//			cout << a._h << endl;
//		}
//	private:
//		int _b;
//	};
//};
//
//int main()
//{
//	A aa;
//	cout << sizeof(aa) << endl;
//
//	A::B bb;
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;

		if (this != &aa)
		{
			_a = aa._a;
		}

		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{
}

void func2(const A& aa)
{
}

//int main()
//{
//	A aa1 = 1; // 构造+拷贝构造 -》 优化为直接构造
//	func1(aa1); // 无优化
//	func1(2); // 构造+拷贝构造 -》 优化为直接构造
//	func1(A(3)); // 构造+拷贝构造 -》 优化为直接构造
//
//	cout << "----------------------------------" << endl;
//
//	func2(aa1);  // 无优化
//	func2(2);    // 无优化
//	func2(A(3)); // 无优化
//
//
//	return 0;
//}

A func3()
{
	A aa;
	return aa; 
}

A func4()
{
	return A();
}

// 深度探索C++对象模型

int main()
{
	func3(); // 优化为构造

	A aa1 = func3(); // 优化为一个构造

	cout << "****" << endl;
	A aa2;
	aa2 = func3();  // 不能优化

	cout << "---------------------------" << endl;
	func4(); // 构造+拷贝构造 -- 优化为构造
	A aa3 = func4(); // 优化为一个构造

	return 0;
}