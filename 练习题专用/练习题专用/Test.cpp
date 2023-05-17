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

#include <stdio.h>
int main() {
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	printf("%p %p %p\n", &a, &b, &c);
	return 0;
}