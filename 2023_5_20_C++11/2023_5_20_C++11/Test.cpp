#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//struct Point
//{
//	int _x1;
//	int _x2;
//};

//int main()
//{
//	int x1 = 1;
//	int x2 = { 2 };
//
//	// 可以省略赋值符号
//	int x3{ 3 };
//	int array1[]{ 1,2,3,4,5 };
//	int array2[5]{ 0 };
//	Point p{ 1,2 };
//
//	return 0;
//}

//class Date
//{
//public:
//	//explicit Date(int year, int month, int day)
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1(2023, 5, 20);
//
//	// C++11支持的 列表初始化 ，这里会调用构造函数初始化
//	Date d2 = { 2023,6,6 };
//	Date d3{ 2023,4,4 };
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5 };
//	vector<int> v2 = { 10,20,30 };
//	vector<int> v3 = { 10,20,30,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,1,1,2 };
//
//	list<int> lt1 = { 1,2,3,4,5 };
//	list<int> lt2 = { 10,20,30 };
//
//	auto i1 = { 10,20,30,1,2,3,4,5,6,7,8 };
//	auto i2 = { 1,2,3 };
//	cout << typeid(i1).name() << endl;
//	cout << typeid(i2).name() << endl;
//
//	initializer_list<int>::iterator it1 = i1.begin();
//	initializer_list<int>::iterator it2 = i2.begin();
//
//
//	cout << it1 << endl;
//	cout << it2 << endl;
//
//	//(*it)++; 常量区--不能修改
//
//	// initializer_list构造
//	// 因为编译器并不知道initializer_list<T>::iterator究竟是一个类型的名字还是一个某个变量的名字。
//	// 究其根本，造成这种歧义的原因在于，编译器不明白initializer_list<T>::iterator到底是不是“模板参数的非独立名字”，简称“非独立名字”。
//	// 注意，任何含有名为“bar”的项的类T，都可以被当作模板参数传入foo()函数，包括typedef类型、枚举类型或者变量等。
//
//	initializer_list<int> i3 = { 10,20,30 };
//	initializer_list<int>::iterator it3 = i3.begin();
//	cout << it3 << endl;
//
//	Date d1(2023, 3, 2);
//	Date d2(2023, 9, 3);
//	vector<Date> vd1 = { d1,d2 };
//	vector<Date> vd2 = { Date(2023, 3, 2),Date(2023, 9, 3) };
//	vector<Date> vd3 = { {2023, 3, 2},{2023, 9, 3} };
//
//	map<string, string> dict = { {"sort","排序"},{"string","字符串"},{"Date","日期"} };
//	pair<string, string> kv1 = { "Date","日期" };
//	pair<string, string> kv2 { "Date","日期" };
//
//	return 0;
//}

//-----------------------------decltype--------------------------------------------
int main()
{
	const int x = 1;
	double y = 2.2;

	cout << typeid(x * y).name() << endl;

	decltype(x * y) ret; // ret的类型是double
	decltype(&x) p; // p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;

	return 0;
}