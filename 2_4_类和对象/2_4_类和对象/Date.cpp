#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

int GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	else
		return monthArray[month];
}

Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13
		&& day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期错误" << endl;
		return;
	}
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator<(const Date& d)
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator<=(const Date& d)
{
	return *this == d || *this < d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	//如果函数返回时，出了函数作用域，返回对象还在(还没还给系统)，则可以使用引用返回，如果已经还给系统了，则必须使用传值返回。
	return *this;
}

//Date Date::operator+(int day)
//{
//	Date temp(*this);
//	temp._day += day;
//	while (temp._day > GetMonthDay(temp._year, temp._month))
//	{
//		temp._day -= GetMonthDay(temp._year, temp._month);
//		temp._month++;
//		if (temp._month == 13)
//		{
//			temp._year++;
//			temp._month = 1;
//		}
//	}
//	return temp;
//}
Date Date::operator+(int day)
{
	Date temp(*this);
	temp += day;
	
	return temp;
}
// ++d1
Date& Date::operator++()
{
	*this += 1;
	if (_day > GetMonthDay(_year, _month))
	{
		_day = 1;
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
//d1++
Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	if (_day > GetMonthDay(_year, _month))
	{
		_day = 1;
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return temp;
}

//Date& Date::operator-(const Date& d)
//{
//
//}
//Date& Date::operator-(int day)
//{
//
//}