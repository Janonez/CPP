#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//---------------------�������캯��----------------------------
//class Date
//{
//public:
//	// ���캯��
//	Date(int year = 2002,int month = 1,int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// ��������  
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{
//		_array[_size++] = x;
//	}
//
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		if (_array == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_array, st._array, sizeof(int)*st._size);
//		_capacity = st._capacity;
//		_size = st._size;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_size = _capacity = 0;
//		}
//		
//	}
//private:
//	int* _array;
//	int _size;
//	int _capacity;
//};
//
//class MyQueue
//{
//public:
//	// Ĭ�����ɹ��죬��������������
//private:
//	Stack _pushST;
//	Stack _popST;
//	int size = 0;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(2023, 2, 4);
//	d2.Print();
//
//	Date d3(d2);
//	d3.Print();
//
//	Stack st1;
//	Stack st2(st1);
//	cout << "-------------------" << endl;
//	MyQueue q1;
//	MyQueue q2(q1);
//	return 0;
//}


//-----------------------��ֵ���������------------------------------------------------

class Date
{
public:
	// ���캯��
	Date(int year = 2002,int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// ��������  
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

int main()
{
	Date d1(2024, 2, 4);
	Date d2(2023, 3, 4);

	//cout << operator==(d1, d2) << endl;
	//cout << (d1 == d2) << endl; // ת����operator==(d1,d2);
	//// ���ȼ����⣬��Ҫ��()������ȼ������򱨴�

	cout << d1.operator==(d2) << endl;
	cout << (d1 == d2) << endl;

	cout << (d1 < d2) << endl;

	return 0;
}