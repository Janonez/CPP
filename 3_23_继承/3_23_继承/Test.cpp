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
////private: // 在子类不可见（不能用）
//protected: // 在子类可见
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//		// 不可见
//		//out << _name << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
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
//	int i = d; // 发生了隐式类型转换
//	const int& ri = d; // 隐式类型转换产生了临时变量，临时变量具有常性，需要const修饰
//
//	return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，也叫做重定义
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
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
//	int _num = 999; // 学号
//};
//
//// 需要注意的是如果是成员函数的隐藏，只需要函数名相同就构成隐藏。
//// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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
//	// 构造函数
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	// 拷贝构造
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
//	string _name; // 姓名
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
//	Student s1("张三", 12);
//	Student s2(s1);
//
//	Person p = s1;
//
//	s2 = s1;
//	return 0;
//}

// 友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
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

// 基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。
// 无论派生出多少个子类，都只有一个static成员实例。
class Person
{
public:
	Person() { ++_count; }
//protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student {
protected:
	string _seminarCourse; // 研究科目
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