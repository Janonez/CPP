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


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return 0;
}