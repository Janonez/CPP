#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3 = "hello world";
//	
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		s2[i]++;
//	}
//
//	cout << s2 << endl;
//
//	cout << s3.size() << endl;
//	cout << s3.capacity() << endl;
//
//	string s4 = s3 + "hello world";
//	cout << s4 << endl;
//
//	string s5("hello");
//	s5.push_back(' ');
//	s5.append("world");
//	s5.push_back('!');
//	cout << s5 << endl;
//	return 0;
//}

//int main()
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//    string num1 = "0", num2 = "0";
//    int sum1=0, sum2 = 0;
//    for (int i = 0; i < num1.size(); ++i)
//    {
//        sum1 = sum1 * 10 + (num1[i] - '0');
//    }
//    for (int i = 0; i < num2.size(); ++i)
//    {
//        sum2 = sum2 * 10 + (num2[i] - '0');
//    }
//    int sum = sum1 + sum2;
//    string ret;
//    int i = 0, tmp = 0;
//    while (sum)
//    {
//        tmp = sum % 10;
//        ret.push_back(tmp + '0');
//        sum /= 10;
//    }
//    int begin = 0, end = ret.size() - 1;
//    while (begin < end)
//    {
//        swap(ret[begin++], ret[end--]);
//    }
//    cout<<ret;
//
//	return 0;
//}


//int main()
//{
//	string s1;
//	string s2 = "hello world";
//	// copy (2)	string(const string & str);
//	string s3("hello world");
//
//	// substring (3) string (const string& str, size_t pos, size_t len = npos);
//	// 用str字符串的pos位置开始初始化，直到len位置，npos默认为一个很大的数（size_t）-1;
//	string s4(s3, 6, 3);
//	cout << s4 << endl;
//	string s5(s3, 6, 13);
//	cout << s5 << endl;
//	string s6(s3, 6);
//	cout << s6 << endl;
//
//	// from sequence (5) string (const char* s, size_t n);
//	// 拷贝s的前n个字符进行构造
//	string s7("hello world", 7);
//	cout << s7 << endl;
//
//	// fill (6)	string(size_t n, char c);
//	// 用n个字符初始化字符串
//	string s8(10, '#');
//	cout << s8 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		s2[i]++;
//	}
//	cout << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	// size() length() 计算字符串长度
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	// max_size 字符串最大的长度
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	s1.push_back(' ');
//	s1.push_back('!');
//	cout << s1 << endl;
//
//	// string (1) string& append(const string & str);
//	s1.append("world");
//	cout << s1 << endl;
//
//	s1 += ' ';
//	s1 += '!';
//	s1 += "world";
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	// 观察扩容情况
//	string s;
//	cout << s.capacity() << endl;
//	cout << sizeof(s) << endl;
//
//	s.reserve(10);
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	cout << "capacity changed: " << sz << '\n';
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << "------------------" << endl;
//	string s2("hello world");
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	s2.resize(100, 'x');
//	cout << s2 << endl;
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	return 0;
//}

int main()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
	return 0;
}