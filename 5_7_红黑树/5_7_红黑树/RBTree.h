#pragma once
#include <time.h>
enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)// ���캯��
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}

};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
public:
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		// ��Ϊ�գ���ʼ���룬ȡ����ǰ�ڵ㣬Ѱ��λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first) // Ҫ��������ݱȸýڵ�С��������
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first) // Ҫ��������ݱȸýڵ��������
			{
				parent = cur;
				cur = cur->_right;
			}
			else // ��ͬ������ʧ��
			{
				return false;
			}
		}
		// �ߵ�����˵���ҵ���Ҫ�����λ�ã�ΪҪ��������ݴ���һ���ڵ�
		cur = new Node(kv);
		// ��ʱ��Ҫ�жϲ���λ�ã��븸�ڵ�����ݱȽϴ�С
		if (parent->_kv.first > kv.first)// �ȸ��ڵ�С���������
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		// ����ǰ�ڵ��_parent�븸������
		cur->_parent = parent;


		// ������ɫ -- ��ɫ�ڵ����������ֻ��Ϊ�ڣ�����Ĭ�ϲ�����Ǻ�ڵ�
		// cur����ǰ�ڵ� parent�����ڵ� grandfather���游�ڵ� uncle������ڵ�
		while (parent && parent->_col == RED)// ������ڵ�ĸ��ڵ�ҲΪ��ʱ������Ҫ������
		{
			// ���һ��cur�� parent�� grandfather�� uncle������Ϊ��
			//     g
			//   p   u
			// c 
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED) // uncle������Ϊ��
				{
					grandfather->_col = RED;
					uncle->_col = BLACK;
					parent->_col = BLACK;
					//���½ڵ㣬�������ϣ��鿴�Ƿ���Ҫ������ɫ
					cur = grandfather;
					parent = cur->_parent;
					
					
				}
				else // uncle������/uncleΪ��
				{
					//     g
					//   p   u
					// c 
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
					//     g
					//   p   u
					//     c 
						RotateL(parent);
						cur->_col = BLACK;
						grandfather->_col = RED;
						RotateR(grandfather);
					}
					break;
				}
			}
			else // (parent == grandfer->_right)
			{
				//     g
				//   u   p
				//		   c 
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED) // uncle������Ϊ��
				{
					grandfather->_col = RED;
					uncle->_col = BLACK;
					parent->_col = BLACK;

					// ���½ڵ㣬�������ϣ��鿴�Ƿ���Ҫ������ɫ
					cur = grandfather;
					parent = cur->_parent;
				
				}
				else // uncle������/uncleΪ��
				{
					//     g
					//   u   p
					//         c 
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   u   p
						//     c 
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "���ڵ����ɫ�Ǻ�ɫ" << endl;
			return false;
		}
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		return _Check(_root, 0, benchmark);
	}

	void InOrder()
	{
		_InOrder(_root);
	}
	int Height()
	{
		return _Height(_root);
	}
private:
	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	bool _Check(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "ĳ��·����ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == BLACK)
			++blackNum;
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _Check(root->_left, blackNum, benchmark)
			&& _Check(root->_right, blackNum, benchmark);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}
	// ����
	void RotateL(Node* parent)
	{
		// ������Ҫ��ת�Ľڵ�
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		// ��ת
		parent->_right = subRL;
		// �ж��Ƿ�Ϊ�գ����¸��ӹ�ϵ
		if (subRL)
			subRL->_parent = parent;

		// ��¼parent�ĸ��ڵ�
		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;
		// �жϸ��ڵ�ĸ��Ƿ����
		if (ppnode)
		{
			// �ж�parent�ڵ���ppnode������
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
		else
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		
	}

	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		Node* ppnode = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (ppnode)
		{
			if (ppnode->_left == parent)
				ppnode->_left = subL;
			else
				ppnode->_right = subL;
		}
		else
		{
			_root = subL;
		}
		subL->_parent = ppnode;

	
	}

	
private:
	Node* _root = nullptr;
};

void Test_RBTree1()
{
	//int arr[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int,int> t1;

	for (auto a : arr)
	{
		t1.Insert(make_pair(a,a));
		//cout << a << "���룺" << t1.IsBalance() << endl;
	}

	t1.InOrder();

	cout << t1.IsBalance() << endl;
}

void Test_RBTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}

void Test_RBTree3()
{
	//int arr[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	int arr[] = { 30,15,70,10,20,60,85,5,50,65,80,90,40,55 };
	RBTree<int, int> t1;

	for (auto a : arr)
	{
		t1.Insert(make_pair(a, a));
		//cout << a << "���룺" << t1.IsBalance() << endl;
	}

	t1.InOrder();

	cout << t1.IsBalance() << endl;
}