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
//	printf("a�ĵ�ַ:%p\n", &a);
//	printf("str1�ĵ�ַ:%p\n", &str1);
//	printf("abcd�ĵ�ַ:%p\n", str1);
//	printf("str2�ĵ�ַ:%p\n", &str2);
//	printf("b�ĵ�ַ:%p\n",&b);
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
//#include <string.h> // �ṩstrlen()������ԭ��
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
//// ������������ָ�ڴ���1����Ȼ���У�����1�����������ⲻ����������������Ȼ����
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
//        // Ѱ������Լ��
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
//    if (*pos == 0) // ��ǰ�ڵ�һ�У���ǰ�����������
//    {
//        if (n <= 4)// �������С��4����ֱ�ӷ������һ��
//        {
//            *pos = n-1;
//        }
//        else // ������������ĸ������������
//        {
//            if (select == 1)// ��ǰ��1���������һ���������һ��λ��
//            {
//                *pos = 3;
//            }
//            // ��ǰ����1��-1�����ڵ�һ��λ��
//        }
//    }
//    else // ���ڵ�һ�У�ֱ����ǰ�ƶ�һ��
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
//    if (*pos == end) // ��ǰ������У���ǰ�����������
//    {
//        if (n <= 4)// �������С��4����ֱ�ӷ�����һ��
//        {
//            *pos = 0;
//        }
//        else // ������������ĸ������������
//        {
//            if (select == n)// ��ǰ�����һ��ֵ��������һ��������һ��λ��
//            {
//                *pos = 0;
//            }
//            // ��ǰ�������һ��ֵ��-1���������һ��λ��
//        }
//    }
//    else // ��������У�ֱ�������ƶ�һ��
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
//        if (str[i] == 'U') // ���Ϸ�ҳ�����������
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
//    // b�Ǵ��ڵ���a��,bΪ��������aΪ����
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
//            // ��ʼ���
//            if (c > b[i]) {
//                // ����ֵc���ڹֵķ�������ֱ�Ӵ�ܲ��ӷ�����
//                c += b[i];
//            }
//            else {
//                // ����ֵcС�ڹֵķ������������Լ��
//                c += gcd(c, b[i]);
//            }
//        }
//        cout << c << endl;
// 
//    return 0;
//}
//#include <vector>
//template<typename C>
//void print2nd(const C& container)    	//��ӡ�����ڵĵڶ�Ԫ��
//{
//	if (container.size() >= 2)
//	{
//		C::const_iterator iter(container.begin());	//ȡ�õ�һԪ�صĵ�����
//		++iter;										//��iter�����ڶ�Ԫ��
//		int value = *iter;							//����Ԫ�ظ��Ƶ�ĳ��int.
//		std::cout << value;							//��ӡ�Ǹ�int.
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

// ���߳�ʵ�ֽ����ӡ����,ʵ�������߳����ν����ӡ1-100��������ż��
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
        else // ���������ַ������ʾһ�����������ִ������ˣ��жϳ���
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