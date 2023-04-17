#include <iostream>
#include <queue>
#include <functional>

using namespace std;
#include "PriorityQueue.h"

//void test_priority_queue()
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(1);
//	pq.push(0);
//	pq.push(5);
//	pq.push(2);
//	pq.push(9);
//	pq.push(7);
//
//	while (!pq.empty())
//	{
//		cout << pq.top();
//		pq.pop();
//	}
//	cout << endl;
//}

// ·Âº¯Êý -- ÖØÔØ()
//template<class T>
//struct Less
//{
//	bool operator()(const T& x,const T& y)
//	{
//		return x < y;
//	}
//};

int main()
{
	/*test_priority_queue();

	Less<int> lessfunc;
	cout << lessfunc(1, 2) << endl;
	cout << lessfunc(5, 2) << endl;*/

	Janonez::test_my_priority_queue();
	Janonez::test_my_priority_queue2();
	return 0;
}