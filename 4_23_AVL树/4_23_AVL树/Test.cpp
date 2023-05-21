#include <iostream>
using namespace std;
#include "AVL.h"

int main()
{
	int arr[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	AVLTree<int, int> t1;

	for (auto a : arr)
	{
		t1.Insert(make_pair(a, a));
		cout << a << "²åÈë£º" << t1.IsBalance() << endl;
	}
	return 0;
}