#pragma once
#include <vector>
#include <string>
template<size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N / 8 + 1,0);
	}
	void set(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		_bits[i] |= (1 << j);
	}
	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		_bits[i] &= ~(1 << j);
	}
	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		
		return _bits[i] & (1 << j);
	}
private:
	vector<char> _bits;
};

void test_bitset()
{
	bitset<100> bs;
	bs.set(10);
}

template<size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		// 第一次出现 00->01
		if (_bs1.test(x) == false && _bs2.test(x) == false)
		{
			_bs2.set(x);
		}
		// 01->10
		else if (_bs1.test(x) == false && _bs2.test(x) == true)
		{
			_bs1.set(x);
			_bs2.reset(x);
		}
		// 10 多次 -- 不操作
	}

	void Print()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (_bs2.test(i))
			{
				cout << i << endl;

			}
		}
	}
private:
	bitset<N> _bs1;
	bitset<N> _bs2;
};

void test_twobitset()
{
	int a[] = { 3, 45, 53, 32, 32, 43, 3, 2, 5, 2, 32, 55, 5, 53,43,9,8,7,8 };
	twobitset<100> bs;
	for (auto e : a)
	{
		bs.set(e);
	}

	bs.Print();
}

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}
		return hash;
	}
};
struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); ++i)
		{
			size_t ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));

			}
		}
		return hash;

	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) +ch;
		}
		return hash;
	}
};

// N-最多插入key数据的个数
template<size_t N,
	class K = string,
	class Hash1 = BKDRHash, 
	class Hash2 = APHash, 
	class Hash3 = DJBHash>
class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t len = N * _X;
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);
		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);
		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);

		//std::cout << hash1 << " " << hash2 << " " << hash3 << std::endl;
	}
	bool test(const K& key)
	{
		size_t len = N * _X;
		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
		{
			return false;
		}

		return true;
	}

private:
	static const size_t _X = 6;
	bitset<N* _X> _bs;
};



void test_bloomfilter()
{
	BloomFilter<100> bs;
	bs.set("sort");
	bs.set("bloom");
	bs.set("hello world");
	bs.set("test");
	bs.set("etst");
	bs.set("ttes");
}

void test_bloomfilter2()
{
	srand(time(0));
	const size_t N = 10000;
	BloomFilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		//string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}