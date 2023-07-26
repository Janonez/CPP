#pragma once
#include "HashTable.h"
namespace Janonez
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashBucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;
		typedef typename HashBucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::const_iterator const_iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		const_iterator begin() const
		{
			return _ht.begin();
		}
		const_iterator end() const
		{
			return _ht.end();
		}

		pair<iterator, bool> Insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}
		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}
	private:
		HashBucket::HashTable<K, pair<const K,V>, MapKeyOfT,Hash> _ht;
	};

	void test_unordered_map1()
	{
		unordered_map<int,int> m;
		m.Insert(make_pair(1,1));
		m.Insert(make_pair(3,3));
		m.Insert(make_pair(2,2));

		unordered_map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ": " << it->second << endl;
			++it;
		}
		cout << endl;
	}

	void test_unordered_map2()
	{
		string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "梨" };
		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
	class Date
	{
		friend struct HashDate;
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
		bool operator==(const Date& d) const
		{
			return _year == d._year
				&& _month == d._month
				&& _day == d._day;
		}

		friend ostream& operator<<(ostream& _cout, const Date& d);
		
	private:
		int _year;
		int _month;
		int _day;
	};

	ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	struct HashDate
	{
		size_t operator()(const Date& d)
		{
			size_t hash = 0;
			hash += d._year;
			hash *= 31;
			hash += d._month;
			hash *= 31;
			hash += d._day;
			hash *= 31;

			return hash;
		}
	};
	// 一个类型要做unordered_set/map 的key，要满足支持转换成取模的仿函数 和==比较
	// 一个类型要做set/map的key,要满足支持 < 比较
	void test_unordered_map3()
	{
		Date d1(2023, 3, 13);
		Date d2(2023, 3, 13);
		Date d3(2023, 3, 12);
		Date d4(2023, 3, 11);
		Date d5(2023, 3, 12);
		Date d6(2023, 3, 13);

		Date a[] = { d1, d2, d3, d4, d5, d6 };
		unordered_map<Date, int, HashDate> countMap;
		for (auto e : a) 
		{
			countMap[e]++;
		}
		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}