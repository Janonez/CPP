#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month);

// 类里面短小函数，适合做内联的函数，直接是在类里面定义的
class Date
{
	// 友元函数声明
	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	// 类的成员函数的默认参数不可以写在右边赋值，所以类的成员函数只能写在定义里赋值！
	Date(int year = 1970, int month = 1, int day = 1);
	void Print() const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);

	// ++d1
	Date& operator++();
	// d1++
	// int参数 仅仅是为了占位，跟前置重载区分
	Date operator++(int);

	// d1 - 100
	Date operator-(int day) const;

	// d1 - d2;
	int operator-(const Date& d) const;

	// --d1
	Date& operator--();
	// d1--
	Date operator--(int);

	//void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};

// 函数声明
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);