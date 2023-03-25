#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	char a = '99';
//	int b = a - '0';
//	int c = a + '0';
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	return 0;
//}

//void Func(const string& str)
//{
//	// 遍历和读容器的数据，不要写的权限
//	string::const_iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	//string::const_reverse_iterator rit = str.rbegin();
//	auto rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//}
//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		//*it += 1;
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << ' ';
//		rit++;
//	}
//	cout << endl;
//
//	Func(s1);
//
//	return 0;
//}

//int main()
//{
//	// insert 在pos位置之前插入
//	string s1("world");
//	// string (1) string& insert(size_t pos, const string & str);
//	s1.insert(0,"hello");
//	cout << s1 << endl;
//
//	//fill (5) string& insert(size_t pos, size_t n, char c);
//	//s1.insert(5, 1, ' ');
//	//s1.insert(5, " ");
//	//single character (6) iterator insert(iterator p, char c);
//	s1.insert(s1.begin() + 5, ' ');
//	cout << s1 << endl;
//
//	cout << "-----------------" << endl;
//
//	string s2("hello world");
//	// sequence (1)	string& erase(size_t pos = 0, size_t len = npos);
//	//s2.erase(5, 1);
//	//s2.erase(5);
//	
//	// character (2) iterator erase(iterator p); 只删除一个字符
//	//s2.erase(s2.begin() + 5);
//	//range (3)	iterator erase(iterator first, iterator last);范围
//	s2.erase(s2.begin() + 5, s2.end()-1);
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	// string (1) string& replace(size_t pos, size_t len, const string & str); 
//	// string& replace(iterator i1, iterator i2, const string & str);
//	s1.replace(5, 1, "你好");
//	cout << s1 << endl;
//
//	string s2("hello world i love u");
//	// string (1) size_t find(const string & str, size_t pos = 0) const;
//	size_t num = 0;
//	for (auto ch : s2)
//	{
//		if (ch == ' ')
//			num++;
//	}
//	// 提前开空间，不初始化
//	s2.reserve(s2.size() + 2*num);
//	size_t pos = s2.find(" ");
//	while (pos != string::npos)
//	{
//		s2.replace(pos, 1, "%20");
//		pos = s2.find(" ", pos + 3);
//	}
//	cout << s2 << endl;
//
//	string s3("hello world i love u");
//	string newStr;
//	size_t num1 = 0;
//	for (auto ch : s3)
//	{
//		if (ch == ' ')
//			num1++;
//	}
//	newStr.reserve(s3.size() + 2 * num1);
//	for (auto ch : s3)
//	{
//		if (ch != ' ')
//			newStr += ch;
//		else
//			newStr += "%20";
//	}
//	s3 = newStr;
//	cout << s3 << endl;
//
//	cout << "---------------------" << endl;
//
//	string s4("xxxxxxxxxxxxxx");
//	s3.swap(s4);
//	cout << s3 << endl;
//	cout << s4 << endl;
//	
//	swap(s3, s4);
//	cout << s3 << endl;
//	cout << s4 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	// const char* c_str() const;
//	// 返回一个指向数组指针，数组和字符串一样，结尾加'\0'
//	cout << s1.c_str() << endl;
//	cout << (void*)s1.c_str() << endl;
//
//	s1 += '\0';
//	s1 += '\0';
//	s1 += "xxxxxxxxxxx";
//	// c_str 遇到\0 就停止，s1 会打印出所有内容
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//
//	string filename("test.cpp");
//	FILE* fout = fopen(filename.c_str(), "r");
//	if (fout == nullptr)
//	{
//		perror("fopen fail");
//	}
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//		
//	fclose(fout);
//	return 0;
//}

//int main()
//{
//	string file("string.cpp.tar.zip");
//	size_t pos = file.rfind('.');
//	if (pos != string::npos)
//	{
//		// string substr (size_t pos = 0, size_t len = npos) const;
//		//string suffix = file.substr(pos, file.size() - 1);
//		string suffix = file.substr(pos);
//		cout << suffix << endl;
//	}
//
// 	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//	}
//	start += 3;
//	size_t final = url.find('/', start);
//	string address = url.substr(start, final - start);
//	cout << address << endl;
//	return 0;
//}

int main()
{
	string str("Please, replace the vowels in this sentence by asterisks.");
	size_t found = str.find_first_of("abcdv");
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("abcdv", found + 1);
	}
	
	cout << str << '\n';
	
	string s1("hello world");
	string s2("hello world");
	s1 == s2;
	s1 == "hello world";
	"hello world" == s1;
	
	return 0;
}