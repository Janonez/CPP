#include <iostream>

using namespace std;

// 多态的条件：
// 1、虚函数的重写（接口继承，重写实现） -- 三同（函数名、参数、返回值）
// 2、父类指针或者引用 调用
// -- 例外(协变)：返回值可以不同，必须是父子关系指针或者引用
// -- 例外：子类虚函数可以不加virtual
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//	// 析构虽然名字不同，但是虚函数会被编译器自动处理为destructor
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	// 当父类是虚函数是，子类不加virtual也构成多态，继承父类的接口，重写实现
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//	// 父类的析构函数加了virtual，一定构成多态，子类加不加都可以
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
////void Func(Person& p)
////{
////	// 1、不满足多态 -- 看调用者类型，调用这个类型的成员函数
////	// 2、满足多态   -- 看指向的对象的类型，调用的是这个对象的成员函数
////	p.BuyTicket();
////}
//
//void Func(Person* p)
//{
//	p->BuyTicket();
//	delete p;
//}
//
//int main()
//{
//	/*Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);*/
//
//	Func(new Person);
//	Func(new Student);
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////
// 多态的条件：
// 1、虚函数的重写 -- 三同(函数名、参数、返回值) 
//  -- 例外(协变)：返回值可以不同，必须是父子关系指针或者引用
//  -- 例外：子类虚函数可以不加virtual  
// 2、父类指针或者引用去调用
//
//class A{};
//class B : public A {};
//
//class Person {
//public:
//	//virtual A* BuyTicket()
//	virtual Person* BuyTicket()
//	{ 
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	//virtual B* BuyTicket() 
//	virtual Student* BuyTicket()
//	{ 
//		cout << "买票-半价" << endl;
//		return nullptr;
//	}
//};
//
//void Func(Person* p)
//{
//	// 1、不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 2、满足多态   -- 看指向的对象的类型，调用这个类型的成员函数
//	p->BuyTicket();
//
//	delete p;
//}
//
//int main()
//{
//	Func(new Person);
//	Func(new Student);
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl; 
//	}
//	virtual void test() 
//	{ 
//		func(); 
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0) 
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	// B这个子类继承了父类的test(),func构成虚函数的重写，test()函数参数是A* this，构成多态
//	// 执行子类中的func函数，但是子类的func是父类的重写，继承了virtual void func(int val = 1)，重写了实现
//	// 虽然执行的是子类的func，但是缺省值是父类的val=1的，所以打印B->1
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 1){
//		std::cout << "A->" << val << std::endl;
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0){
//		std::cout << "B->" << val << std::endl;
//	}
//	virtual void test(){
//		func();
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();	
//	// B中的test()函数参数是B* this，不是父类的指针或引用，不构成多态
//	// 执行子类自己的func，缺省值是val=0的，所以打印B->0
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	// 声明为 "final" 的函数不能由 "Benz::Drive" 重写
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car{
//public:
//	void Drive(){}
//};
//
//// 检查是否完成重写，不是就报错
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//	// “Benz::Drive”: 包含重写说明符“override”的方法没有重写任何基类方法
//};


////////////////////////////////////////////////////////////////////

//
//class Car
//{
//public:
//	 纯虚函数  -- 抽象类 -- 不能实例化出对象
//	virtual void Drive() = 0;
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//int main()
//{
//	 Car car; // 不能实例化出对象
//	BMW bmwCar;
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////
// 原理层
// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;//16,虚标指针
//	Base bb;
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void Func() { cout << "买票-全价" << endl; }
//
//	int _a = 0;
//
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	int _b = 1;
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person mike;
//	Func(mike);
//
//	Student johnson;
//	Func(johnson);
//
//	mike = johnson;
//
//	return 0;
//}


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b1;
//	Base b2;
//	Base b3;
//
//	Derive d;
//
//	b1.Func1();
//	b1.Func3();
//
//
//	return 0;
//}