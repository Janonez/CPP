#pragma once
#include <assert.h>
#include <time.h>
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)// ���캯��
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}

};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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

		// ����ƽ������
		while (parent)
		{
			// ������+1��������-1
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			// �жϲ����˸ýڵ㣬���Ƚڵ��Ƿ�ƽ��
			if (parent->_bf == 1 || parent->_bf == -1)// ƽ�⣬�������ϲ���
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if(parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת����-������ƽ��
				if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				else if (parent->_bf == -2 && cur->_bf == 1)
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1)
					RotateRL(parent);
				else
					assert(false);
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	int Height()
	{
		return _Height(_root);
	}
private:
	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	bool _IsBalance(Node* root)
	{
		// ����Ҳ��AVL��
		if (root == nullptr) 
			return true;
		// ����root�ڵ��ƽ�����ӣ���root���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		if (diff != root->_bf)
		{
			cout << root->_kv.first << "�ڵ�ƽ�������쳣" << endl;
			return false;
		}
		
		return abs(diff) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
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
		parent->_bf = subR->_bf = 0;
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

		subL->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);

		if (bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};

void Test_AVLTree1()
{
	//int arr[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;

	for (auto a : arr)
	{
		t1.Insert(make_pair(a, a));
		cout << a << "���룺" << t1.IsBalance() << endl;
	}

	t1.InOrder();

	cout << t1.IsBalance() << endl;
}

void Test_AVLTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	AVLTree<int, int> t;
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