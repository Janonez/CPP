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
				if (x % 2 == 0) // ż��
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
				if (x % 2 == 1) // ����
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