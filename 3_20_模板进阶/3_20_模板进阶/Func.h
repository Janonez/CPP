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

// �����Ͷ���ŵ�һ��ֱ�ӾͿ���ʵ����������ʱ���е�ַ������Ҫ����
void func();