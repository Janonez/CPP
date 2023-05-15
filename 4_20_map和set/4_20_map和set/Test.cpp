#include <iostream>
#include <set>
#include <map>

// set - key
// map - key/value

using namespace std;

void test_set1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// �������������޸�key�����ܻ��ƻ��޸Ĺ���
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

void test_set2()
{
	// ���� + ȥ��
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	int x;
	while (cin >> x)
	{
		/*auto ret = s1.find(x);
		if (ret != s1.end())
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}*/

		if (s1.count(x))
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
	}
}

void test_set3()
{
	// ����
	multiset<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);

	multiset<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ���key��find����ĵ�һ��key
	auto ret = s1.find(1);
	while (ret != s1.end() && *ret == 1)
	{
		cout << *ret << " ";
		++ret;
	}
	cout << endl;

	cout << s1.count(1) << endl;
	cout << s1.count(2) << endl;
}

void test_map1()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));

	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << ":" << (*dit).second << endl;
		++dit;
	}
	cout << endl;
}

void test_map2()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));
	dict.insert(make_pair("string", "(�ַ���)")); // ����ʧ��
	
}

int main()
{
	//test_set1();
	//test_set2();
	//test_set3();

	test_map1();
	return 0;
}