#pragma once

#include <assert.h>

namespace janonez
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		/*string()
			: _str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}
		string(const char* str)
			:_size(strlen(str))	
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}*/
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 4:_size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// 拷贝构造
		string(const string& str)
			: _size(str._size)
			, _capacity(str._capacity)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
		}
		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		const char* c_str()
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		string& operator=(const string& str)
		{
			if (this != &str)
			{
				char* tmp = new char[str._capacity + 1];
				strcpy(tmp, str._str);

				delete[] _str;
				_str = tmp;
				_size = str._size;
				_capacity = str._capacity;
			}	
			return *this;
		}

		bool operator>(const string& str) const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str) const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator>=(const string& str) const
		{
			return (*this > str || *this == str);
		}
		bool operator<(const string& str) const
		{
			return !(*this >= str);
		}
		bool operator<=(const string& str) const
		{
			return !(*this > str);
		}
		bool operator!=(const string& str) const
		{
			return !(*this == str);
		}
		//---------------------------------------------------------
		void resize(size_t n, char ch = '\0')
		{
			size_t pos = _size;
			if (pos > n)
			{
				_str[n] = '\0';
			}
			if (pos < n)
			{
				if (n+1 > _capacity)
				{
					reserve(n+1);
				}
				size_t tmp = pos;
				while (tmp < n)
				{
					_str[tmp] = ch;
					++tmp;
				}
				_str[tmp] = '\0';
			}
			
		}
		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			++_size;

			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}
			strcpy(_str+_size, str);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void insert(size_t pos, char ch)
		{
			assert(pos<=_size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			size_t end = _size;
			++_size;
			while (end >= pos && end != npos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
		}

		void insert(size_t pos, const char* str)
		{

		}

		void erase(size_t pos, size_t len = npos)
		{

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
		//static const size_t npos = -1;
	};
	const size_t string::npos = -1;

	void Print(const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			cout << str[i] << " ";
		}
		cout << endl;

		string::const_iterator it = str.begin();
		while (it != str.end())
		{
			//*it = 'x'; “it”: 不能给常量赋值
			++it;
		}
		cout << endl;

		for (auto ch : str)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string1()
	{
		string s1;
		string s2("hello world");
		
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		
		s2[0]++;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void test_string2()
	{
		string s1;
		string s2("hello world");

		string s3(s2);
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		s2[0]++;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
		
		s1 = s3;
		s1[0]++;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
		
		s1 = s1;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		Print(s1);

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)--;
			++it;
		}
		cout << endl;
		
		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("hello world");
		string s3("xxx");

		cout << (s1 > s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 <= s3) << endl;
		cout << (s1 < s3) << endl;
		cout << (s2 != s3) << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		s1 += ' ';
		s1 += " ";
		s1 += ' ';
		s1 += "xxxxxxxxxx";
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		//s1.resize(5);
		//s1.resize(19, 'x');
		s1.insert(5, 'x');
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
	}
}