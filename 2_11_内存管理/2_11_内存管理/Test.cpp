#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
//int main()
//{
//	int* pp1 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	free(pp1);
//	delete p1;
//
//	int* pp2 = (int*)malloc(sizeof(int)*10);
//	int* p2 = new int[10];
//	free(pp2);
//	delete[] p2;
//
//	A* pp3 = (A*)malloc(sizeof(A));
//	free(pp3);
//
//	A* p3 = new A(10);
//	delete p3;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//
//	return 0;
//}

//int main()
//{
//	//int* p1 = new int;// �����ʼ��
//	//int* pp1 = new int(0);
//
//	//int* p2 = (int*)malloc(sizeof(int));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//    // ��̬����һ��int���͵Ŀռ�
//    int* ptr4 = new int;
//    // ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//    int* ptr5 = new int(10);
//    // ��̬����10��int���͵Ŀռ�
//    int* ptr6 = new int[10];
//    // ��̬����10��int���͵Ŀռ�,����ʼ��ǰ4��
//    int* ptr7 = new int[10] {1, 2, 3, 4};
//
//    delete ptr4;
//    delete ptr5;
//    delete[] ptr6;
//    delete[] ptr7;
//
//	return 0;
//}

//class A
//{
//public:
//    A(int a = 0)
//        : _a(a)
//    {
//        cout << "A():" << this << endl;
//    }
//    ~A()
//    {
//        cout << "~A():" << this << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    // new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//    A* p1 = (A*)malloc(sizeof(A));
//    A* p2 = new A(1);
//    free(p1);
//    delete p2;
//    // ���������Ǽ�����һ����
//    int* p3 = (int*)malloc(sizeof(int)); 
//    int* p4 = new int;
//    free(p3);
//    delete p4;
//    A* p5 = (A*)malloc(sizeof(A) * 10);
//    A* p6 = new A[10];
//    free(p5);
//    delete[] p6;
//    return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = new int[4];
//		_top = 0;
//		_capacity = 4;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		delete[] _a;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	// ʧ�������쳣
//	int* p1 = (int*)operator new(sizeof(int*));
//
//	// ʧ�ܷ���nullptr
//	int* p2 = (int*)malloc(sizeof(int*));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// ����ռ� operator new -> ��װmalloc
//	// ���ù��캯��
//	A* p5 = new A;
//
//	// �ȵ�����������
//	// ��operator delete p5ָ��Ŀռ�
//	// operator delete -> free
//	delete p5;
//
//	// ����ռ� operator new[] ->perator new-> ��װmalloc
//	// ����10�ι��캯��
//	A* p6 = new A[10];
//	
//	// �ȵ���10����������
//	// ��operator delete[] p6ָ��Ŀռ�
//	delete[] p6;
//
//	int* p7 = new int[10];
//	free(p7);  // �����ͷţ��������ͣ����Ƽ�
//	
//	A* p8 = new A;
//	//free(p8); // �ٵ��õ���������
//	delete p8;
//	
//	Stack st;
//	
//	Stack* pst = new Stack;
//	delete pst;
//	//free(pst); // �ٵ������������� -- ���ڴ�й©
//	
//	// ���ۣ�new/mallocϵ�� �еײ�ʵ�ֻ����й������档��ƥ��ʹ��
//	// ���������⣬����û���⣬������һ��ƥ��ʹ��
//	
//	A* p9 = new A[10];
//	//free(p9);
//	//delete p9;
//	delete[] p9;
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

// ���ͱ�� -- ģ�� typename��class���ǹؼ��֣���˭������
//template<typename T>
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class X,class Y>
//void Func()
//{
//
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	//Swap(a, b);
//	swap(a, b);
//	double c = 1.1, d = 2.2;
//	//Swap(c, d);
//	swap(c, d);
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double b1 = 10.22, b2 = 23.78;
//	// ʵ�δ��ݸ��βΣ��Զ�����ģ������
//	cout << Add(a1, a2) << endl;
//	cout << Add(b1, b2) << endl;
//	cout << Add((double)a1, b2) << endl;
//	cout << Add(a1, (int)b2) << endl;
//	
//	//Add(a1, b2);
//	cout << "------------" << endl;
//	// ��ʾʵ����
//	cout << Add<int>(a1, b2) << endl;
//	cout << Add<double>(a1, b2) << endl;
//
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	//cout << "ADD" << endl;
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	//cout << "template" << endl;
//	return left + right;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(a, b); // ���ñ������ػ���Add�汾
//
//	Add(1.1, 2);
//
//	return 0;
//}


//typedef double STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Stack st1; // int
//	Stack st2; // double
//	// ����ͬʱ������������
//
//	return 0;
//}

template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = new T[capacity];
		_top = 0;
		_capacity = capacity;
	}
	~Stack()
	{
		delete[] _a;
		_top = _capacity = 0;
	}
private:
	T* _a;
	size_t _top;
	size_t _capacity;
};

int main()
{
	// ��ģ�������ʾʵ����
	Stack<int> st1; // int
	Stack<double> st2; // double
	return 0;
}