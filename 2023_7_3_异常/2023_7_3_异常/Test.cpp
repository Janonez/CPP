#include <iostream>
using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	int a, b;
//	cin >> a >> b;
//	Division(a, b);
//
//	//try
//	//{
//	//	cout << Division(a, b) << endl;
//	//}
//	//catch (const char* str)
//	//{
//	//	cout << str << endl;
//	//}
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}

#include <string>

//class Exception
//{
//public:
//	Exception(int errid, const string& errmsg)
//		: _errid(errid)
//		, _errmsg(errmsg)
//	{}
//
//	const string& GetMsg() const
//	{
//		return _errmsg;
//	}
//		
//	int GetErrid() const
//	{
//		return _errid;
//	}
//private:
//	int _errid;//������
//	string _errmsg;//��������
//};
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		//Exception err(1, "��0����");
//		//throw err;
//
//		throw Exception(1, "��0����");
//
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	int a, b;
//	cin >> a >> b;
//	Division(a, b);
//
//	//try
//	//{
//	//	cout << Division(a, b) << endl;
//	//}
//	//catch (const char* str)
//	//{
//	//	cout << str << endl;
//	//}
//}

//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (const Exception& e)
//		{
//			cout << e.GetErrid() << ":" << e.GetMsg() << endl;
//		}
//		catch (...) // �ŵ���󣬲����������͵��쳣����ֹ��һЩ�쳣û���񣬵��³�����ֹ
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//	
//	return 0;
//}


//-----------------------------�̳����쳣-----------------------------
#include <thread>
class Exception
{
public:
	Exception(int errid, const string& errmsg)
		: _errid(errid)
		, _errmsg(errmsg)
	{}

	int GetErrid() const
	{
		return _errid;
	}

	virtual string what() const  // ��̬
	{
		return _errmsg;
	}
protected:
	int _errid;//������
	string _errmsg;//��������
};

class SqlException : public Exception
{
public:
	SqlException(int errid, const string& errmsg, const string& sql)
		: Exception(errid,errmsg) // ����Ĳ���������û��๹��
		, _sql(sql)
	{}

	virtual string what() const
	{
		string msg = "SqlException: ";
		msg += _errmsg;
		msg += "->";
		msg += _sql;

		return msg;
	}
protected:
	string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(id, errmsg)
	{}
	virtual string what() const
	{
		string msg = "CacheException: ";
		msg += _errmsg;

		return msg;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(id, errmsg)
		, _type(type)
	{}

	virtual string what() const
	{
		string msg = "HttpServerException: ";
		msg += _errmsg;
		msg += "->";
		msg += _type;

		return msg;
	}

private:
	const string _type;
};

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException(100, "Ȩ�޲���", "select * from name = '����'");
	}

	cout << "���óɹ�" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	//ģ��������
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}

	CacheMgr();
}

//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//
//		try
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // ���ﲶ�������Ϳ���
//		{
//			// ��̬
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "Division by zero condition!";
	return (double)a / (double)b;
}

void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ�����������׳�ȥ��
	int* array = new int[10];
	int len, time;
	cin >> len >> time;
	try
	{
		cout << Division(len, time) << endl;
		HttpServer();
	}
	catch (...)   // �쳣�������׳�
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;   // ����ʲô��ʲô
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (const Exception& e) // ���ﲶ�������Ϳ���
	{
		// ��̬
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}

	return 0;
}