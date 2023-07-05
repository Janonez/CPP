#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <time.h>
using namespace std;

// 1.请设计一个类，不能被拷贝
//
// C++98: 只声明不定义 并且 设置成私有: 如果只声明没有设置成private，用户自己如果在类外定义了，就可以不能禁止拷贝了
//class CopyBan
//{
//	// ...
//private:
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//	//...
//};

// C++11:扩展delete的用法，delete除了释放new申请的资源外，如果在默认成员函数后跟上 = delete，表示让编译器删除掉该默认成员函数。
//class CopyBan
//{
//	// ...
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//	//...
//};


// 2.设计一个类，只能在 堆 上创建对象 
//
// 思路一: 将析构设为私有
// 外部不能调用私有，只能new一个类
//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;
//	}
//private:
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//};
//
//int main()
//{
//	// 不可以
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//
//	HeapOnly* pho3 = new HeapOnly;
//	pho3->Destroy();
//	return 0;
//}

// 思路二: 将构造设为私有
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj(int x = 0)
//	{
//		HeapOnly* p = new HeapOnly(x);
//		return p;
//	}
//private:
//	HeapOnly(int x = 0)
//		: _x(x)
//	{}
//
//	HeapOnly(const HeapOnly& hp) = delete;
//	HeapOnly& operator=(const HeapOnly& hp) = delete;
//	int _x;
//};
//
//int main()
//{
//	// 不可以
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//	//HeapOnly* pho3 = new HeapOnly;
//	
//	HeapOnly::CreateObj(1);
//	return 0;
//}


// 设计一个类，只能在 栈 上创建对象 
// 
// 将构造设为私有
//class StackOnly
//{
//public:
//	static StackOnly CreateObj(int x = 0)
//	{
//		return StackOnly(x);
//	}
//
//	// 移动构造
//	StackOnly(StackOnly&& st)
//		: _x(st._x)
//	{}
//private:
//	StackOnly(int x = 0)
//		: _x(x)
//	{}
//
//	// 封拷贝构造 就不能传值返回
//	// StackOnly(const StackOnly& st) = delete;
//
//	int _x;
//};
//int main()
//{
//	// 不可以
//	//StackOnly st1;
//	//static StackOnly st2;
//	//StackOnly* pst3 = new StackOnly;
//	
//	StackOnly st4 = StackOnly::CreateObj(1);
//	// static StackOnly st2 = st1;
//	return 0;
//}


// 请设计一个类，不能被继承
// 
// C++98: 中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};

// C++11:final关键字，final修饰类，表示该类不能被继承。
//class A final
//{
//	// ....
//};

/////////////////////////////////////////////////////////////////
// 单例模式

// 饿汉模式: 一开始就创建对象（main函数之前）
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _ins;
//	}
//
//	void Add(const string& str)
//	{
//		_mtx.lock();
//		_v.push_back(str);
//		_mtx.unlock();
//	}
//
//	void Print()
//	{
//		_mtx.unlock();	
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//		_mtx.unlock();
//	}
//private:
//	// 限制类外面随意创建对象
//	Singleton()
//	{}
//private:
//	mutex _mtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//};
//
//Singleton* Singleton::_ins = new Singleton;


// 懒汉模式：第一次访问实例对象时创建（调用GetInstance()）

// 分析：懒汉和饿汉的优缺点
// 饿汉的缺点：
// 1、如果单例对象很大，main函数之前就要申请，第一,暂时不需要使用确占用资源，第二,程序启动会受影响。
// 2、如果两个单例都是饿汉，并且有依赖关系，要求单例1先创建，单例2再创建，饿汉无法控制顺序，懒汉才可以。
// 饿汉的优点：简单（相对懒汉而言）

// 懒汉完美的解决了上面饿汉的问题，但是就是相对复杂一点点
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// 这里存在线程安全问题
		// 双检查加锁 -- 保护第一次
		if (_ins == nullptr)// 提高效率，不需要每次获取单利都加锁解锁
		{
			_imtx.lock();
			if (_ins == nullptr) // 保证线程安全和只new一次
			{
				_ins = new Singleton; 
			}
			_imtx.unlock();
		}
		return _ins;
	}

	// 一般不显示释放，全局都要使用单例对象
	static void DelInstance()
	{
		_imtx.lock();
		if (_ins)
		{
			delete _ins;
			_ins = nullptr;
		}
		_imtx.unlock();
	}

	// 内部类：单例对象回收
	class GC
	{
	public:
		~GC()
		{
			DelInstance();
		}
	};

	static GC _gc;

	void Add(const string& str)
	{
		_vmtx.lock();
		_v.push_back(str);
		_vmtx.unlock();
	}

	void Print()
	{
		_vmtx.lock();
		for (auto& e : _v)
		{
			cout << e << endl;
		}
		cout << endl;
		_vmtx.unlock();
	}

	~Singleton()
	{
		// 持久化
		// 比如要求程序结束时，将数据写到文件，单例对象 析构 时持久化就比较好
	}
private:
	// 限制类外面随意创建对象
	Singleton()
	{}
private:
	mutex _vmtx;//保护vector写入的原子性
	vector<string> _v;

	static Singleton* _ins;
	static mutex _imtx;//保护实例
};

Singleton* Singleton::_ins = nullptr;
mutex Singleton::_imtx;
// 静态对象自动调用析构
Singleton::GC Singleton::_gc;
int main()
{
	srand(time(0));

	int n = 50;
	thread t1([n]() {
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t1线程：" + to_string(rand()));
		}
		});

	thread t2([n]() {
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t2线程：" + to_string(rand()));
		}
		});

	t1.join();
	t2.join();

	Singleton::GetInstance()->Print();
	return 0;
}