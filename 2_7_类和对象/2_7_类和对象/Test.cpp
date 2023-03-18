#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

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
class B
{
public:
	B(int b)
		:_b(0)
	{
		cout << "B()" << endl;
	}
private:
	int _b;
};
class A
{
public:
	
	// 如果在类成员处声明，就是用声明处的数据，
	// 如果初始化列表中有定义，则使用初始化列表中的数据
	A()
		:_x(1)
		,_a1(1) // 初始化列表
		,_ref(_a1)
		, _bb(10)
	{
		_a1++;
		_a2++;
	}
private:
	// 这里声明定义的是缺省值
	int _a1 = 2;
	int _a2 = 1;

	// 必须初始化
	const int _x;
	int& _ref;
	B _bb;
};

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		cout << "Stack(size_t capacity = 10)" << endl;

		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			exit(-1);
		}

		_size = 0;
		_capacity = capacity;
	}

	void Push(const DataType& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	Stack(const Stack& st)
	{
		cout << "Stack(const Stack& st)" << endl;
		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			exit(-1);
		}

		memcpy(_array, st._array, sizeof(DataType)*st._size);
		_size = st._size;
		_capacity = st._capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	DataType *_array;
	size_t    _size;
	size_t    _capacity;
};

class MyQueue
{
public:
	//MyQueue(int pushN, int popN)
	//	:_pushST(pushN)
	//	, _popST(popN)
	//{}

	MyQueue()
	{}

private:
	Stack _pushST;
	Stack _popST;
	int _size = 0;
};


int main()
{
	A aa;
	return 0;
}