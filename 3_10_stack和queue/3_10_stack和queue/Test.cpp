#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

#include "Stack.h"
#include "Queue.h"

void stack_test1()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	//stack_test1();
	Janonez::stack_test();
	Janonez::queue_test();
	return 0;
}