#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// const��Ա
// ��const���εġ���Ա��������֮Ϊconst��Ա������const�������Ա������ʵ�����θó�Ա����
// ������thisָ�룬�����ڸó�Ա�����в��ܶ�����κγ�Ա�����޸ġ�
class A
{
public:
	// �������const���γ�Ա�����Ļ���*this ӵ�����޸ĵ�Ȩ�ޣ�Ȩ�ޱ��Ŵ�
	// const ���� *this
	// this�����ͱ�� const A*
	// �ڲ����ı��Ա�����ĳ�Ա����
	// ��ü���const��const�������ͨ���󶼿��Ե���
	void Print() const
	{
		cout << _a << endl;
	}
private:
	int _a = 10;
};
void Func(const A& x)
{
	x.Print();
}
int main()
{
	A aa;
	aa.Print();

	A bb;
	bb.Print();

	Func(aa);

	cout << &aa << endl;
	cout << &bb << endl;
	return 0;
}