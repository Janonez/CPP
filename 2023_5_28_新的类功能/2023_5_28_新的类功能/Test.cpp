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

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// s1 = ����ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
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
		size_t _capacity; // �������������ʶ��\0
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

	// ǿ�������ƶ�������ƶ���ֵ
	Person(Person&& p) = default;
	Person& operator=(Person&& p) = default;

	~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	Janonez::string _name; // �Զ�������
	int _age = 1;		   // ��������
};

// �����û���Լ�ʵ�� �ƶ����캯������û��ʵ�� �������� ���������졢������ֵ�����е�����һ����
// ��ô���������Զ�����һ��Ĭ���ƶ����졣
// Ĭ�����ɵ��ƶ����캯���������������ͳ�Ա��ִ�����Ա���ֽڿ������Զ������ͳ�Ա������Ҫ�������Ա�Ƿ�ʵ���ƶ����죬
// ���ʵ���˾͵����ƶ����죬û��ʵ�־͵��ÿ������졣

// �����û���Լ�ʵ���ƶ���ֵ���غ�������û��ʵ���������� ���������졢������ֵ�����е�����һ����
// ��ô���������Զ�����һ��Ĭ���ƶ���ֵ��
// Ĭ�����ɵ��ƶ����캯���������������ͳ�Ա��ִ�����Ա���ֽڿ������Զ������ͳ�Ա������Ҫ�������Ա�Ƿ�ʵ���ƶ���ֵ��
// ���ʵ���˾͵����ƶ���ֵ��û��ʵ�־͵��ÿ�����ֵ��(Ĭ���ƶ���ֵ�������ƶ�������ȫ����)

// ������ṩ���ƶ���������ƶ���ֵ�������������Զ��ṩ��������Ϳ�����ֵ��

//int main()
//{
//	Person s1("����", 18);
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
//// ��ν������ɱ������ -- �ݹ�˼��
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
//	// ���ű��ʽ�����������������ϵ�ʽ�����������������������������ʽ���������ʽ��ֵΪ���һ�����ʽ��ֵ��
//	cout << endl;
//}
//int main()
//{
//	ShowList(1, "A", std::string("sort"));
//	return 0;
//}

// STL�����Ĳ���ӿڶ���emplaceϵ��
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
//	mylist.push_back("3333");		// ������������ + �ƶ�����
//	mylist.emplace_back("3333");	// ֱ�ӹ���
//	return 0;
//}

#include "Date.h"
int main()
{
	// ǳ��������
	// û����
	std::list<Date> list2;
	Date d1(2023, 5, 28);
	list2.push_back(d1);
	list2.emplace_back(d1);

	cout << endl;
	Date d2(2023, 5, 28);
	list2.push_back(move(d1));
	list2.emplace_back(move(d2));

	// ������
	cout << "=========================" << endl;
	list2.push_back(Date(2023, 5, 28));
	list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // ����+�ƶ�����
	list2.emplace_back(2023, 5, 28);       // ֱ�ӹ���
	return 0;
}