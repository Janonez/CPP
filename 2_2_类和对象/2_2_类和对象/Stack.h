#pragma once

#include <stdlib.h>


// 类成员函数声明和定义分离
//struct Stack
//{
//	// 成员函数
//	void Init(int n);	
//	void Push(int x);	
//	int Top();
//	
//	// 成员变量
//	int* a;
//	int size;
//	int capacity;
//};

class Stack
{
public:
	// 成员函数
	void Init(int capacity);	
	void Push(int x);	
	int Top();
private:	
	// 成员变量
	int* _a;
	int _size;
	int _capacity;
};