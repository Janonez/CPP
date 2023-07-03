#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <list>
using namespace std;
//int x = 0;
//mutex mtx;
//list<int> lt;
//void func(int n)
//{
//	// cout << &n << endl; // ��ͬ
//	// cout << &x << endl; // ��ͬ
//
//	// ����
//	for (int i = 0; i < n; ++i)
//	{
//		mtx.lock();
//		++x;
//		lt.push_back(x);
//		mtx.unlock();
//	}
//
//	// ����
//	/*mtx.lock();
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//		lt.push_back(x);
//	}
//	mtx.unlock();*/
//
//}
//int main()
//{
//	int n = 1000000;
//	size_t begin = clock();
//	thread t1(func, n);
//	thread t2(func, n);
//
//	t1.join();
//	t2.join();
//	size_t end = clock();
//	cout << x << endl;
//	cout << end - begin << endl;
//	return 0;
//}

//int main()
//{
//	int n = 1000000;
//	int x = 0;
//	mutex mtx;
//
//	size_t begin = clock();
//	thread t1([&, n]() {
//		mtx.lock();
//		for (int i = 0; i < n; ++i)
//		{
//			++x;
//		}
//		mtx.unlock();
//		});
//
//	thread t2([&, n]() {
//		mtx.lock();
//		for (int i = 0; i < n; ++i)
//		{
//			++x;
//		}
//		mtx.unlock();
//		});
//
//	t1.join();
//	t2.join();
//
//	size_t end = clock();
//
//	cout << x << endl;
//	cout << end - begin << endl;
//
//	return 0;
//}

//int x = 0;
//recursive_mutex mtx;
//
//void Func(int n)
//{
//	if (n == 0)
//		return;
//
//	mtx.lock();
//	++x;
//
//	Func(n - 1);
//
//	mtx.unlock();
//}
//
//int main()
//{
//	thread t1(Func, 10000);
//	thread t2(Func, 20000);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

// ģ��ʵ�ֵ�lockguard
//template<class Lock>
//class LockGuard
//{
//public:
//	LockGuard(Lock& lk)
//		: _lk(lk)
//	{
//		_lk.lock();
//	}
//	~LockGuard()
//	{
//		_lk.unlock();
//	}
//private:
//	Lock& _lk;
//};
//
//int x = 0;
//mutex mtx;
//void Func(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		try
//		{
//			// -----------------------------------------------
//			//mtx.lock();
//			//++x;
//			//// ... ���쳣
//			//if (rand() % 3 == 0)
//			//{
//			//	throw exception("���쳣");
//			//}
//			//mtx.unlock();
//			// -----------------------------------------------
//
//			
//			//LockGuard<mutex> lock(mtx); // ģ��ʵ��
//			//lock_guard<mutex> lock(mtx); // ����ʵ��
//			unique_lock<mutex> lock(mtx);  // ����ʵ�֣������Զ����������
//			++x;
//			// ... ���쳣
//			if (rand() % 3 == 0)
//			{
//				throw exception("���쳣");
//			}
//		}
//		catch (const exception& e)
//		{
//			cout << e.what() << endl;
//		}
//	}
//}
//int main()
//{
//	thread t1(Func, 10);
//	thread t2(Func, 10);
//	
//	t1.join();
//	t2.join();
//	
//	cout << x << endl;
//	return 0;
//}


// atomic
//void Func(int x)
//{
//	cout << x << endl;
//}
//
//int main()
//{
//	int n = 100000;
//	// �������ֶ�����ͬ���������������������ԭ���Ե�
//	// atomic<int> x = 0;
//	// atomic<int> x = { 0 };
//
//	atomic<int> x{ 0 };
//	
//	//int x = 0;
//
//	mutex mtx;
//	size_t begin = clock();
//	
//	thread t1([&, n](){
//			for (int i = 0; i < n; i++)
//			{
//				++x;
//			}
//		});
//	
//	thread t2([&, n]() {
//			for (int i = 0; i < n; i++)
//			{
//				++x;
//			}
//		});
//	
//	t1.join();
//	t2.join();
//	size_t end = clock();
//	
//	cout << x << endl;
//	cout << end - begin << endl;
//		
//	//Func(x);
//	//printf("%d\n", x.load());
//
//	return 0;
//}

// ֧�������߳̽����ӡ��t1��ӡ������t2һ����ӡż��
//#include <condition_variable>
//int main()
//{
//	mutex mtx;
//	condition_variable cv;
//	int n = 100;
//	int x = 1;
//	thread t1([&, n](){
//			while(1)
//			{
//				unique_lock<mutex> lock(mtx);
//				if (x >= n)
//					break;
//				//if (x % 2 == 0) // ż������
//				//{
//				//	cv.wait(lock);
//				//}
//				// false��wait����
//				cv.wait(lock, [&x]() {return x % 2 != 0; });
//				cout << this_thread::get_id() << ": " << x << endl; 
//				++x;
//				cv.notify_one();
//			}
//		});
//	
//	thread t2([&, n]() {
//			while (1)
//			{
//				unique_lock<mutex> lock(mtx);
//				if (x > n)
//					break;
//				//if (x % 2 == 1) // ��������
//				//{
//				//	cv.wait(lock);
//				//}
//				// false��wait����
//				cv.wait(lock, [&x]() {return x % 2 == 0; });
//				cout << this_thread::get_id() << ": " << x << endl;
//				++x;
//				cv.notify_one();
//
//			}
//		});
//	
//	t1.join();
//	t2.join();
//	
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////
// ��װ�� - �ɵ��ö������ͽ����ٷ�װ����
// ����ָ��
// �º���
// lambda
#include <functional>
#include <map>
//int f(int a, int b)
//{
//	cout << "int f(int a, int b)" << endl;
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		cout << "int operator() (int a, int b)" << endl;
//		return a + b;
//	}
//};
//
//int main()
//{
//	// ����ָ������
//	// int(*pf1)(int, int) = f;
//	// map<string, >
//
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {
//		cout << "[](int a, int b) {return a + b;}" << endl;
//		return a + b; 
//	};
//
//	cout << f1(1, 2) << endl;
//	cout << f2(10, 20) << endl;
//	cout << f3(100, 200) << endl;
//
//	map<string, function<int(int, int)>> opFuncMap;
//	opFuncMap["����ָ��"] = f;
//	opFuncMap["�º���"] = Functor();
//	opFuncMap["lambda"] = [](int a, int b) {
//		cout << "[](int a, int b) {return a + b;}" << endl;
//		return a + b;
//	};
//
//	cout << opFuncMap["lambda"](1, 2) << endl;
//	return 0;
//}

//class Plus
//{
//public:
//	Plus (int rate = 2)
//		: _rate(rate)
//	{}
//	static int plusi(int a, int b) // ��̬��Ա����
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)// �Ǿ�̬��Ա����
//	{
//		return a + b;
//	}
//private:
//	int _rate = 2;
//};
//
//int main()
//{
//	// function<int(int, int)> p1 = &Plus::plusi;
//	function<int(int, int)> p1 = Plus::plusi;
//	function<double(Plus,double, double)> p2 = &Plus::plusd; // ����thisָ��,��Ҫ�ټӸ�����
//
//	cout << p1(10, 20) << endl;
//	cout << p2(Plus(3),10, 20) << endl;
//	Plus pp (3);
//	cout << p2(pp,20, 20) << endl;
//	return 0;
//}

////////////////////////////////bind///////////////////////////

// ��������˳��

//void Print(int a, int b)
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main()
//{
//	Print(1, 2);
//	// bind(Print, placeholders::_1, placeholders::_2); // δ����
//	// auto RPrint = bind(Print, placeholders::_2, placeholders::_1); //  ����
//	function<void(int,int)> RPrint = bind(Print, placeholders::_2, placeholders::_1); //  ����
//	RPrint(10, 20);
//	return 0;
//}


// ������������
#include <stack>
#include <string>
class Sub
{
public:
	Sub(int rate)
		: _rate(rate)
	{}
	int func(int a, int b)
	{
		return (a - b) * _rate;
	}
private:
	int _rate;
};

class Solution
{
public:
	int evalRPN(vector<string>&tokens) 
	{
		stack<int> st;
		map<string, function<int(int, int)>> opFuncMap =
		{
			{ "+", [](int i, int j) {return i + j; } },
			{ "-", [](int i, int j) {return i - j; } },
			{ "*", [](int i, int j) {return i * j; } },
			{ "/", [](int i, int j) {return i / j; } },
			{ "&", bind(&Sub::func,Sub(1),placeholders::_1, placeholders::_2)}
		};
		for (auto& str : tokens)
		{
			if (opFuncMap.find(str) != opFuncMap.end())
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(opFuncMap[str](left, right));
			}
			else
			{
				// 1��atoi itoa
				// 2��sprintf scanf
				// 3��stoi to_string C++11
				st.push(stoi(str));
			}
		}
		return st.top();
	}
};

int main()
{
	function<int(Sub, int, int)> fSub = &Sub::func;
	fSub(Sub(1), 10, 20);

	// ��������
	function<int(int, int)> fSub1 = bind(&Sub::func,Sub(1),placeholders::_1, placeholders::_2);
	cout << fSub1(10, 20) << endl; 

	function<int(Sub, int)> fSub2 = bind(&Sub::func, placeholders::_1, 100,placeholders::_2);
	cout << fSub2(Sub(2), 20) << endl;
	return 0;
}