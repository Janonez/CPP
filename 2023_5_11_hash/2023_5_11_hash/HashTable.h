#pragma once

#include <vector>
namespace OpenAddress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
			// 负载因子超过0.7就扩容
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				// 遍历旧表重新映射到新表
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}
				_tables.swap(newht._tables);
			}

			size_t hashi = kv.first % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST)
			{
				index = hashi + i;
				index %= _tables.size();
				++i;
			}

			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			_n++;
			return true;
		}
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			size_t hashi = key % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXIST && _tables[index]._kv.first == key)
					return &_tables[index];
				index = hashi + i;
				index %= _tables.size();
				++i;
				// 如果已经查找一圈，说明全是EXIST DELETE
				if (hashi == index)
					break;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_n--;
				return true;
			}
			return false;
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;
	};

	void TestHashTable1()
	{
		int a[] = { 3,33,2,13,5,12,1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(15, 15));
		if (ht.Find(13))
		{
			cout << "13在" << endl;
		}
		else
		{
			cout << "13不在" << endl;
		}

		ht.Erase(13);

		if (ht.Find(13))
		{
			cout << "13在" << endl;
		}
		else
		{
			cout << "13不在" << endl;
		}
	}
}

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;
		HashNode(const pair<K,V>& kv)
			: _kv(kv)
			, _next(nullptr)
		{}
	};
	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))// 防止重复插入
				return false;
			// 负载因子 == 1
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtables(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = cur->_kv.first % newtables.size();
						// 头插到新表
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newtables);
			}
			size_t hashi = kv.first % _tables.size();
			// 头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return true;
		}
		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			size_t hashi = key % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
						_tables[hashi] = cur->_next;
					else
						prev->_next = cur->_next;

					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _n;
	};

	void TestHashTable1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 25));
		ht.Insert(make_pair(35, 35));
		ht.Insert(make_pair(45, 45));
	}

	void TestHashTable2()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(12);
		ht.Erase(3);
		ht.Erase(33);
	}
}