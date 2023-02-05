#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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


class Date 
{
public:
	/*Date()
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	Date(int year = 2002, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		//cout << _year << "/" << _month << "/" << _day << endl;
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2023, 2, 3);
	Date d3(2023);
	Date d4(2023,2);

	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();

	return 0;
}