#pragma once 

enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)// 构造函数
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}

};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	// 构造
	__RBTreeIterator(Node* node)
		: _node(node)
	{}

	__RBTreeIterator(const __RBTreeIterator<T, T&, T*>& it)
		: _node(it._node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
	Self& operator++()
	{
		if (_node->_right)
		{
			// 右不为空，找右子树最左节点
			Node* subLeft = _node->_right; 
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else
		{
			// 右为空，找到孩子是父亲左子树的那个祖先节点(中序遍历，左中右，如果当前节点是父亲节点的右子树，说明父亲这颗树已经遍历完成)
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right) // 已经遍历过的，继续向上查找
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;

		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)// 左子树
		{
			// 左不为空，找左子树最右节点
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}
			_node = subRight;
		}
		else
		{
			// 左为空，找到孩子是父亲右子树的那个祖先节点
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left) // 已经遍历过的，继续向上查找
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;

		}
		return *this;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			KeyOfT kot;
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
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

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		// 不为空，开始插入，取出当前节点，寻找位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			KeyOfT kot;
			if (kot(cur->_data) > kot(data)) // 要插入的数据比该节点小，往左走
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data)) // 要插入的数据比该节点大，往右走
			{
				parent = cur;
				cur = cur->_right;
			}
			else // 相同，返回失败
			{
				return make_pair(iterator(cur), false);
			}
		}
		
		// 走到这里说明找到了要插入的位置，为要插入的数据创建一个节点
		cur = new Node(data);
		Node* newnode = cur;
		// 这时需要判断插入位置，与父节点的数据比较大小
		if (parent->_data > data)// 比父节点小，插入左边
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
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
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
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else // (parent == grandfer->_right)
			{
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
		return make_pair(iterator(newnode), true);
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
