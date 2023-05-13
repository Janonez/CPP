#include <iostream>
#include <set>

using namespace std;

void test_set1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(3);

	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	for (auto s : s1)
	{
		cout << s << " ";
	}
	cout << endl;
}


int main()
{
	test_set1();
	return 0;
}