#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
using namespace std;

#include<assert.h>

//int main()
//{
//	int a = 0;
//	int b = 1;
//	int* p = &a;
//
//	a + b;
//
//	// ��ֵ���ø���ֵȡ����
//	int& ref1 = a;
//
//	// ��ֵ���ø���ֵȡ����
//	// int& ref2 = (a + b);
//	const int& ref2 = (a + b);
//
//	// ��ֵ���ø���ֵȡ����
//	int&& ref3 = (a + b);
//
//	// ��ֵ���ø�move����ֵȡ����
//	//int&& ref4 = a;
//	int&& ref4 = move(a);
//
//	return 0;
//}

//void func(int& a)
//{
//	cout << "void func(int& a)" << endl;
//}
//
//void func(int&& a)
//{
//	cout << "void func(int&& a)" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	func(a);
//	func(a + b);
//}

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
			//cout << "string(char* str)" << endl;

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

		~string()
		{
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
//	Janonez::string s1("hello world");
//
//	Janonez::string ret1 = s1;
//	Janonez::string ret2 = (s1+'!');
//
//	Janonez::string ret3 = move(s1);
//
//	return 0;
//}

// ��ֵ���ã�ֱ�Ӽ��ٿ�����1����ֵ���ô���  2�������÷��ء��������ڵľֲ����󣬲��������÷��أ�

//int main()
//{
//	Janonez::string valStr = Janonez::to_string(1234);
//	cout << valStr.c_str() << endl;
//
//	std::string s1("hello");
//
//	std::string s2 = s1;
//	//std::string s3 = move(s1);
//
//	//move(s1);
//	//std::string s3 = s1;
//
//	return 0;
//
//}
// 
// 

//int main()
//{
//	list<Janonez::string> lt;
//
//	Janonez::string s1("hello world");
//	lt.push_back(s1);
//	lt.push_back(move(s1));
//
//	lt.push_back(Janonez::string("hello world"));
//	lt.push_back("hello world");
//
//	return 0;
//}

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

// ��������(�����۵�)���ȿ���������ֵ��Ҳ����������ֵ
template<typename T>
void PerfectForward(T&& t)
{
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	/*int&& rr1 = 10;
//	cout << &rr1 << endl;
//	rr1++;*/
//
//	/*string s1("hello world");
//	string s2("hello world");
//	string s3 = s1 + s2;*/
//
//	return 0;
//}

#include "List.h"

int main()
{
	Janonez::list<Janonez::string> lt;

	Janonez::string s1("hello world");
	lt.push_back(s1);

	lt.push_back(Janonez::string("hello world"));
	lt.push_back("hello world");

	return 0;
}