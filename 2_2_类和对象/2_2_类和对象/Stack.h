#pragma once

#include <stdlib.h>


// ���Ա���������Ͷ������
//struct Stack
//{
//	// ��Ա����
//	void Init(int n);	
//	void Push(int x);	
//	int Top();
//	
//	// ��Ա����
//	int* a;
//	int size;
//	int capacity;
//};

class Stack
{
public:
	// ��Ա����
	void Init(int capacity);	
	void Push(int x);	
	int Top();
private:	
	// ��Ա����
	int* _a;
	int _size;
	int _capacity;
};