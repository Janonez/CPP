#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month);

// �������С�������ʺ��������ĺ�����ֱ�����������涨���
class Date
{
	// ��Ԫ��������
	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	// ��ĳ�Ա������Ĭ�ϲ���������д���ұ߸�ֵ��������ĳ�Ա����ֻ��д�ڶ����︳ֵ��
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
	// int���� ������Ϊ��ռλ����ǰ����������
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

// ��������
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);