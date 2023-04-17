#pragma once
#include<iostream>
#include<array>
#include <vector>
using namespace std;

template<class T>
T Add(const T& left, const T& right);

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

// 声明和定义放到一起，直接就可以实例化，编译时就有地址，不需要链接
void func();