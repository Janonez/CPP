#include <iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////private: // �����಻�ɼ��������ã�
//protected: // ������ɼ�
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//		// ���ɼ�
//		//out << _name << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	/*Student s;
//	Teacher t;
//
//	s.Print();
//	t.Print();*/
//
//	double d = 1.1;
//	int i = d; // ��������ʽ����ת��
//	const int& ri = d; // ��ʽ����ת����������ʱ��������ʱ�������г��ԣ���Ҫconst����
//
//	return 0;
//}

//// Student��_num��Person��_num�������ع�ϵ��Ҳ�����ض���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//// ��Ҫע���������ǳ�Ա���������أ�ֻ��Ҫ��������ͬ�͹������ء�
//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//
//int main()
//{
//	/*Student s1;
//	s1.Print();*/
//
//	B b;
//	b.fun(10);
//	return 0;
//};

//class Person
//{
//public:
//	// ���캯��
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	// ��������
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person & p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Stduent(const Student& s)" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s1("����", 12);
//	Student s2(s1);
//
//	Person p = s1;
//
//	s2 = s1;
//	return 0;
//}

// ��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//
//	return 0;
//}

// ���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա��
// �������������ٸ����࣬��ֻ��һ��static��Աʵ����
class Person
{
public:
	Person() { ++_count; }
//protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student {
protected:
	string _seminarCourse; // �о���Ŀ
};
int main()
{
	Person p;
	Student s;
	/*cout << &(p._name) << endl;
	cout << &(s._name) << endl;
	
	cout << &(p._count) << endl;
	cout << &(s._count) << endl;*/

	Graduate g1;
	Graduate g2;

	cout << Person::_count << endl;
	return 0;
}