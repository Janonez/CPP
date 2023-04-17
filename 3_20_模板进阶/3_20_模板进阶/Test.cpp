#include <iostream>
//#include <array>
#include <vector>
using namespace std;

//#define N 20
// 类型模板参数 -- class T
// 非类型模板参数 -- 整型常量
//template<class T, size_t N = 20>
//class Array
//{
//public:
//	// ...
//private:
//	T _a[N];
//};
//
//template<class T, int N = 20>
//void func1(const T& a)
//{
//
//}
//
//template<class T, bool flag = true>
//void func2(const T& a)
//{
//
//}
//
//int main()
//{
//	Array<int> a1;
//	Array<int,10> a2;
//
//	func1(1);
//	func2(2);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T l, T r)
//{
//	return l < r;
//}
//
// 模板特化 -- 某些特殊化处理
// 全特化
//template<>
//bool Less<Date*>(Date* l, Date* r)
//{
//	return *l < *r;
//}
//template<class T>
//bool Less(T* l, T* r)
//{
//	return *l < *r;
//}
//
//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	Date d1(2023, 1, 7);
//	Date d2(2023, 1, 4);
//	cout << Less(d1, d2) << endl;
//
//	
//	Date* p2 = &d2;
//	Date* p1 = &d1;
//	cout << Less(p1, p2) << endl;
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less(p3, p4) << endl;
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////
//template<class T>
//struct Less
//{
//	bool operator()(const T& l, const T& r)
//	{
//		return l < r;
//	}
//};
//
//// 全特化
//template<>
//struct Less<Date*>
//{
//	bool operator()(const Date* l, const Date* r)
//	{
//		return *l < *r;
//	}
//};
//
//// 偏特化
//template<class T>
//struct Less<T*>
//{
//	bool operator()(const T* l, const T* r)
//	{
//		return *l < *r;
//	}
//};
//
//int main()
//{
//	
//	
//	Date d1(2023, 1, 7);
//	Date d2(2023, 1, 4);
//	cout << Less<Date>()(d1, d2) << endl;
//	
//		
//	Date* p2 = &d2;
//	Date* p1 = &d1;
//	cout << Less<Date*>()(p1, p2) << endl;
//	
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less<int*>()(p3, p4) << endl;
//
//	return 0;
//}

//template<class T1, class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 全特化
//template<>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<int, char>" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//
//template<>
//class Data<int*, char*>
//{
//public:
//	Data()
//	{
//		cout << "Data<int*, char*>" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//
//template<class T1>
//class Data<T1, int>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1, int>" << endl;
//	}
//private:
//	T1 _d1;
//	int _d2;
//};
//// 两个参数偏特化为指针类型
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() 
//	{ 
//		cout << "Data<T1*, T2*>" << endl; 
//	}
//
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1 = T1(), const T2& d2 = T2())
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2*>
//{
//public:
//	Data(const T1& d1 = T1())
//
//	{
//		cout << "Data<T1&, T2*>" << endl;
//	}
//};
//
//int main()
//{
//	Data<int, int> d1;
//	Data<double, int> d2;
//	Data<int, char> d3;
//	Data<int*, char*> d4;
//	Data<int*, int*> d5;
//	Data<int&, char&> d6;
//	Data<int&, char*> d7;
//	return 0;
//}

#include "Func.h"



int main()
{
	Add(1, 2);
	Add(1.0, 2.0); // call func(0xdadada)

	func(); // call func(?)

	return 0;
}