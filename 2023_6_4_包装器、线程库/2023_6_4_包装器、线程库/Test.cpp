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
#include <condition_variable>
int main()
{
	mutex mtx;
	condition_variable cv;
	int n = 100;
	int x = 1;
	thread t1([&, n](){
			while(x < n)
			{
				unique_lock<mutex> lock(mtx);
				if (x % 2 == 0) // 偶数
				{
					cv.wait(lock);
				}
				cout << this_thread::get_id() << ": " << x << endl; 
				++x;
				cv.notify_one();
			}
		});
	
	thread t2([&, n]() {
			while (x < n)
			{
				unique_lock<mutex> lock(mtx);
				if (x % 2 == 1) // 奇数
				{
					cv.wait(lock);
				}
				cout << this_thread::get_id() << ": " << x << endl;
				++x;
				cv.notify_one();

			}
		});
	
	t1.join();
	t2.join();
	
	return 0;
}