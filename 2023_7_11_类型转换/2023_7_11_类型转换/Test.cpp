#include <iostream>

using namespace std;

//// ����ת��
//void Test()
//{
//	int i = 1;
//	// ��ʽ����ת�����������Ƶ�����
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//	// ��ʾ��ǿ������ת��
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//}
//
//
////void insert(size_t pos, char ch)
////{
////	size_t end = _size;
////	// pos == 0ʱ�ͻ������,�޷��ŵ�end��end==0ʱ����ѭ������--end��Ϊ-1���޷��ű���ر�������������ѭ��
////	// ��Ϊ int end = _size; ͬ���������⣬�������Ͳ�ͬ���Ƚ�ʱ�ᷢ����ʽ����ת��
////	while (end >= pos)
////	{
////		//...
////		--end;
////	}
////}
//
//// C++��4������ת��
//// static_cast��reinterpret_cast��const_cast��dynamic_cast
//
//// 1.static_cast ��ʽ����ת��
//void static_cast_test()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//}
//
//// 2.reinterpret_cast ���������ת��
//void reinterpret_cast_test()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ����ʹ��static_cast�ᱨ��Ӧ��ʹ��reinterpret_cast
//	// int *p = static_cast<int*>(a);
//	int* p = reinterpret_cast<int*>(a);
//}
//
//// 3.const_cast ɾ��������const����,���㸳ֵ
//void const_cast_test()
//{
//	// const int a = 2;
//	volatile const int a = 2; // ȷ������ָ��ᱻ���������Ż������ԡ�
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl; // �޸���a������const�������������ƺ��滻���߼Ĵ���
//	cout << *p << endl;
//}
//
//// 4.dynamic_cast dynamic_cast ���ڽ�һ����������ָ��/����ת��Ϊ��������ָ�������(��̬ת��)
//// ����ת�ͣ��������ָ�� / ����->����ָ�� / ����(����Ҫת������ֵ���ݹ���)
//// ����ת�ͣ��������ָ�� / ����->����ָ�� / ����(��dynamic_castת���ǰ�ȫ��)
//// ע�⣺
//// 1. dynamic_castֻ�����ڸ��ຬ���麯������
//// 2. dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�0
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
//	cout <<"paָ��"<<s << endl;
//
//	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
//	// ָ��ָ����ת��ʧ�ܣ�ָ������ת���ɹ�
//	B* pb1 = (B*)pa;			   // ����ȫ��
//	B* pb2 = dynamic_cast<B*>(pa); // ��ȫ��
//
//	cout << "[ǿ��ת��]pb1:" << pb1 << endl;
//	cout << "[dynamic_castת��]pb2:" << pb2 << endl << endl;
//}
//
//void dynamic_cast_test()
//{
//	A aa;
//	B bb;
//
//	// bb = (B)aa; ���󣬶�����ת��
//	fun(&aa, "ָ�������"); // �������
//	// aaǿ��ת��B*���Ǵ��ڷ��յģ���Ϊ���B���Լ��ĳ�Ա����ô��ָ����Է�����Щ��Ա�������������ʾ���ǿ��Խ����
//
//	fun(&bb, "ָ���������"); // ������� 
//	// ��ȫ�� 
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
// IO��
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
//	// ctrl+c �ź�ǿ��ɱ������
//	// ctrl+z + ���� ��������ȡ��������־
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//
//	// istream��cin�������תbool ��string�Ķ���ȴ������תbool
//	// ��Ϊistream������bool -- explicit operator bool() const;
//	// ֧���Զ�������ת��������
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
//	// ��������ת��Ϊ�Զ�������
//	A aa1 = 1;
//	//A aa1 = static_cast<A>(1);
//
//	// �Զ�������ת��Ϊ��������
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
		// ����������д�ģ���������_yearΪ0�������
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
////	// �Զ�����������Ҫ�����Լ�����<< �� >>
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
//	// �����ƶ�д����д�����У�������string
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
//	// �ı���д C++�ı���д����
//	// �ı���д���ʣ��ڴ����κ����Ͷ���ת���ַ�����д
//	// c�����ı���д�ܲ����㣬��ΪҪ����ת�ַ���
//	// c++��װ���Ժ���кܴ������
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
//	string _filename; // �����ļ�
//};
//int main()
//{
//	ServerInfo winfo = { "192.0.0.1",80,{2023,7,11} };
//	string str;
//	cin >> str;
//	if (str == "������д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "�����ƶ�")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "�ı�д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//	else if (str == "�ı���")
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

// ���л��ͷ����л�
struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
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
	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}