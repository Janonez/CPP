#include <iostream>

using namespace std;

#include "BSTree.h"

void TestBSTree1()
{
	key::BSTree<int> t1;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t1.Insert(e);
	}

	t1.InOrder();

	cout << t1.Find(1) << endl;
	cout << t1.Find(4) << endl;
	cout << t1.Find(2) << endl;
}

void TestBSTree2()
{
	key::BSTree<int> t1;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t1.Insert(e);
	}

	t1.InOrder();

	//t1.Erase(8);
	t1.Erase(10);
	t1.Erase(14);
	t1.Erase(13);

	t1.InOrder();

}

void TestBSTree3()
{
	key::BSTree<int> t1;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t1.InsertR(e);
	}

	t1.InOrder();

	t1.Erase(8);
	t1.InOrder();

}

void TestBSTree4()
{
	key::BSTree<int> t1;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t1.InsertR(e);
	}
	t1.InOrder();

	key::BSTree<int> t2(t1);

	t2.InOrder();

}

void TestBSTree5()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("left", "���");
	dict.Insert("right", "�ұ�");
	dict.Insert("string", "�ַ���");
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "�޴˵���" << endl;
		}
	}
}
void TestBSTree6()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };

	key_value::BSTree<string, int> countTree;
	for (auto str : arr)
	{
		//key_value::BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}

int main()
{
	//cout << new BSTreeNode<int> << endl;
	//TestBSTree1();
	//TestBSTree2();
	//TestBSTree3();
	//TestBSTree4();
	//TestBSTree5();
	TestBSTree6();
	return 0;
}