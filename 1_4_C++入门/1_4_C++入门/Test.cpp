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

#include <iostream>
using namespace std;
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
typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps,int defaultCapacity = 4)
{
	ps->a = (int*)malloc(sizeof(int)*defaultCapacity);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = defaultCapacity;
}
int main()
{
	Stack s1;
	StackInit(&s1, 100);// ���Ҫ��100������

	Stack s2;
	StackInit(&s2);// ��֪������ٸ�����
	return 0;
}
// ����