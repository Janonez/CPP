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

int main()
{
    string num1 = "0", num2 = "0";
    int sum1=0, sum2 = 0;
    for (int i = 0; i < num1.size(); ++i)
    {
        sum1 = sum1 * 10 + (num1[i] - '0');
    }
    for (int i = 0; i < num2.size(); ++i)
    {
        sum2 = sum2 * 10 + (num2[i] - '0');
    }
    int sum = sum1 + sum2;
    string ret;
    int i = 0, tmp = 0;
    while (sum)
    {
        tmp = sum % 10;
        ret.push_back(tmp + '0');
        sum /= 10;
    }
    int begin = 0, end = ret.size() - 1;
    while (begin < end)
    {
        swap(ret[begin++], ret[end--]);
    }
    cout<<ret;

	return 0;
}


