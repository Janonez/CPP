#pragma once
#include <vector>
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