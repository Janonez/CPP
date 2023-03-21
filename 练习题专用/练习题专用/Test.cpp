#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

int func() {
	int i, j, k = 0;
	for (i = 0, j = -1; j = -1; i++, j++) {
		k++;
	}
	return k;
}
int main() {
	//cout << (func());
	int j = 0;
	printf("%d\n", j = -111);
	printf("%d\n", j = 1222);
	printf("%d\n", j = 0);
	return 0;
}