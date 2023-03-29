#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;

//int main()
//{
//    string s("Let's take LeetCode contest");
//    size_t pos = s.find(' ');
//    // if(pos == string::npos)
//    // {
//    //     reverse(s.begin(),s.end());
//    //     return 
//    // }
//    int i = 0;
//    while (pos != string::npos)
//    {
//        reverse(s.begin() + i, s.begin() + pos);
//        i = (pos + 1);
//        pos = s.find(' ', pos + 1);
//    }
//    reverse(s.begin() + i, s.end());
//
//    cout << (int)'0';
//    return 0;
//}

//int main()
//{
//    string num1("123"), num2("456");
//    if (num1.size() < num2.size())
//        num1.swap(num2);
//    int s1 = 0;
//    for (auto ch : num1)
//    {
//        s1 += (s1 * 10 + (ch - '0'));
//    }
//    int s2 = 0;
//    int end2 = num2.size() - 1;
//    //for(;end2>=0;--end2)
//    for (auto ch : num2)
//    {
//        s2 += s2 * 10 + s1 * (ch - '0');
//    }
//    string s;
//     s += s2;
//
//     cout << s2;
//    return 0;
//}

//int main()
//{
//    string num1("123");
//    string num2("456");
//    int len1 = num1.size();
//    int len2 = num2.size();
//    string res(len1 + len2, '0');
//    for (int i = len1 - 1; i >= 0; i--)
//    {
//        for (int j = len2 - 1; j >= 0; j--)
//        {
//            int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
//            res[i + j + 1] = tmp % 10 + '0';
//            res[i + j] += tmp / 10;
//        }
//    }
//    for (int i = 0; i < len1 + len2; i++)
//    {
//        if (res[i] != '0')
//        {
//            cout << res.substr(i);
//            return 0;
//        }
//            
//    }
//    cout << "0";
//
//    return 0;
//}

//int main()
//{
//	string s1;
//	cout << s1.capacity() << endl;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << (int)"лл" << endl;
//	return 0;
//}
#include <iostream>
using namespace std;
#include "string.h"

int main()
{
	//janonez::test_string1();
	//janonez::test_string2();
	//janonez::test_string3();
	//janonez::test_string4();
	//janonez::test_string5();
	//janonez::test_string6();
	//janonez::test_string7();
	//janonez::test_string8();
	//janonez::test_string9();
	//janonez::test_string10();

	/*string s1("hello world");
	cout << s1.capacity() << endl;
	s1.resize(19, 'x');
	cout << s1.capacity() << endl;
	cout << s1;*/

	/*string s1("hello world");
	s1.insert(s1.begin()+5, 'x');
	cout << s1 << endl;*/

	janonez::string s1;
	std::string s2;
	cout << sizeof(s1) << endl; //24
	cout << sizeof(s2) << endl; // 40 

	janonez::string s3("11111");  // 24
	std::string s4("1111111"); // 40

	cout << sizeof(s3) << endl;
	cout << sizeof(s4) << endl;

	return 0;
}
