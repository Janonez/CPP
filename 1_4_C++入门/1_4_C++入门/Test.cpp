#define _CRT_SECURE_NO_WARNINGS 1
// C++����C�﷨
//#include <stdio.h>
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}
// C����û�취�������������������ͻ���⣬����C++�����namespace�����
//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int a = 0;
//void test1()
//{
//    int a = 1;
//    printf("%d\n", a);
//}
//void test2()
//{
//    int a = 2;
//    printf("%d\n", a);
//}
//int main()
//{
//    printf("%d\n", a);
//    test1();
//    test2();
//    return 0;
//}

//#include "List.h"
//#include "Queue.h"

//int main()
//{
//	struct AQueue::Node node1;
//	struct BList::Node node2;
//	return;
//}


//int main()
//{
//	struct Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	return 0;
//}
//#include "Queue.h"
//// 1��ָ�������ռ���� -- �������ռ����Ƽ��������޶���
//int main()
//{
//	struct Janonez::Queue q;
//	Janonez::QueueInit(&q);
//	Janonez::QueuePush(&q, 1);
//	Janonez::QueuePush(&q, 2);
//	return 0;
//}
//
//// 2��ȫ��չ��(һ�������������ȫ��չ���ġ�) -- ʹ��using namespace �����ռ����� ����
//using namespace Janonez;
//int main()
//{
//	struct Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	return 0;
//}
//
//// 3������չ�� -- ʹ��using�������ռ���ĳ����Ա����
//using Janonez::Queue;
//using Janonez::QueueInit;
//int main()
//{
//	struct Queue q;
//	QueueInit(&q);
//	Janonez::QueuePush(&q, 1);
//	Janonez::QueuePush(&q, 2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	// << ������
//	// endl == '\n'
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//
//	/*int n;
//	cin >> n;
//	double* a = (double*)malloc(sizeof(double) * n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << endl;
//	}*/
//
//	char name[19] = "����";
//	int age = 19;
//
//	cout << "������" << name << endl;
//	cout << "���䣺" << age << endl;
//
//	printf("������%s\n���䣺%d\n", name, age);
//
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(1); // ����ʱ��ʹ��ָ����ʵ��
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	return 0;
//}
 

// ȫȱʡ
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func(1,2,3);
//	Func(1,2);
//	Func(1);
//	Func();
//	return 0;
//}

// ��ȱʡ
//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func(1, 2, 3);
//	Func(1, 2);
//	Func(1);
//	return 0;
//}

// ʵ��Ӧ��
//typedef struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//}Stack;
//
//void StackInit(Stack* ps,int defaultCapacity = 4)
//{
//	ps->a = (int*)malloc(sizeof(int)*defaultCapacity);
//	if (ps->a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	ps->top = 0;
//	ps->capacity = defaultCapacity;
//}
//int main()
//{
//	Stack s1;
//	StackInit(&s1, 100);// ���Ҫ��100������
//
//	Stack s2;
//	StackInit(&s2);// ��֪������ٸ�����
//	return 0;
//}
// git commit -m '����'


#include <iostream>
#include <assert.h>
using namespace std;

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//
//	return 0;
//}


//////////////////////////////////////////////////////////////
// 1��������
// ����Ͳ���
// �βεĸı䣬Ӱ��ʵ��
//void Swap(int* p1, int* p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//void swap(int& p1, int& p2)
//{
//	int temp = p1;
//	p1 = p2;
//	p2 = temp;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	swap(a, b);
//	printf("a=%d,b=%d\n", a, b);
//
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////
// 2��������ֵ
//int& Count()
//{
//	static int n = 0;
//	n++;
//
//	return n;
//}
//// ���÷���
//// 1�����ٿ���
//// 2�������߿����޸ķ��ض���
//#define N 10
//typedef struct Array
//{
//	int a[N];
//	int size;
//}AY;
//int& PosAT(AY& ay,int i)
//{
//	assert(i < N);
//	return ay.a[i];
//}
//
//int main()
//{
//	int ret = Count();
//
//	AY ay;
//	for (int i = 0; i < N; i++)
//	{
//		PosAT(ay, i) = i * 10;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cout << PosAT(ay, i) << " ";
//	}
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int Count()
//{
//	int n = 0;
//	n++;
//
//	return n;
//}
//
//int main()
//{
//	int a = 1;
//	int& b = a;
//
//	// ָ������ã���ֵ/��ʼ�� Ȩ�޿�����С�����ǲ��ܷŴ�
//
//	// Ȩ�޷Ŵ�
//	/*const int c = 2;
//	int& d = c;
//
//	const int* p1 = NULL;
//	int* p2 = p1;*/
//
//	// Ȩ�ޱ���
//	const int c = 2;
//	const int& d = c;
//
//	const int* p1 = NULL;
//	const int* p2 = p1;
//
//	// Ȩ����С
//	int x = 1;
//	const int& y = x;
//
//	int* p3 = NULL;
//	const int* p4 = p3;
//
//	// 
//	//const int m = 1;
//	//int n = m;
//
//	const int& ret = Count();
//
//	int i = 10;
//
//	cout << (double)i << endl;
//
//	double dd = i;
//
//	const double& rd = i;
//
//	return 0;
//}

// C++�Ƽ�
// const��enum����곣��
// inlineȥ����꺯��

// ��ȱ�㣺
// 1�����ܵ���
// 2��û�����Ͱ�ȫ�ļ��
// 3����Щ�����·ǳ�����,���׳�������������

// Ҫ��ʵ��ADD�꺯��
//#define ADD(x, y) ((x)+(y))

//int main()
//{
//	ADD(1, 2) * 3; // ((1)+(2))*3;
//
//	int a = 1, b = 2;
//	ADD(a | b, a & b); // ((a | b) + (a & b));;
//
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	int z = x + y;
//	z = x + y;
//	z += x + y;
//	//z = x + y;
//	//z = x + y;
//	//z = x * y;
//	//z = x + y;
//	//z += x + y;
//	//z -= x + y;
//	//z += x + y;
//	//z += x * y;
//	//z -= x / y;
//	//z += x + y;
//	//z += x + y;
//
//	return z;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//
//	return 0;
//}

//#include "Func.h"
//int main()
//{
//	f(10);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	// int b = a;
//	auto b = a;
//	auto c = &a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//}

//int main()
//{
//	int a = 10;
//	auto b = &a;
//	auto* c = &a;
//	auto& d = a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	int array[] = { 1,2,3,4,5,6,7 };
//	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	return 0;
}
// test2
