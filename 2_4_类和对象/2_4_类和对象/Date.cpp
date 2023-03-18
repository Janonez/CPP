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
		cout << "���ڴ���" << endl;
		return;
	}
}

void Date::Print() const
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
	// �����һ�������Ļ����൱�ڼ���(-day)
	if (day < 0)
	{
		// ���� -= ������
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
	//�����������ʱ�����˺��������򣬷��ض�����(��û����ϵͳ)�������ʹ�����÷��أ�����Ѿ�����ϵͳ�ˣ������ʹ�ô�ֵ���ء�
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
// ֱ�Ӹ���
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

Date Date::operator--(int)// ����--,Ҫ�����֮ǰ������
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
// ��������
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}