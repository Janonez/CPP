#include <iostream>

using namespace std;

// ����ת��
void Test()
{
	int i = 1;
	// ��ʽ����ת�����������Ƶ�����
	double d = i;
	printf("%d, %.2f\n", i, d);
	int* p = &i;
	// ��ʾ��ǿ������ת��
	int address = (int)p;
	printf("%x, %d\n", p, address);
}


//void insert(size_t pos, char ch)
//{
//	size_t end = _size;
//	// pos == 0ʱ�ͻ������,�޷��ŵ�end��end==0ʱ����ѭ������--end��Ϊ-1���޷��ű���ر�������������ѭ��
//	// ��Ϊ int end = _size; ͬ���������⣬�������Ͳ�ͬ���Ƚ�ʱ�ᷢ����ʽ����ת��
//	while (end >= pos)
//	{
//		//...
//		--end;
//	}
//}

// C++��4������ת��
// static_cast��reinterpret_cast��const_cast��dynamic_cast

// 1.static_cast ��ʽ����ת��
void static_cast_test()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
}

// 2.reinterpret_cast ���������ת��
void reinterpret_cast_test()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;

	// ����ʹ��static_cast�ᱨ��Ӧ��ʹ��reinterpret_cast
	// int *p = static_cast<int*>(a);
	int* p = reinterpret_cast<int*>(a);
}

// 3.const_cast ɾ��������const����,���㸳ֵ
void const_cast_test()
{
	// const int a = 2;
	volatile const int a = 2; // ȷ������ָ��ᱻ���������Ż������ԡ�
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl; // �޸���a������const�������������ƺ��滻���߼Ĵ���
	cout << *p << endl;
}

// 4.dynamic_cast dynamic_cast ���ڽ�һ����������ָ��/����ת��Ϊ��������ָ�������(��̬ת��)
// ����ת�ͣ��������ָ�� / ����->����ָ�� / ����(����Ҫת������ֵ���ݹ���)
// ����ת�ͣ��������ָ�� / ����->����ָ�� / ����(��dynamic_castת���ǰ�ȫ��)
// ע�⣺
// 1. dynamic_castֻ�����ڸ��ຬ���麯������
// 2. dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�0
class A
{
public:
	virtual void f() {}
};
class B : public A
{};

void fun(A* pa, const string& s)
{
	cout <<"paָ��"<<s << endl;

	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	// ָ��ָ����ת��ʧ�ܣ�ָ������ת���ɹ�
	B* pb1 = (B*)pa;			   // ����ȫ��
	B* pb2 = dynamic_cast<B*>(pa); // ��ȫ��

	cout << "[ǿ��ת��]pb1:" << pb1 << endl;
	cout << "[dynamic_castת��]pb2:" << pb2 << endl << endl;
}

void dynamic_cast_test()
{
	A aa;
	B bb;

	// bb = (B)aa; ���󣬶�����ת��
	fun(&aa, "ָ�������"); // �������
	// aaǿ��ת��B*���Ǵ��ڷ��յģ���Ϊ���B���Լ��ĳ�Ա����ô��ָ����Է�����Щ��Ա�������������ʾ���ǿ��Խ����

	fun(&bb, "ָ���������"); // ������� 
	// ��ȫ�� 

	cout << typeid(aa).name() << endl;
}
int main()
{
	// Test();
	// static_cast_test();
	// reinterpret_cast_test();
	// const_cast_test();
	dynamic_cast_test();
	return 0;
}