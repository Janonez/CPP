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

	RBTreeNode(const T& data)// ���캯��
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

	// ����
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
			// �Ҳ�Ϊ�գ�������������ڵ�
			Node* subLeft = _node->_right; 
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else
		{
			// ��Ϊ�գ��ҵ������Ǹ������������Ǹ����Ƚڵ�(��������������ң������ǰ�ڵ��Ǹ��׽ڵ����������˵������������Ѿ��������)
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right) // �Ѿ��������ģ��������ϲ���
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
		if (_node->_left)// ������
		{
			// ��Ϊ�գ������������ҽڵ�
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}
			_node = subRight;
		}
		else
		{
			// ��Ϊ�գ��ҵ������Ǹ������������Ǹ����Ƚڵ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left) // �Ѿ��������ģ��������ϲ���
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

		// ��Ϊ�գ���ʼ���룬ȡ����ǰ�ڵ㣬Ѱ��λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			KeyOfT kot;
			if (kot(cur->_data) > kot(data)) // Ҫ��������ݱȸýڵ�С��������
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data)) // Ҫ��������ݱȸýڵ��������
			{
				parent = cur;
				cur = cur->_right;
			}
			else // ��ͬ������ʧ��
			{
				return make_pair(iterator(cur), false);
			}
		}
		
		// �ߵ�����˵���ҵ���Ҫ�����λ�ã�ΪҪ��������ݴ���һ���ڵ�
		cur = new Node(data);
		Node* newnode = cur;
		// ��ʱ��Ҫ�жϲ���λ�ã��븸�ڵ�����ݱȽϴ�С
		if (parent->_data > data)// �ȸ��ڵ�С���������
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
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
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
		return make_pair(iterator(newnode), true);
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
