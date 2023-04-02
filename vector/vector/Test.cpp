#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// 普通版本
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	// 迭代器版本
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 范围for
	for (auto e :v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> copy(v1);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v1(10,1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(v1.begin(), v1.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1("hello world");
	vector<char> v3(s1.begin(), s1.end());
	for (auto e : v3)
	{
		cout << e ;
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
	
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v1.rbegin();
	// auto rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	const size_t n = 10000000000;

	size_t begin = clock();
	v.reserve(n);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			//cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();
	cout << "消耗时间:" << end - begin << endl;
}

void test_vector4()
{
	vector<int> v1;
	v1.resize(10, 0);

	vector<int> v2(10, 2);
}


int main()
{
	test_vector4();
	
	TestVectorExpand();

	return 0;
}