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

void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator<(const Date& d) const
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator<=(const Date& d) const
{
	return *this == d || *this < d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

Date& Date::operator+=(int day)
{
	// 如果加一个负数的话，相当于减等(-day)
	if (day < 0)
	{
		// 复用 -= 操作符
		*this -= -day;
		return *this;
	}
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
// 直接复用
Date Date::operator+(int day) const
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


Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return *this;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)// 后置--,要保存减之前的数据
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}
// 函数定义
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}