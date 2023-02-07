#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

//class Stack
//{
//public:
//	Stack()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//	Stack(int capacity)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(int x)
//	{
//		_a[_size] = x;
//		_size++;
//	}
//	int Pop()
//	{
//		return _a[_size - 1];
//	}
//	// ...
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;	
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//int main()
//{
////	Stack st0;
//	Stack st(4);
//	
//	st.Push(1);
//	st.Push(3);
//	st.Push(5);
//	st.Push(7);
//
//	return 0;
//}


//class Date 
//{
//public:
//	/*Date()
//	{
//		_year = 1970;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(int year = 2002, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	void Print()
//	{
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	/*Date d2(2023, 2, 3);
//	Date d3(2023);
//	Date d4(2023,2);*/
//
//	/*d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();*/
//
//	return 0;
//}

//class Date
//{
//public:
//	// 默认生成构造函数，对内置类型不处理
//	// 默认生成析构函数，对内置类型不处理
//	Date(int year = 0)
//	{}
//
//	void Print()
//	{
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//private:
//	// 基本类型/内置类型
//	
//	// 声明位置给的缺省值
//	int _year ;
//	int _month ;
//	int _day ;
//};
//
//class MyQueue {
//public:
//	// 默认生成构造函数，对自定义类型成员，会调用他的默认构造函数
//	// 默认生成析构函数，对自定义类型成员，会调用他的析构函数
//
//	void push(int x) {
//
//	}
//	//....
//
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	MyQueue q;
//
//	return 0;
//}


// -----------------------------------------------
// 获取x天后的日期

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		else
			return monthArray[month];

	}
	Date GetAfterXDay(int x)// i + 10
	{
		// Date temp(*this);
		Date temp = *this;
		temp._day += x;
		while (temp._day > GetMonthDay(temp._year, temp._month))
		{
			temp._day -= GetMonthDay(temp._year, temp._month);
			temp._month++;
			if (temp._month == 13)
			{
				temp._year++;
				temp._month = 1;
			}
		}
		return temp;
	}

	Date& AddEqual(int x) // i += 10
	{
		_day += x;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023, 2, 3);
	Date d2 = d1.GetAfterXDay(100);
	Date d3 = d1.GetAfterXDay(500);

	d1.Print();
	d2.Print();
	d3.Print();


	return 0;
}