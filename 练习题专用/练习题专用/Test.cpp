#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

//int func() {
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = -1; i++, j++) {
//		k++;
//	}
//	return k;
//}
//int main() {
//	//cout << (func());
//	int j = 0;
//	printf("%d\n", j = -111);
//	printf("%d\n", j = 1222);
//	printf("%d\n", j = 0);
//	return 0;
//}



//int main()
//{
//    int a = 5, b = 7;
//    //cin >> a >> b;
//    int max = a > b ? a : b;
//    int min = a > b ? b : a;
//    int i = 1;
//    int sum = max;
//    while (i++)
//    {
//        if (sum % min == 0)
//            break;
//        else {
//            sum = max * i;
//        }
//    }
//    cout << sum << endl;
//    return 0;
//}

//
//int main()
//{
//	int a = 1;
//	char* str1 = "abcd";
//	char str2[] = "abcd";
//	static int b = 2;
//	printf("a的地址:%p\n", &a);
//	printf("str1的地址:%p\n", &str1);
//	printf("abcd的地址:%p\n", str1);
//	printf("str2的地址:%p\n", &str2);
//	printf("b的地址:%p\n",&b);
//	return 0;
//}

//struct bs
//{
//    unsigned m;
//    unsigned n : 4;
//    unsigned char ch : 6;
//};
//int main()
//{
//    
//    cout << sizeof(struct bs) << endl;
//    return 0;
//}

//int main()
//{
//	long long a = 1;
//	long long b = 2;
//	long long c = 3;
//	printf("%d %d %d\n", a, b, c);
//	printf("%d\n", a);
//	printf("%d\n", b);
//	printf("%d\n", c);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h> // 提供strlen()函数的原型
//#define PRAISE "You are an extraordinary being."
//int main()
//{
//    char name[40];
//    printf("What's your name? ");
//    scanf("%s", name);
//    printf("Hello,%s. %s\n", name, PRAISE);
//    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name);
//    printf("The phrase of praise has %zd letters ", strlen(PRAISE));
//    printf("and occupies %zd memory cells.\n", sizeof PRAISE);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//	long long a = 1, b = 2, c = 3;
//	//printf("%d %d %d\n", a, b, c);
//	printf("%p %p %p\n", &a, &b, &c);
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int cur = 0; 
//    int ret = 0;
//    while (n)
//    {
//        if ((n & 1) == 1)
//        {
//            cur++;
//        }
//        else
//        {
//            if (cur > ret)
//            {
//                ret = cur;
//                cur = 0;
//            }
//        }
//        n = n >> 1;
//    }
//    if (cur > ret)
//        ret = cur;
//    cout << ret;
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//using namespace std;
//// 素数：质数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
//bool isPrime(int n)
//{
//    int m = sqrt(n);
//    int i;
//    for (i = 2; i <= m; ++i)
//    {
//        if (n % i == 0)
//            break;
//    }
//    if (i > m)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int tmp = n - 2;
//    int diff = n;
//    int cur = 0;
//    int ret = 0;
//    while (tmp >= (n / 2))
//    {
//        if (isPrime(tmp) && isPrime(n - tmp))
//        {
//            cur = tmp - (n - tmp);
//            if (cur < diff)
//            {
//                ret = tmp;
//                diff = cur;
//                cur = 0;
//            }
//        }
//        tmp--;
//    }
//    cout << ret << endl << n - ret << endl;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//void Div(int num, vector<int>& a)
//{
//    for (int i = 2; i <= sqrt(num); ++i)
//    {
//        if (num % i == 0)
//        {
//            a.push_back(i);
//            if (num / i != i)
//            {
//                a.push_back(num / i);
//            }
//        }
//        
//    }
//    sort(a.begin(), a.end());
//    //     for(auto s: a)
//    //     {
//    //         cout << s << " ";
//    //     }
//}
//int main()
//{
//    int n, m = 0;
//    cin >> n >> m;
//    int tmp = n;
//    int count = 0;
//    while (tmp != m)
//    {
//        // 寻找最大的约数
//        vector<int> a;
//        Div(tmp, a);
//        int i = a.size() - 1;
//        while (i)
//        {
//            if (tmp + a[i] > m)
//                i--;
//            else
//                break;
//        }
//        tmp += a[i];
//        count++;
//    }
//    cout << count;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> arr;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> arr[i];
//    }
//    sort(arr.begin(), arr.end());
//    for (auto a : arr)
//    {
//        cout << a << " ";
//    }
//    return 0;
//}
//
//inline const string& shorterString(const string& s1, const string& s2)
//{
//    return s1.size() <= s2.size() ? s1 : s2;
//}
//
//int main()
//{
//    string s1, s2, s3, s4, s5, s6;
//    // ...
//    cout<< (s1.size() <= s2.size() ? s1 : s2) << endl;
//    cout<< (s3.size() <= s4.size() ? s3 : s4) << endl;
//    cout<< (s5.size() <= s6.size() ? s5 : s6) << endl;
//    // ...
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void shuffle_cards(vector<int>& v1, vector<int>& v2, vector<int>* ret)
//{
//    vector<int>::reverse_iterator rit1 = v1.rbegin();
//    vector<int>::reverse_iterator rit2 = v2.rbegin();
//    vector<int> result = *ret;
//    while (rit1 != v1.rend() || rit2 != v2.rend())
//    {
//        result.push_back(*rit2);
//        result.push_back(*rit1);
//        ++rit1;
//        ++rit2;
//    }
//}
//
//int main()
//{
//    int T = 0;
//    cin >> T;
//    while (T--)
//    {
//        int n, k;
//        cin >> n >> k;
//        vector<int> v1;
//        vector<int> v2;
//        for (int i = 0; i < n; ++i)
//        {
//            int tmp = 0;
//            cin >> tmp;
//            v1.push_back(tmp);
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            int tmp = 0;
//            cin >> tmp;
//            v2.push_back(tmp);
//        }
//        vector<int> ret;
//        while (k--)
//        {
//            shuffle_cards(v1, v2,&ret);
//        }
//        for (int i = 0; i < ret.size(); ++i)
//        {
//            cout << ret[i] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int>& shuffle_cards(vector<int>& v, int n)
//{
//    size_t pos1 = n - 1;
//    size_t pos2 = 2 * n - 1;
//    static vector<int> ret;
//    while (pos1)
//    {
//        ret.push_back(v[pos2]);
//        ret.push_back(v[pos1]);
//        --pos2;
//        --pos1;
//    }
//    reverse(ret.begin(), ret.end());
//    return ret;
//}
//
//int main()
//{
//    int T = 0;
//    cin >> T;
//    while (T--)
//    {
//        int n, k;
//        cin >> n >> k;
//        vector<int> v;
//        for (int i = 0; i < 2 * n; ++i)
//        {
//            int tmp = 0;
//            cin >> tmp;
//            v.push_back(tmp);
//        }
//        while (k--)
//        {
//            v = shuffle_cards(v, n);
//        }
//        for (int i = 0; i < 2 * n; ++i)
//        {
//            cout << v[i] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int pageUp(int select, int n, int* pos)
//{
//    if (*pos == 0) // 当前在第一行，往前翻有两种情况
//    {
//        if (n <= 4)// 如果总数小于4个，直接翻到最后一行
//        {
//            *pos = n-1;
//        }
//        else // 如果总数大于四个，分两种情况
//        {
//            if (select == 1)// 当前是1，翻到最后一个数，最后一个位置
//            {
//                *pos = 3;
//            }
//            // 当前不是1，-1，还在第一个位置
//        }
//    }
//    else // 不在第一行，直接往前移动一行
//    {
//        *pos -= 1;
//    }
//    if (select == 1)
//        return n;
//    else
//        return select - 1;
//}
//int pageDown(int select, int n, int* pos)
//{
//    int end = n >= 4 ? 3 : n - 1;
//    if (*pos == end) // 当前在最后行，往前翻有两种情况
//    {
//        if (n <= 4)// 如果总数小于4个，直接翻到第一行
//        {
//            *pos = 0;
//        }
//        else // 如果总数大于四个，分两种情况
//        {
//            if (select == n)// 当前是最后一个值，翻到第一个数，第一个位置
//            {
//                *pos = 0;
//            }
//            // 当前不是最后一个值，-1，还在最后一个位置
//        }
//    }
//    else // 不在最后行，直接往后移动一行
//    {
//        *pos += 1;
//    }
//
//    if (select == n)
//        return 1;
//    else
//        return select + 1;
//}
//void pageUD(int n, const string& str) {
//    int select = 1;
//    int pos = 0;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] == 'U') // 向上翻页，分两种情况
//        {
//            select = pageUp(select, n, &pos);
//        }
//        else//str[i] == 'D' 
//        {
//            select = pageDown(select, n, &pos);
//        }
//    }
//    vector<int> v;
//    size_t local;
//    for (int i = 0; i < n; ++i)
//    {
//        v.push_back(i+1);
//        if (v[i] == select)
//        {
//            local = i - pos;
//        }
//    }
//    int count = 4;
//    if (local + 4 > n - 1)
//        count = n - 1;
//    while (count--)
//    {
//        cout << v[local] << " ";
//        local++;
//    }
//    cout << endl;
//    cout << select;
//
//}
//int main() {
//    int n = 0;
//    cin >> n;
//    string str;
//    cin >> str;
//    pageUD(n, str);
//
//    return 0;
//}

//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int gcd(int a, int b) {
//    // b是大于等于a的,b为被除数，a为除数
//    int divd = b;
//    int div = a;
//    int rem = divd % div;
//    while (rem) {
//        divd = div;
//        div = rem;
//        rem = divd % div;
//    }
//    return div;
//
//}
//int main() {
//    int a;
//    cin >> a; 
//    const int n = 3;
//        int b[n];
//        for (int i = 0; i < n; ++i) {
//            cin >> b[i];
//        }
//        int c = a;
//        for (int i = 0; i < n; ++i) {
//            // 开始打怪
//            if (c > b[i]) {
//                // 能力值c大于怪的防御力，直接打败并加防御力
//                c += b[i];
//            }
//            else {
//                // 能力值c小于怪的防御力，加最大公约数
//                c += gcd(c, b[i]);
//            }
//        }
//        cout << c << endl;
// 
//    return 0;
//}
//#include <vector>
//template<typename C>
//void print2nd(const C& container)    	//打印容器内的第二元素
//{
//	if (container.size() >= 2)
//	{
//		C::const_iterator iter(container.begin());	//取得第一元素的迭代器
//		++iter;										//将iter移往第二元素
//		int value = *iter;							//将该元素复制到某个int.
//		std::cout << value;							//打印那个int.
//	}
//}
//int main()
//{
//	std::vector<int> v = { 1,2,3,4 };
//	print2nd(v);
//	return 0;
//}
// 

//#include <iostream>
//#include <vector>
//class A
//{
//public:
//	A(int num = 10)
//		: _n(num)
//	{}
//private:
//	std::vector<int> _n;
//};
//
//int main()
//{
//	A aa;
//	return 0;
//}

//#include <iostream>
//int main()
//{
//	int n = 21 << 5;
//	int m = 21 ^ (n - 1);
//	std::cout << m;
//	return 0;
//}

// 多线程实现交错打印数字,实现两个线程依次交错打印1-100的奇数和偶数
//#include <iostream>
//#include <thread>
//using namespace std;
//int main()
//{
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int count = 0;
    string tmp;
    string ret;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            tmp += str[i];
        }
        else // 不是数字字符，则表示一个连续的数字串结束了，判断长度
        {
            if (ret.size() < tmp.size())
            {
                ret = tmp;

            }
            else
            {
                tmp = "";
            }

        }
    }
    if (ret.size() < tmp.size())
    {
        ret = tmp;

    }
    cout << ret;
}