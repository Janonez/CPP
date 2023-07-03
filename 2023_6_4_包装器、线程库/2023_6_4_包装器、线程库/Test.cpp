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
//	// cout << &n << endl; // 不同
//	// cout << &x << endl; // 相同
//
//	// 并行
//	for (int i = 0; i < n; ++i)
//	{
//		mtx.lock();
//		++x;
//		lt.push_back(x);
//		mtx.unlock();
//	}
//
//	// 串行
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

// 模拟实现的lockguard
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
//			//// ... 抛异常
//			//if (rand() % 3 == 0)
//			//{
//			//	throw exception("抛异常");
//			//}
//			//mtx.unlock();
//			// -----------------------------------------------
//
//			
//			//LockGuard<mutex> lock(mtx); // 模拟实现
//			//lock_guard<mutex> lock(mtx); // 库中实现
//			unique_lock<mutex> lock(mtx);  // 库中实现，可以自定义加锁解锁
//			++x;
//			// ... 抛异常
//			if (rand() % 3 == 0)
//			{
//				throw exception("抛异常");
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
//	// 下面三种定义相同，无需加锁解锁，本身是原子性的
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

// 支持两个线程交替打印，t1打印奇数，t2一个打印偶数
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
//				//if (x % 2 == 0) // 偶数阻塞
//				//{
//				//	cv.wait(lock);
//				//}
//				// false才wait阻塞
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
//				//if (x % 2 == 1) // 奇数阻塞
//				//{
//				//	cv.wait(lock);
//				//}
//				// false才wait阻塞
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
// 包装器 - 可调用对象类型进行再封装适配
// 函数指针
// 仿函数
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
//	// 函数指针声明
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
//	opFuncMap["函数指针"] = f;
//	opFuncMap["仿函数"] = Functor();
//	opFuncMap["lambda"] = [](int a, int b) {
//		cout << "[](int a, int b) {return a + b;}" << endl;
//		return a + b;
//	};
//
//	cout << opFuncMap["lambda"](1, 2) << endl;
//	return 0;
//}

class Plus
{
public:
	Plus (int rate = 2)
		: _rate(rate)
	{}
	static int plusi(int a, int b) // 静态成员函数
	{
		return a + b;
	}
	double plusd(double a, double b)// 非静态成员函数
	{
		return a + b;
	}
private:
	int _rate = 2;
};

int main()
{
	// function<int(int, int)> p1 = &Plus::plusi;
	function<int(int, int)> p1 = Plus::plusi;
	function<double(Plus,double, double)> p2 = &Plus::plusd; // 还有this指针,需要再加个对象

	cout << p1(10, 20) << endl;
	cout << p2(Plus(3),10, 20) << endl;
	Plus pp (3);
	cout << p2(pp,20, 20) << endl;
	return 0;
}