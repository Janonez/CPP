#include <iostream>

using namespace std;

//// 类型转换
//void Test()
//{
//	int i = 1;
//	// 隐式类型转换：意义相似的类型
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//	// 显示的强制类型转换
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//}
//
//
////void insert(size_t pos, char ch)
////{
////	size_t end = _size;
////	// pos == 0时就会出问题,无符号的end，end==0时进入循环，再--end变为-1，无符号变成特别大的数，陷入死循环
////	// 改为 int end = _size; 同样存在问题，两边类型不同，比较时会发生隐式类型转换
////	while (end >= pos)
////	{
////		//...
////		--end;
////	}
////}
//
//// C++的4种类型转换
//// static_cast、reinterpret_cast、const_cast、dynamic_cast
//
//// 1.static_cast 隐式类型转换
//void static_cast_test()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//}
//
//// 2.reinterpret_cast 不相关类型转换
//void reinterpret_cast_test()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 这里使用static_cast会报错，应该使用reinterpret_cast
//	// int *p = static_cast<int*>(a);
//	int* p = reinterpret_cast<int*>(a);
//}
//
//// 3.const_cast 删除变量的const属性,方便赋值
//void const_cast_test()
//{
//	// const int a = 2;
//	volatile const int a = 2; // 确保本条指令不会被编译器的优化而忽略。
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl; // 修改了a，但是const对象在这里类似宏替换或者寄存器
//	cout << *p << endl;
//}
//
//// 4.dynamic_cast dynamic_cast 用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)
//// 向上转型：子类对象指针 / 引用->父类指针 / 引用(不需要转换，赋值兼容规则)
//// 向下转型：父类对象指针 / 引用->子类指针 / 引用(用dynamic_cast转型是安全的)
//// 注意：
//// 1. dynamic_cast只能用于父类含有虚函数的类
//// 2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0
//class A
//{
//public:
//	virtual void f() {}
//};
//class B : public A
//{};
//
//void fun(A* pa, const string& s)
//{
//	cout <<"pa指向"<<s << endl;
//
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	// 指针指向父类转换失败，指向子类转换成功
//	B* pb1 = (B*)pa;			   // 不安全的
//	B* pb2 = dynamic_cast<B*>(pa); // 安全的
//
//	cout << "[强制转换]pb1:" << pb1 << endl;
//	cout << "[dynamic_cast转换]pb2:" << pb2 << endl << endl;
//}
//
//void dynamic_cast_test()
//{
//	A aa;
//	B bb;
//
//	// bb = (B)aa; 错误，对象不能转换
//	fun(&aa, "指向父类对象"); // 父类对象
//	// aa强制转成B*，是存在风险的，因为如果B有自己的成员，那么用指针可以访问这些成员，但是这样访问就是强制越界了
//
//	fun(&bb, "指向子类对象"); // 子类对象 
//	// 安全的 
//
//	cout << typeid(aa).name() << endl;
//}
//int main()
//{
//	// Test();
//	// static_cast_test();
//	// reinterpret_cast_test();
//	// const_cast_test();
//	dynamic_cast_test();
//	return 0;
//}

//---------------------------------------------------------------------------------------------
// IO流
//int main()
//{
//	cout << "1111111" << endl;
//	cerr << "4444444" << endl;
//	return 0;
//}

//#include <string>
//int main()
//{
//	string str;
//	// ctrl+c 信号强制杀死进程
//	// ctrl+z + 换行 流对象提取到结束标志
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//
//	// istream的cin对象可以转bool 而string的对象却不可以转bool
//	// 因为istream重载了bool -- explicit operator bool() const;
//	// 支持自定义类型转内置类型
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{}
//
//	operator int()
//	{
//		return _a;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	// 内置类型转换为自定义类型
//	A aa1 = 1;
//	//A aa1 = static_cast<A>(1);
//
//	// 自定义类型转换为内置类型
//	int x = aa1;
//	return 0;
//}


class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool() const
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}

private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

////int main()
////{
////	// 自定义类型则需要我们自己重载<< 和 >>
////	Date d(2022, 4, 10);
////	cout << d <<endl;
////
////	while (d)
////	{
////		cin >> d;
////		cout << d;
////	}
////
////	return 0;
////}
//
//#include <fstream>
//
////int main()
////{
////	std::ofstream ofs("test.txt", ofstream::out | ofstream::app);
////	ofs << "hello world";
////	ofs << "hello world";
////	return 0;
////}
//
//struct ServerInfo
//{
//	char _address[32];
//	// string _address;
//
//	int _port;
//	Date _date;
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{}
//
//	// 二进制读写，读写对象中，不能有string
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename, ofstream::out | ofstream::binary);
//		ofs.write((char*)&info, sizeof(info));
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename, ofstream::in | ofstream::binary);
//		ifs.read((char*)&info, sizeof(info));
//	}
//
//	// 文本读写 C++文本读写更简单
//	// 文本读写本质，内存中任何类型都是转成字符串在写
//	// c语言文本读写很不方便，因为要不断转字符串
//	// c++封装了以后就有很大的优势
//	void WriteText(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs << info._address << " ";
//		ofs << info._port << endl;
//		ofs << info._date << endl;
//	}
//
//	void ReadText(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs >> info._address;
//		ifs >> info._port;
//		ifs >> info._date;
//	}
//
//private:
//	string _filename; // 配置文件
//};
//int main()
//{
//	ServerInfo winfo = { "192.0.0.1",80,{2023,7,11} };
//	string str;
//	cin >> str;
//	if (str == "二进制写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "二进制读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "文本写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//	else if (str == "文本读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadText(rinfo);
//
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	
//
//
//	return 0;
//}

#include <sstream>

//int main()
//{
//	//ostringstream oss;
//	stringstream oss;
//	oss << 100 << " ";
//	oss << 11.22 << " ";
//	oss << "hello";
//
//	string str = oss.str();
//	cout << str << endl;
//
//	//istringstream iss(str);
//	stringstream iss(str);
//	int i;
//	double d;
//	string s;
//	iss >> i >> d >> s;
//	cout << i << endl;
//	cout << d << endl;
//	cout << s << endl;
//
//	return 0;
//}

// 序列化和反序列化
struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	stringstream oss;
	oss << winfo._name << " ";
	oss << winfo._id << " ";
	oss << winfo._date << " ";
	oss << winfo._msg;
	string str = oss.str();
	cout << str << endl;

	stringstream iss(str);
	ChatInfo rinfo;
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}