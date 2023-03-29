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
		const char* c_str() // 遇到'\0'就停止
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
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
			
			if (n < _size)
			{
				// 删除数据 -- 保留前n个
				_size = n;
				_str[_size] = '\0';
			}
			else if(n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				size_t tmp = _size;
				while (tmp < n) 
				{
					_str[tmp] = ch;
					++tmp;
				}
				_size = n;
				_str[_size] = '\0';
			}
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
			/*if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			++_size;

			_str[_size] = '\0';*/

			insert(_size, ch);
		}
		void append(const char* str)
		{
			/*size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}
			strcpy(_str+_size, str);
			_size += len;*/

			insert(_size, str);
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
		string& insert(size_t pos, char ch)
		{
			assert(pos<=_size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			/*size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			++_size;
			_str[pos] = ch;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			size_t end = _size + len;
			if (end > _capacity)
			{
				reserve(len + _size);
			}
			while (end > pos+len-1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			/*for (int i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}*/
			strncpy(_str, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (pos + len >= _size || len == npos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		//s1.swap(s2);
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_capacity, str._capacity);
			std::swap(_size, str._size);
		}

		size_t find(char ch,size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			char* p = strstr(_str + pos, str);
			if (p == nullptr)
				return npos;
			else
				return p - _str;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
		//static const size_t npos = -1;
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& str)
	{
		for (auto ch : str)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		char ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				i = 0;
				str += buff;
			}

			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return in;
	}


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
		string s1("hello world111111111111111111111");
		cout << s1.capacity() << endl;
		s1.reserve(10);
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
	}

	void test_string7()
	{
		string s1("hello world");
		s1.resize(5);
		s1.resize(19, 'x');
		cout << s1.c_str() << endl;
	}

	void test_string8()
	{
		string s1("hello world");
		s1.insert(0,'x');
		
		cout << s1.c_str() << endl;
		s1.insert(3, "yyy");
		cout << s1.c_str() << endl;
		s1.insert(0, "zzz");
		cout << s1.c_str() << endl;

	}
	
	void test_string9()
	{
		string s1("hello world");
		string s2("hello world");
		string s3("hello world");
		s1.erase(3, 3);
		cout << s1.c_str() << endl;
		s2.erase(4, 15);
		cout << s2.c_str() << endl;
		s3.erase(5);
		cout << s3.c_str() << endl;
	}

	void test_string10()
	{
		string s1("hello world");
		cout << s1 << endl;
		string s2;
		cin >> s2;
		cout << s2 << endl;

		cin >> s1;
		cout << s1 << endl;

	}
}