#pragma once

namespace Janonez
{
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T, class Container = vector<T>,class Compare = less<T>>
	class my_priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				Compare com;
				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child+1<_con.size() && _con[child] < _con[child + 1])
				if (child+1<_con.size() && com(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}

		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		// 从大到小，建大堆
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		const T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
	void test_my_priority_queue()
	{
		//my_priority_queue<int> pq;
		my_priority_queue<int,vector<int>,greater<int>> pq;
		pq.push(1);
		pq.push(0);
		pq.push(5);
		pq.push(2);
		pq.push(9);
		pq.push(7);

		while (!pq.empty())
		{
			cout << pq.top();
			pq.pop();
		}
		cout << endl;
	}

	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		bool operator<(const Date& d) const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d) const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
		friend ostream& operator<<(ostream& _cout, const Date& d)
		{
			_cout << d._year << "-" << d._month << "-" << d._day;
			return _cout;
		}
	private:
		int _year;
		int _month;
		int _day;
	};

	class PDateLess
	{
	public:
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 < *p2;
		}
	};

	class PDateGreater
	{
	public:
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 > *p2;
		}
	};

	void test_my_priority_queue2()
	{

		//priority_queue<Date> q1;
		my_priority_queue<Date,vector<Date>,greater<Date>> q1;
		q1.push(Date(2018, 10, 29));
		q1.push(Date(2018, 10, 28));
		q1.push(Date(2018, 10, 30));
		cout << q1.top() << endl;


		//riority_queue<Date*, vector<Date*>, PDateGreater> q2;
		priority_queue<Date*> q2;
		q2.push(new Date(2018, 10, 29));
		q2.push(new Date(2018, 10, 30));
		q2.push(new Date(2018, 10, 28));
		cout << *(q2.top()) << endl;
	}
}

