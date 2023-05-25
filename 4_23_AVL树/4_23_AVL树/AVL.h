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

	AVLTreeNode(const pair<K, V>& kv)// 构造函数
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
		
		// 不为空，开始插入，取出当前节点，寻找位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first) // 要插入的数据比该节点小，往左走
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first) // 要插入的数据比该节点大，往右走
			{
				parent = cur;
				cur = cur->_right;
			}
			else // 相同，返回失败
			{
				return false;
			}
		}
		// 走到这里说明找到了要插入的位置，为要插入的数据创建一个节点
		cur = new Node(kv);
		// 这时需要判断插入位置，与父节点的数据比较大小
		if (parent->_kv.first > kv.first)// 比父节点小，插入左边
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		// 将当前节点的_parent与父节链接
		cur->_parent = parent;

		// 更新平衡因子
		while (parent)
		{
			// 右子树+1，左子树-1
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			// 判断插入了该节点，祖先节点是否不平衡
			if (parent->_bf == 1 || parent->_bf == -1)// 平衡，继续向上查找
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
				// 旋转处理-让子树平衡
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
		// 空树也是AVL树
		if (root == nullptr) 
			return true;
		// 计算root节点的平衡因子：即root左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		if (diff != root->_bf)
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}
		
		return abs(diff) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}
	// 左单旋
	void RotateL(Node* parent)
	{
		// 定义需要旋转的节点
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		// 旋转
		parent->_right = subRL;
		// 判断是否为空，更新父子关系
		if (subRL)
			subRL->_parent = parent;

		// 记录parent的父节点
		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;
		// 判断父节点的父是否存在
		if (ppnode)
		{
			// 判断parent节点是ppnode的左右
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

	// 右单旋
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
		cout << a << "插入：" << t1.IsBalance() << endl;
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