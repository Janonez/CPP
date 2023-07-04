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

		// ����Ȩת��
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

		*ap1 = 10; // ����Ȩת�Ƶ���ap1���գ����ܷ���
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

		// ������
		// ��������͸�ֵ��Ĭ�ϳ�Ա��������д���Զ����ɣ����Բ���Ҫд
		// C++11˼·���﷨֧��
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		// C++98˼·��ֻ������ʵ�֣�������������ǿ�ж��壬���Ի�Ҫ����Ϊ˽��
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


	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
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
			if (--(*_pcount) == 0)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;

				// delete _pmtx; ��ν������
			}
			_pmtx->unlock();
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

		// sp1 = sp4; ����ֵ��sp1--���ü���
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
		
		T* get()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
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
	};
	void SharePtrFunc(shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		for (size_t i = 0; i < n; ++i)
		{
			// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
			shared_ptr<Date> copy(sp);
		}
	}

	void test_shared_safe()
	{
		shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		const size_t n = 100000;
		mutex mtx;
		thread t1(SharePtrFunc, ref(p), n, ref(mtx));
		thread t2(SharePtrFunc, ref(p), n, ref(mtx));
		t1.join();
		t2.join();

		cout << p.use_count() << endl;
	}
}