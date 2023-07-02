#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
using namespace std;

struct Goods
{
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

// Խ��ԽС ����
struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};
// Խ��Խ�� ����
struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	return 0;
//}

// lambda���ʽ
//int main()
//{
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 99) << endl;
//
//	// ͨ��������ôд
//	// cout << [](int x, int y)->int {return x + y; }(2, 3) << endl;
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
//
//	auto PriceLess = [](const Goods& gl, const Goods& gr)->bool {return gl._price > gr._price; };
//	sort(v.begin(), v.end(), PriceLess);
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
//		return gl._price < gr._price; 
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
//		return gl._evaluate < gr._evaluate;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
//		return gl._evaluate < gr._evaluate;
//		});
//	return 0;
//}

//int main()
//{
//	int x = 0, y = 2;
//	auto swap1 = [](int& x, int& y)
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1(x, y);
//	cout << x << " " << y << endl;
//
//	// auto swap2 = [x, y]() mutable	// ��ֵ��׽
//	auto swap2 = [&x,&y]()				// ���ò�׽
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap2();
//	cout << x << " " << y << endl;
//
//	// ��ϲ�׽
//	auto func1 = [&x, y]()
//	{
//		//...
//	};
//	
//	// ȫ�����ò�׽
//	auto func2 = [&]()
//	{
//		//...
//	};
//	
//	// ȫ����ֵ��׽
//	auto func3 = [=]()
//	{
//		//...
//	};
//	
//	// ȫ�����ò�׽��x��ֵ��׽
//	auto func4 = [&, x]()
//	{
//		//...
//	};
//	return 0;
//}

// C++98��linux��windows�¶�����֧�ֵĶ��̳߳���-- ��������

//#ifdef _WIN32
//	CreateThread
//#else
//	pthread_create
//#endif

// C++11,linux��windows�¶�����֧�ֵĶ��̳߳���-- thread��

void func(int n, int num)
{
	for (int i = 0; i < n; ++i)
	{
		cout << num << " : " << i << endl;
	}
	cout << endl;
}

//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	thread t1(func,n1, 1);
//	thread t2(func,n2, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	thread t1([n1](int num)
//		{
//			for (int i = 0; i < n1; ++i)
//			{
//				cout << num << " : " << i << endl;
//			}
//			cout << endl;
//		}, 1);
//	thread t2([n2](int num)
//		{
//			for (int i = 0; i < n2; ++i)
//			{
//				cout << num << " : " << i << endl;
//			}
//			cout << endl;
//		}, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//int main()
//{
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m); // ����m��
//	// Ҫ��m���̷ֱ߳��ӡn������
//	for (size_t i = 0; i < m; ++i)
//	{
//		size_t n;
//		cin >> n;
//
//		vthds[i] = thread([i, n]() {
//			for (int j = 0; j < n; ++j)
//			{
//				cout << i << ":" << j << endl;
//			}
//			});
//	}
//
//	for (auto& t : vthds)
//	{
//		t.join();
//	}
//
//	return 0;
//}

//class Rate
//{
//public:
//	Rate(double rate) 
//		: _rate(rate)
//	{}
//
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//
//private:
//	double _rate;
//};
//
//int main()
//{
//	/*int x = 0, y = 1;
//	int m = 0, n = 1;
//	auto swap1 = [](int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	};
//
//	cout << sizeof(swap1) << endl;*/
//
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(100000, 2);
//
//	// lambda
//	auto r2 = [=](double money, int year)->double {return money * rate * year; };
//	r2(100000, 3);
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//
//	// f1 != f2;
//	return 0;
//}

int main()
{
	size_t m;
	cin >> m;
	vector<thread> vthds(m);

	for (size_t i = 0; i < m; ++i)
	{
		size_t n = 10;
		vthds[i] = thread([n, m]()
			{
				for (int j = 0; j < n; ++j)
				{
					cout << this_thread::get_id() << ":" << j << endl;

					this_thread::sleep_for(chrono::milliseconds(200));
				}
				cout << endl;

			});
	}

	for (auto& t : vthds)
	{
		t.join();
	}

	int i = 0;
	//i += 1;

	// ԭ��
	/*int old = i;
	while (!__sync_bool_compare_and_swap(&i, old, old+1))
	{
		old = i;
	}*/
	return 0;
}