#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month);

class Date
{
public:
	// ��ĳ�Ա������Ĭ�ϲ���������д���ұ߸�ֵ��������ĳ�Ա����ֻ��д�ڶ����︳ֵ��
	Date(int year = 1970, int month = 1, int day = 1);
	void Print();
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	bool operator>(const Date& d);
	bool operator>=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator++();
	Date operator++(int);

	Date& operator-(const Date& d);
	Date& operator-(int day);

private:
	int _year;
	int _month;
	int _day;
};