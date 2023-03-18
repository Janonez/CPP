#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

// const��Ա
// ��const���εġ���Ա��������֮Ϊconst��Ա������const�������Ա������ʵ�����θó�Ա����
// ������thisָ�룬�����ڸó�Ա�����в��ܶ�����κγ�Ա�����޸ġ�
//class A
//{
//public:
//	// �������const���γ�Ա�����Ļ���*this ӵ�����޸ĵ�Ȩ�ޣ�Ȩ�ޱ��Ŵ�
//	// const ���� *this
//	// this�����ͱ�� const A*
//	// �ڲ����ı��Ա�����ĳ�Ա����
//	// ��ü���const��const�������ͨ���󶼿��Ե���
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
//	// �������� i �� const i
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

//---------���캯��������ʼ���б�------------------------------------------------
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
	
	// ��������Ա�������������������������ݣ�
	// �����ʼ���б����ж��壬��ʹ�ó�ʼ���б��е�����
	A()
		:_x(1)
		,_a1(1) // ��ʼ���б�
		,_ref(_a1)
		, _bb(10)
	{
		_a1++;
		_a2++;
	}
private:
	// ���������������ȱʡֵ
	int _a1 = 2;
	int _a2 = 1;

	// �����ʼ��
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
			perror("malloc����ռ�ʧ��");
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
			perror("malloc����ռ�ʧ��");
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