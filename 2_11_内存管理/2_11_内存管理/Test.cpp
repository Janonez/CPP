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

class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }
private:
    int _a;
};
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

int main()
{
	// ʧ�������쳣
	int* p1 = (int*)operator new(sizeof(int*));

	// ʧ�ܷ���nullptr
	int* p2 = (int*)malloc(sizeof(int*));
	if (p2 == nullptr)
	{
		perror("malloc fail");
	}

	// ����ռ� operator new -> ��װmalloc
	// ���ù��캯��
	A* p5 = new A;

	// �ȵ�����������
	// ��operator delete p5ָ��Ŀռ�
	// operator delete -> free
	delete p5;

	// ����ռ� operator new[] ->perator new-> ��װmalloc
	// ����10�ι��캯��
	A* p6 = new A[10];
	
	// �ȵ���10����������
	// ��operator delete[] p6ָ��Ŀռ�
	delete[] p6;

	return 0;
}