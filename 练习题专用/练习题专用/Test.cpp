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



int main()
{
    int a = 5, b = 7;
    //cin >> a >> b;
    int max = a > b ? a : b;
    int min = a > b ? b : a;
    int i = 1;
    int sum = max;
    while (i++)
    {
        if (sum % min == 0)
            break;
        else {
            sum = max * i;
        }
    }
    cout << sum << endl;
    return 0;
}