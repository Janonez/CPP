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
//	// ����ʡ�Ը�ֵ����
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
//	// C++11֧�ֵ� �б��ʼ�� ���������ù��캯����ʼ��
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
//	//(*it)++; ������--�����޸�
//
//	// initializer_list����
//	// ��Ϊ����������֪��initializer_list<T>::iterator������һ�����͵����ֻ���һ��ĳ�����������֡�
//	// ���������������������ԭ�����ڣ�������������initializer_list<T>::iterator�����ǲ��ǡ�ģ������ķǶ������֡�����ơ��Ƕ������֡���
//	// ע�⣬�κκ�����Ϊ��bar���������T�������Ա�����ģ���������foo()����������typedef���͡�ö�����ͻ��߱����ȡ�
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
//	map<string, string> dict = { {"sort","����"},{"string","�ַ���"},{"Date","����"} };
//	pair<string, string> kv1 = { "Date","����" };
//	pair<string, string> kv2 { "Date","����" };
//
//	return 0;
//}

//-----------------------------decltype--------------------------------------------
int main()
{
	const int x = 1;
	double y = 2.2;

	cout << typeid(x * y).name() << endl;

	decltype(x * y) ret; // ret��������double
	decltype(&x) p; // p��������int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;

	return 0;
}