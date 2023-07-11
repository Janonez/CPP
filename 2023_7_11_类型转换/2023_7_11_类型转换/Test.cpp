#include <iostream>

using namespace std;

// 类型转换
void Test()
{
	int i = 1;
	// 隐式类型转换：意义相似的类型
	double d = i;
	printf("%d, %.2f\n", i, d);
	int* p = &i;
	// 显示的强制类型转换
	int address = (int)p;
	printf("%x, %d\n", p, address);
}


//void insert(size_t pos, char ch)
//{
//	size_t end = _size;
//	// pos == 0时就会出问题,无符号的end，end==0时进入循环，再--end变为-1，无符号变成特别大的数，陷入死循环
//	// 改为 int end = _size; 同样存在问题，两边类型不同，比较时会发生隐式类型转换
//	while (end >= pos)
//	{
//		//...
//		--end;
//	}
//}

// C++的4种类型转换
// static_cast、reinterpret_cast、const_cast、dynamic_cast

// 1.static_cast 隐式类型转换
void static_cast_test()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
}

// 2.reinterpret_cast 不相关类型转换
void reinterpret_cast_test()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;

	// 这里使用static_cast会报错，应该使用reinterpret_cast
	// int *p = static_cast<int*>(a);
	int* p = reinterpret_cast<int*>(a);
}

// 3.const_cast 删除变量的const属性,方便赋值
void const_cast_test()
{
	// const int a = 2;
	volatile const int a = 2; // 确保本条指令不会被编译器的优化而忽略。
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl; // 修改了a，但是const对象在这里类似宏替换或者寄存器
	cout << *p << endl;
}

// 4.dynamic_cast dynamic_cast 用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)
// 向上转型：子类对象指针 / 引用->父类指针 / 引用(不需要转换，赋值兼容规则)
// 向下转型：父类对象指针 / 引用->子类指针 / 引用(用dynamic_cast转型是安全的)
// 注意：
// 1. dynamic_cast只能用于父类含有虚函数的类
// 2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0
class A
{
public:
	virtual void f() {}
};
class B : public A
{};

void fun(A* pa, const string& s)
{
	cout <<"pa指向"<<s << endl;

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	// 指针指向父类转换失败，指向子类转换成功
	B* pb1 = (B*)pa;			   // 不安全的
	B* pb2 = dynamic_cast<B*>(pa); // 安全的

	cout << "[强制转换]pb1:" << pb1 << endl;
	cout << "[dynamic_cast转换]pb2:" << pb2 << endl << endl;
}

void dynamic_cast_test()
{
	A aa;
	B bb;

	// bb = (B)aa; 错误，对象不能转换
	fun(&aa, "指向父类对象"); // 父类对象
	// aa强制转成B*，是存在风险的，因为如果B有自己的成员，那么用指针可以访问这些成员，但是这样访问就是强制越界了

	fun(&bb, "指向子类对象"); // 子类对象 
	// 安全的 

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