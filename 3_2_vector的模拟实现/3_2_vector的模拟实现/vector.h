#pragma once
#include <assert.h>

namespace Janonez
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void resize(size_t n,T val = T())
		{
			if (n < size())
			{
				// ֱ��ɾ������
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
				
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size(); // size()��ʵ����{_finish - _start;}����30��ֱ��ʹ�õĻ�_start���£���_finishû�й�ϵ
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());// sizeof(T) -- > ���͵Ĵ�С
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);

			// ����Ҫ��Ų�����ݣ�������˵Ļ�����Խ�磬��Ҫ����
			// ����,��ַλ�þͻ�ı� posҲ��Ҫ�ı䣬��¼���λ��
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				// ���ݺ����pos�����posʧЧ������
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			
			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}

			--_finish;

			return pos;
		}

		size_t size() const
		{
			return _finish - _start;
		}
		
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty()
		{
			return (_start == _finish);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int>::const_iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v1.pop_back();
		v1.pop_back();

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(10,100);

		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		//v1.resize(3);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		/*v1.insert(v1.begin(), 0);
		for (auto e : v1)
		{
		cout << e << " ";
		}
		cout << endl;

		v1.insert(v1.end(), 0);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;*/

		auto pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			//v1.insert(pos, 30);
			pos = v1.insert(pos, 30);
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		// insert�Ժ�������ΪposʧЧ�ˣ�������ʹ��
		//(*pos)++;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.erase(pos);
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(10);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(40);
		
		//ɾ��ż��
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if(*it % 2 == 0)
				it = v1.erase(it);
			else
				++it;
		}
		
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<int> v1(10,5);
		
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(v1.begin()+1, v1.end()-1);

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		std::string s1("hello");
		vector<int> v3(s1.begin(), s1.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		int a[] = { 100,10,2,20,5 };
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
		vector<int> v4(a, a + 5);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.insert(v1.begin(), 30);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(v1.begin(), v1.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(a, a + sizeof(a) / sizeof(int), greater<int>());

		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}