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

	// RAII
	// ��ָ��һ��ʹ��
	// ����
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr) // T* ptr = nullptr ���û�й��캯��
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

			// �����������ñ�ʶ��
			bool DeleteFlag = false;
			if (--(*_pcount) == 0)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;

				// delete _pmtx; ��ν������

				//// ����һ���Ƚ������ͷţ���ǰ����
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

	// shared_ptr�������̰߳�ȫ�ģ���Ϊ�����Ǽ�������
	// ����shared_ptr����Ķ������̰߳�ȫ��
	void SharePtrFunc(shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		for (size_t i = 0; i < n; ++i)
		{
			// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
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

	// ѭ������

	// weak_ptr
	// 1�������ǳ��������ָ�룬��֧��RAII
	// 2��֧����ָ��һ��
	// 3��ר����Ƴ������������shared_ptr��ѭ�����õ�����
	// weak_ptr ����ָ����Դ������������������������ü���
	struct ListNode
	{
		//ListNode* _prev;
		//ListNode* _next;

		// ��Ϊ����ָ��

		//// ѭ������ 
		//std::shared_ptr<ListNode> _prev;
		//std::shared_ptr<ListNode> _next;
		//Janonez::shared_ptr<ListNode> _prev;
		//Janonez::shared_ptr<ListNode> _next;

		// ʹ��weak_ptr , ���������ü���, ����ѭ������
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

		////�˴����쳣ʱ���ܵ����ڴ�й¶
		//n1->_next = n2;
		//n2->_prev = n1;

		//delete n1;
		//delete n2;

		Janonez::shared_ptr<ListNode> n1(new ListNode);
		Janonez::shared_ptr<ListNode> n2(new ListNode);
		// ����ԭ������ָ�벻���Զ����ɹ��캯��

		cout << n1.use_count() << endl;
		cout << n2.use_count() << endl;
		
		// ����ԭ������ָ�벻�ܸ�ֵ����ָͨ�룬Ҫ��struct�ṹ���Ϊ����ָ��
		n1->_next = n2;
		n2->_prev = n1;

		cout << n1.use_count() << endl;
		cout << n2.use_count() << endl;
	}


	// weak_ptr
	// 1�������ǳ��������ָ�룬��֧��RAII
	// 2��֧����ָ��һ��
	// 3��ר����Ƴ������������shared_ptr��ѭ�����õ�����
	// weak_ptr ����ָ����Դ������������������������ü���

	//--------------------------------------------------------------------------------------
	// ����ɾ���� -- �ɵ��ö���

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

		// new[]ʱ����ͷ�࿪�ĸ��ֽڴ����������¼��ȡ���ٴ���������
		// ��ȷ����������ɾ����
		std::shared_ptr<Date> spa1(new Date[10],DeleteArray<Date>()); // �º���
		
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