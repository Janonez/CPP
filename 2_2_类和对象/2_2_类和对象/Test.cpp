#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//// C++����C�ṹ���÷�
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTN;
//
//// C++�ѽṹ������������
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//
// ��Ա����ֱ�Ӷ��嵽������
//struct Stack
//{
//	// ��Ա����
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int) * n);
//		if (a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		size = 0;
//		capacity = n;
//	}
//	
//	void Push(int x)
//	{
//		// ���ռ�����...
//		a[size] = x;
//		size++;
//	}
//
//	int Top()
//	{
//		return a[--size];
//	}
//	// ��Ա����
//	int* a;
//	int size;
//	int capacity;
//};

#include "Stack.h"

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	/*Stack st;
	st.Init(4);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	cout << st.Top() << endl;*/

	Date d1;
	d1.Init(2023,2,4);
	cout << sizeof(d1) << endl;

	return 0;
}