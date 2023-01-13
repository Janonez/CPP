#define _CRT_SECURE_NO_WARNINGS 1
// C++兼容C语法
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
// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
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
//// 1、指定命名空间访问 -- 加命名空间名称及作用域限定符
//int main()
//{
//	struct Janonez::Queue q;
//	Janonez::QueueInit(&q);
//	Janonez::QueuePush(&q, 1);
//	Janonez::QueuePush(&q, 2);
//	return 0;
//}
//
//// 2、全局展开(一般情况，不建议全局展开的。) -- 使用using namespace 命名空间名称 引入
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
//// 3、部分展开 -- 使用using将命名空间中某个成员引入
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
//	// << 流插入
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
//	char name[19] = "张三";
//	int age = 19;
//
//	cout << "姓名：" << name << endl;
//	cout << "年龄：" << age << endl;
//
//	printf("姓名：%s\n年龄：%d\n", name, age);
//
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(1); // 传参时，使用指定的实参
//	Func(); // 没有传参时，使用参数的默认值
//	return 0;
//}
 

// 全缺省
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

// 半缺省
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

// 实际应用
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
	StackInit(&s1, 100);// 最多要存100个数据

	Stack s2;
	StackInit(&s2);// 不知道存多少个数据
	return 0;
}
// 测试