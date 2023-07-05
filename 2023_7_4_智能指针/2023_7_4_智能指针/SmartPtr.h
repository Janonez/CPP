#pragma once

#include <mutex>
#include <thread>

namespace Janonez
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
			}
		}

		// 管理权转移
		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto()
	{
		auto_ptr<int> ap1(new int(1));
		auto_ptr<int> ap2(ap1);

		*ap1 = 10; // 管理权转移导致ap1悬空，不能访问
		*ap2 = 20;
	}


	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		// 防拷贝
		// 拷贝构造和赋值是默认成员函数，不写会自动生成，所以不需要写
		// C++11思路：语法支持
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		// C++98思路：只声明不实现，但可以在外面强行定义，所以还要声明为私有
	// private:
		// unique_ptr(const unique_ptr<T>& up);
	private:
		T* _ptr;
	};

	void test_unique()
	{
		unique_ptr<int> up1(new int(1));
		// unique_ptr<int> up2(up1);
	}

	// RAII
	// 像指针一样使用
	// 拷贝
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr) // T* ptr = nullptr 解决没有构造函数
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}
		~shared_ptr()
		{
			Release();
		}

		void Release()
		{
			_pmtx->lock();

			// 方法二，设置标识符
			bool DeleteFlag = false;
			if (--(*_pcount) == 0)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;

				// delete _pmtx; 如何解决？？

				//// 方法一，先解锁再释放，提前返回
				//_pmtx->unlock();
				//delete _pmtx;
				//return;
			}
			_pmtx->unlock();

			if (DeleteFlag)
			{
				delete _pmtx;
			}
		}

		void Addcount()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			Addcount();
		}

		// sp1 = sp4; 被赋值的sp1--引用计数
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;
				Addcount();
			}
			
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
		
		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			: _ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			: _ptr(sp.get())
		{}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_shared()
	{
		shared_ptr<int> sp1(new int(1));
		shared_ptr<int> sp2(sp1);
		shared_ptr<int> sp3(sp2);

		shared_ptr<int> sp4(new int(10));

		sp1 = sp4;
		//sp4 = sp1;

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
		cout << sp3.use_count() << endl;
		cout << sp4.use_count() << endl;
	}

	struct Date
	{
		int _year = 0;
		int _month = 0;
		int _day = 0;

		~Date()
		{}
	};

	// shared_ptr本身是线程安全的，因为计数是加锁保护
	// 但是shared_ptr管理的对象不是线程安全的
	void SharePtrFunc(shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			shared_ptr<Date> copy(sp);

			mtx.lock();
			sp->_day++;
			sp->_year++;
			sp->_month++;
			mtx.unlock();
		}
	}

	void test_shared_safe()
	{
		shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		const size_t n = 500000;
		mutex mtx;
		thread t1(SharePtrFunc, ref(p), n, ref(mtx));
		thread t2(SharePtrFunc, ref(p), n, ref(mtx));
		t1.join();
		t2.join();

		cout << p.use_count() << endl;

		cout << p->_year << endl;
		cout << p->_month << endl;
		cout << p->_day << endl;
	}

	// 循环引用

	// weak_ptr
	// 1、他不是常规的智能指针，不支持RAII
	// 2、支持像指针一样
	// 3、专门设计出来，辅助解决shared_ptr的循环引用的问题
	// weak_ptr 可以指向资源，但他不参与管理，不增加引用计数
	struct ListNode
	{
		//ListNode* _prev;
		//ListNode* _next;

		// 改为智能指针

		//// 循环引用 
		//std::shared_ptr<ListNode> _prev;
		//std::shared_ptr<ListNode> _next;
		//Janonez::shared_ptr<ListNode> _prev;
		//Janonez::shared_ptr<ListNode> _next;

		// 使用weak_ptr , 不增加引用计数, 避免循环引用
		Janonez::weak_ptr<ListNode> _prev;
		Janonez::weak_ptr<ListNode> _next;
		int _val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};

	void test_shared_cycle()
	{
		//ListNode* n1 = new ListNode;
		//ListNode* n2 = new ListNode;

		////此处抛异常时可能导致内存泄露
		//n1->_next = n2;
		//n2->_prev = n1;

		//delete n1;
		//delete n2;

		Janonez::shared_ptr<ListNode> n1(new ListNode);
		Janonez::shared_ptr<ListNode> n2(new ListNode);
		// 报错原因：智能指针不会自动生成构造函数

		cout << n1.use_count() << endl;
		cout << n2.use_count() << endl;
		
		// 报错原因：智能指针不能赋值给普通指针，要将struct结构体改为智能指针
		n1->_next = n2;
		n2->_prev = n1;

		cout << n1.use_count() << endl;
		cout << n2.use_count() << endl;
	}


	// weak_ptr
	// 1、他不是常规的智能指针，不支持RAII
	// 2、支持像指针一样
	// 3、专门设计出来，辅助解决shared_ptr的循环引用的问题
	// weak_ptr 可以指向资源，但他不参与管理，不增加引用计数

	//--------------------------------------------------------------------------------------
	// 定制删除器 -- 可调用对象

	template<class T>
	struct DeleteArray
	{
		void operator()(T* ptr)
		{
			cout << "void operator()(T* ptr)" << endl;
			delete[] ptr;
		}
	};
	void test_shared_deletor()
	{
		// std::shared_ptr<Date> spa(new Date[10]);

		// new[]时会在头多开四个字节储存个数，记录调取多少次析构函数
		// 正确做法：传入删除器
		std::shared_ptr<Date> spa1(new Date[10],DeleteArray<Date>()); // 仿函数
		
		std::shared_ptr<Date> spa2(new Date[10],[](Date* ptr){
			cout << "lambda delete[]" <<ptr << endl;
			delete[] ptr; 
			}); // lambda
		
		std::shared_ptr<FILE> spF3(fopen("Test.cpp","r"), [](FILE* ptr) {
			cout << "lambda fclose" << ptr << endl;
			fclose(ptr); 
			}); // lambda

	}
}