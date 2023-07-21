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

	RBTreeNode(const pair<K, V>& kv)// 构造函数
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


		// 更新颜色 -- 红色节点的左右子树只能为黑，我们默认插入的是红节点
		// cur：当前节点 parent：父节点 grandfather：祖父节点 uncle：叔叔节点
		while (parent && parent->_col == RED)// 当插入节点的父节点也为红时，就需要调整了
		{
			// 情况一：cur红 parent红 grandfather黑 uncle存在且为红
			//     g
			//   p   u
			// c 
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED) // uncle存在且为红
				{
					grandfather->_col = RED;
					uncle->_col = BLACK;
					parent->_col = BLACK;
					//更新节点，继续向上，查看是否需要更新颜色
					cur = grandfather;
					parent = cur->_parent;
					
					
				}
				else // uncle不存在/uncle为黑
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
				if (uncle && uncle->_col == RED) // uncle存在且为红
				{
					grandfather->_col = RED;
					uncle->_col = BLACK;
					parent->_col = BLACK;

					// 更新节点，继续向上，查看是否需要更新颜色
					cur = grandfather;
					parent = cur->_parent;
				
				}
				else // uncle不存在/uncle为黑
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
			cout << "根节点的颜色是红色" << endl;
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
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == BLACK)
			++blackNum;
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
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
		//cout << a << "插入：" << t1.IsBalance() << endl;
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
		//cout << a << "插入：" << t1.IsBalance() << endl;
	}

	t1.InOrder();

	cout << t1.IsBalance() << endl;
}