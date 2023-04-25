#include <iostream>
using namespace std;

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//
//class A
//{
//public:
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B b;
//	b._a = 10;
//	b._b = 20;
//
//	B* ptrb = &d;
//	ptrb->_a++;
//
//	ptrb = &b;
//	ptrb->_a++;
//
//	D d1, d2;
//
//	return 0;
//}



//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//class B :virtual public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :virtual public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D : public C, public B
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4) : B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

class Person 
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person
{
public:
	// 重写/覆盖
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);


	return 0;
}

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student;
//
//	delete ptr1;
//	delete ptr2;
//
//	return 0;
//}