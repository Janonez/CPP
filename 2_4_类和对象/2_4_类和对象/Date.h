#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month);

class Date
{
public:
	// 类的成员函数的默认参数不可以写在右边赋值，所以类的成员函数只能写在定义里赋值！
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