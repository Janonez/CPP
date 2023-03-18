#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;

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
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//
//		//return _year < d._year
//		//	|| (_year == d._year && _month < d._month)
//		//	|| (_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator<=(const Date& d)
//	{
//		return *this < d || *this == d;
//	}
//
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//	// ����ֵΪ��������ֵ
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._year == d2._year
////		&& d1._month == d2._month
////		&& d1._day == d2._day;
////}
//
//int main()
//{
//	Date d1(2024, 2, 4);
//	Date d2(2023, 3, 4);
//	Date d3(2022, 1, 1);
//	//cout << operator==(d1, d2) << endl;
//	//cout << (d1 == d2) << endl; // ת����operator==(d1,d2);
//	//// ���ȼ����⣬��Ҫ��()������ȼ������򱨴�
//
//	cout << d1.operator==(d2) << endl;
//	cout << (d1 == d2) << endl;
//
//	cout << (d1 < d2) << endl;
//
//	d3 = d1 = d2;
//	d3.Print();
//	return 0;
//}


// -------------------------ʾ��-------------------------------
#include "Date.h"

void TestDate1()
{
	Date d1(2023, 2, 4);
	d1.Print();

	Date d2 = d1 + 500;
	//Date d2(d1 + 500);
	d2.Print();
	d1.Print();

	Date d3 = d1;// ��������
	d3 += 600;
	d3.Print();

	Date d4(2023, 1, 31);
	d4++;
	d4.Print();
	
}

void TestDate2()
{
	Date d1(2023, 2, 4);
	d1.Print();

	Date d2 = d1 + 100;
	d2.Print();

	Date d3 = d1 + 100;
	d3.Print();
}

void TestDate3()
{
	Date d1(2023, 2, 4);
	d1.Print();

	Date ret1 = ++d1;  // d1.operator++();
	d1.Print();
	ret1.Print();


	Date ret2 = d1++;  // d1.operator++(0);
	d1.Print();
	ret2.Print();

}

void TestDate4()
{
	Date d1(2023, 2, 4);
	d1.Print();
	
	d1 -= 100;
	d1.Print();

	Date d2(2023, 2, 7);
	d2 += -100;
	d2.Print();

	Date d3(2023, 2, 7);
	d3 -= -100;
	d3.Print();
}

void TestDate5()
{
	Date d1(2023, 2, 4);
	d1.Print();


	Date d2(2023, 4, 5);
	d2.Print();

	Date d3(2023, 5, 1);
	d2.Print();

	cout << d2 - d1 << endl;
	cout << d1 - d2 << endl;
	cout << d3 - d1 << endl;
}
//void operator<<(ostream& out,const Date& d);
//ostream& operator<<(ostream& out, const Date& d);
// 
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
//	return out;
//}
void TestDate6()
{
	Date d1(2023, 2, 4);
	Date d2(2020, 1, 1);
	operator<<(cout, d1);
	cout << d1;
	cout << d1 << d2;

	d1 -= 100;
	cout << d1;
}

void TestDate7()
{
	Date d1;
	cin >> d1;
	cout << d1;
}
int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	//TestDate6();
	TestDate7();
	return 0;
}