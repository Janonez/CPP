#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <time.h>
using namespace std;

// 1.�����һ���࣬���ܱ�����
//
// C++98: ֻ���������� ���� ���ó�˽��: ���ֻ����û�����ó�private���û��Լ���������ⶨ���ˣ��Ϳ��Բ��ܽ�ֹ������
//class CopyBan
//{
//	// ...
//private:
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//	//...
//};

// C++11:��չdelete���÷���delete�����ͷ�new�������Դ�⣬�����Ĭ�ϳ�Ա��������� = delete����ʾ�ñ�����ɾ������Ĭ�ϳ�Ա������
//class CopyBan
//{
//	// ...
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//	//...
//};


// 2.���һ���ֻ࣬���� �� �ϴ������� 
//
// ˼·һ: ��������Ϊ˽��
// �ⲿ���ܵ���˽�У�ֻ��newһ����
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
//	// ������
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//
//	HeapOnly* pho3 = new HeapOnly;
//	pho3->Destroy();
//	return 0;
//}

// ˼·��: ��������Ϊ˽��
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
//	// ������
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//	//HeapOnly* pho3 = new HeapOnly;
//	
//	HeapOnly::CreateObj(1);
//	return 0;
//}


// ���һ���ֻ࣬���� ջ �ϴ������� 
// 
// ��������Ϊ˽��
//class StackOnly
//{
//public:
//	static StackOnly CreateObj(int x = 0)
//	{
//		return StackOnly(x);
//	}
//
//	// �ƶ�����
//	StackOnly(StackOnly&& st)
//		: _x(st._x)
//	{}
//private:
//	StackOnly(int x = 0)
//		: _x(x)
//	{}
//
//	// �⿽������ �Ͳ��ܴ�ֵ����
//	// StackOnly(const StackOnly& st) = delete;
//
//	int _x;
//};
//int main()
//{
//	// ������
//	//StackOnly st1;
//	//static StackOnly st2;
//	//StackOnly* pst3 = new StackOnly;
//	
//	StackOnly st4 = StackOnly::CreateObj(1);
//	// static StackOnly st2 = st1;
//	return 0;
//}


// �����һ���࣬���ܱ��̳�
// 
// C++98: �й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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

// C++11:final�ؼ��֣�final�����࣬��ʾ���಻�ܱ��̳С�
//class A final
//{
//	// ....
//};

/////////////////////////////////////////////////////////////////
// ����ģʽ

// ����ģʽ: һ��ʼ�ʹ�������main����֮ǰ��
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
//	// �������������ⴴ������
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


// ����ģʽ����һ�η���ʵ������ʱ����������GetInstance()��

// �����������Ͷ�������ȱ��
// ������ȱ�㣺
// 1�������������ܴ�main����֮ǰ��Ҫ���룬��һ,��ʱ����Ҫʹ��ȷռ����Դ���ڶ�,������������Ӱ�졣
// 2����������������Ƕ�����������������ϵ��Ҫ����1�ȴ���������2�ٴ����������޷�����˳�������ſ��ԡ�
// �������ŵ㣺�򵥣�����������ԣ�

// ���������Ľ����������������⣬���Ǿ�����Ը���һ���
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// ��������̰߳�ȫ����
		// ˫������ -- ������һ��
		if (_ins == nullptr)// ���Ч�ʣ�����Ҫÿ�λ�ȡ��������������
		{
			_imtx.lock();
			if (_ins == nullptr) // ��֤�̰߳�ȫ��ֻnewһ��
			{
				_ins = new Singleton; 
			}
			_imtx.unlock();
		}
		return _ins;
	}

	// һ�㲻��ʾ�ͷţ�ȫ�ֶ�Ҫʹ�õ�������
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

	// �ڲ��ࣺ�����������
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
		// �־û�
		// ����Ҫ��������ʱ��������д���ļ����������� ���� ʱ�־û��ͱȽϺ�
	}
private:
	// �������������ⴴ������
	Singleton()
	{}
private:
	mutex _vmtx;//����vectorд���ԭ����
	vector<string> _v;

	static Singleton* _ins;
	static mutex _imtx;//����ʵ��
};

Singleton* Singleton::_ins = nullptr;
mutex Singleton::_imtx;
// ��̬�����Զ���������
Singleton::GC Singleton::_gc;
int main()
{
	srand(time(0));

	int n = 50;
	thread t1([n]() {
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t1�̣߳�" + to_string(rand()));
		}
		});

	thread t2([n]() {
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t2�̣߳�" + to_string(rand()));
		}
		});

	t1.join();
	t2.join();

	Singleton::GetInstance()->Print();
	return 0;
}