#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<string>
#include<assert.h>
using namespace std;

namespace Janonez
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;
			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// s1 = 将亡值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			//cout << "~string()" << endl;

			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string operator+(char ch)
		{
			string tmp(*this);
			tmp += ch;
			return tmp;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};

	//const Janonez::string& to_string(int value)
	Janonez::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		Janonez::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

//int main()
//{
//	/*Janonez::string s1;
//	s1 = Janonez::to_string(1234);*/
//
//	/*Janonez::string("hello world");
//	const Janonez::string& ref1 = Janonez::string("hello world");
//	Janonez::string s2;*/
//
//	const Janonez::string& ref2 = Janonez::to_string(1234);
//	cout << "111111111111111111" << endl;
//
//	/*const Janonez::string& ref2 = Janonez::to_string(1234);
//	cout << "111111111111111111" << endl;*/
//
//	return 0;
//}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	Person(const Person& p)
		:_name(p._name)
		,_age(p._age)
	{}

	Person& operator=(const Person& p)
	{
		if(this != &p)
		{
			_name = p._name;
			_age = p._age;
		}
		return *this;
	}

	// 强制生成移动构造和移动赋值
	Person(Person&& p) = default;
	Person& operator=(Person&& p) = default;

	~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	Janonez::string _name; // 自定义类型
	int _age = 1;		   // 内置类型
};

// 如果你没有自己实现 移动构造函数，且没有实现 析构函数 、拷贝构造、拷贝赋值重载中的任意一个。
// 那么编译器会自动生成一个默认移动构造。
// 默认生成的移动构造函数，对于内置类型成员会执行逐成员按字节拷贝，自定义类型成员，则需要看这个成员是否实现移动构造，
// 如果实现了就调用移动构造，没有实现就调用拷贝构造。

// 如果你没有自己实现移动赋值重载函数，且没有实现析构函数 、拷贝构造、拷贝赋值重载中的任意一个，
// 那么编译器会自动生成一个默认移动赋值。
// 默认生成的移动构造函数，对于内置类型成员会执行逐成员按字节拷贝，自定义类型成员，则需要看这个成员是否实现移动赋值，
// 如果实现了就调用移动赋值，没有实现就调用拷贝赋值。(默认移动赋值跟上面移动构造完全类似)

// 如果你提供了移动构造或者移动赋值，编译器不会自动提供拷贝构造和拷贝赋值。

//int main()
//{
//	Person s1("张三", 18);
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	cout << endl << endl;
//	Person s4;
//	s4 = std::move(s2);
//
//	return 0;
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//}
//
//// 如何解析出可变参数包 -- 递归思想
//void ShowList()
//{
//	cout << endl;
//}
//template <class T,class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << val << " ";
//	ShowList(args...);
//}
//int main()
//{
//	ShowList();
//	ShowList('x');
//	ShowList('x','y');
//	ShowList('x',1);
//	ShowList('x',1,string("hello world"));
//
//	return 0;
//}

//void _ShowList()
//{
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void _ShowList(const T& val, Args... args)
//{
//	cout << __FUNCTION__ << "(" << sizeof...(args) << ")" << endl;
//	//cout << val << " ";
//	_ShowList(args...);
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	_ShowList(args...);
//}
//int main()
//{
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

//template<class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args),0)... };
//	// (PrintArg(args),0)
//	// 逗号表达式，它将两个及其以上的式子联接起来，从左往右逐个计算表达式，整个表达式的值为最后一个表达式的值。
//	cout << endl;
//}
//int main()
//{
//	ShowList(1, "A", std::string("sort"));
//	return 0;
//}

// STL容器的插入接口都有emplace系列
//int main()
//{
//	std::list<Janonez::string> mylist;
//	Janonez::string s1("11111");
//	mylist.push_back(s1);
//	mylist.emplace_back(s1);
//	cout << endl;
//
//	Janonez::string s2("22222");
//	mylist.push_back(move(s2));
//	mylist.emplace_back(move(s2));
//	cout << endl;
//
//	mylist.push_back("3333");		// 构造匿名对象 + 移动构造
//	mylist.emplace_back("3333");	// 直接构造
//	return 0;
//}

#include "Date.h"
int main()
{
	// 浅拷贝的类
	// 没区别
	std::list<Date> list2;
	Date d1(2023, 5, 28);
	list2.push_back(d1);
	list2.emplace_back(d1);

	cout << endl;
	Date d2(2023, 5, 28);
	list2.push_back(move(d1));
	list2.emplace_back(move(d2));

	// 有区别
	cout << "=========================" << endl;
	list2.push_back(Date(2023, 5, 28));
	list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // 构造+移动构造
	list2.emplace_back(2023, 5, 28);       // 直接构造
	return 0;
}