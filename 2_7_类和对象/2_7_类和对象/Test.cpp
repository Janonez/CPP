#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <assert.h>
//using namespace std;

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
//	// ��������Ա�������������������������ݣ�
//	// �����ʼ���б����ж��壬��ʹ�ó�ʼ���б��е�����
//	A()
//		:_x(1)
//		,_a1(1) // ��ʼ���б�
//		,_ref(_a1)
//		, _bb(10)
//	{
//		_a1++;
//		_a2++;
//	}
//private:
//	// ���������������ȱʡֵ
//	int _a1 = 2;
//	int _a2 = 1;
//
//	// �����ʼ��
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
//			perror("malloc����ռ�ʧ��");
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
//			perror("malloc����ռ�ʧ��");
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
////���캯���������Թ������ʼ�����󣬶��ڵ����������߳���һ��������Ĭ��ֵ�������Ĭ��ֵ�Ĺ��캯��������������ת��������
//class A
//{
//public:
//	//��������:û��ʹ��explicit���Σ���������ת������
//	A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	// explicit���ι��캯������ֹ����ת��
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
//	// ��������
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
//	// ���嶨����󣬵���Աû�ж���
//	// ��ʼ���б�������Ա�Ķ��� 
//	//Date d1(2001,1,1);
//	
//	// ���������캯�� C++98
//	A aa1(1); // ���캯��
//	A aa2 = 1;// ��ʽ����ת��,���Ǳ�����������Ż���ֱ�ӹ���
//
//	//A& ref = 10;// ���Ǵ���ģ������﷢������ʽ����ת������������ʱ������������ʱ�����Ǿ��г��Եģ�����Ȩ�ޱ��Ŵ�
//	const A& ref = 10;
//
//	// ��������캯�� C++11
//	A aa3(1, 1);
//	A aa4 = { 2,2 };
//
//	int i = 1;
//	double d = i;// ��ʽ����ת��
//	return 0;
//}

// �����⣺ʵ��һ���࣬��������д������˶��ٸ������
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
//	// ��̬��Ա���� -- û��thisָ�룬����ֱ�������е���
//	static int GetCount()
//	{
//		// _a++; ���ɷ��ʷǾ�̬��Ա
//		return count;
//	}
//private:
//	// ������ĳ�������������ж�������������
//	static int count;// ����������
//	// static int count = 0; 
//	// ������ȱʡֵ���� ���캯�� �е� ��ʼ���б� ʹ�ã�
//	// ��ʼ���б� ��ʼ���ǷǾ�̬��Ա����Ķ���
//
//	int _a = 0;
//};
//int A::count = 0;// �����Ƕ���
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
//	// �ڲ��� -- ��A�Ƕ����ģ�ֻ����A����������
//	// �������private�У����ܷ���B��
//	class B // B������A����Դ��B���Է���A��
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
//	A aa1 = 1; // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//	func1(aa1); // ���Ż�
//	func1(2); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//	func1(A(3)); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//
//	cout << "----------------------------------" << endl;
//
//	func2(aa1);  // ���Ż�
//	func2(2);    // ���Ż�
//	func2(A(3)); // ���Ż�
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

// ���̽��C++����ģ��

int main()
{
	func3(); // �Ż�Ϊ����

	A aa1 = func3(); // �Ż�Ϊһ������

	cout << "****" << endl;
	A aa2;
	aa2 = func3();  // �����Ż�

	cout << "---------------------------" << endl;
	func4(); // ����+�������� -- �Ż�Ϊ����
	A aa3 = func4(); // �Ż�Ϊһ������

	return 0;
}