#pragma once

namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree() = default; // 指定强制生成默认构造
		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}
		~BSTree()
		{
			Destroy(_root);
		}
		bool Insert(const K& key)
		{
			// 如果是空树的话，就创建新的节点
			if (_root == nullptr)
			{
				_root = new Node(key);//新建一个节点，并且初始化为key
				return true;
			}

			Node* cur = _root;// 拷贝一份用来寻找位置
			Node* parent = nullptr;// 定义一个父节点指针，为了以后链接做准备
			// 二叉搜索树 -- 左子树小于根节点，右子树大于根节点
			while (cur)
			{
				if (cur->_key > key)// 要插入的值小于当前节点，往左走
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)// 要插入的值大于当前节点，往右走
				{
					parent = cur;
					cur = cur->_right;
				}
				else // 相等 -- 无法插入
				{
					return false;
				}
			}
			// cur为空走出循环，说明找到了要插入的位置
			cur = new Node(key);// 创建新节点，将指针赋值给cur
			// 走到这里说明可以插入，还需判断大小，选择插入左右
			if (parent->_key > key)
			{
				parent->_left = cur;// -> 有解引用的操作
			}
			if (parent->_key < key)
			{
				parent->_right = cur;
			}

			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}

			return false;
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)//比当前节点小，往左走
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//比当前节点大，往右走
				{
					parent = cur;
					cur = cur->_right;
				}
				else// 相等，找到要删除的节点
				{
					// 删除，分两种情况，有一个节点为空（全为空也可以算在这里），两个节点全不为空
					// 1.左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)//根节点改动时，直接改
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						// 找要删除节点的 右树的最小节点 替代，也可以是左树最大节点替代
						Node* pminR = cur;
						Node* minRight = cur->_right;//先找到要删除节点的右树
						// 小的都在左边
						while (minRight->_left)
						{
							pminR = minRight;// 更新父节点
							minRight = minRight->_left;//找最小的节点，最左侧
						}
						// 将最小节点和要删除的节点的值互换
						swap(minRight->_key, cur->_key);
						// 删除之前找到的最小值的位置，因为是最小节点，所以没有左子树，最多又右子树，将父节点的左子树连接该节点的右子树
						if (pminR->_right == minRight)
						{
							// 特殊情况，要删除节点的右节点就是最小节点，没有进入循环，也就是找到的最小节点的父节点就是要删除的节点，这时只能连接父节点的右侧
							pminR->_right = minRight->_right;
						}
						else// 一般情况
						{
							pminR->_left = minRight->_right;
						}
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	protected:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}
		void Destroy(Node*& root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key == key)
				return true;

			if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return _FindR(root->_right, key);
		}
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* maxLeft = root->_left;
					while (maxLeft->_right)
					{
						maxLeft = maxLeft->_right;
					}
					swap(_root->_key, maxLeft->_key);
					// 再次递归，因为删除的时候已经把值进行交换，要删除的值被换到了左子树的最大节点或者右子树的最小节点，无论是那种情况，一定最多有一个子树，进入上面的删除情况
					return _EraseR(root->_left, key);
				}
				delete del;
				return true;
			}
		}
	private:
		Node* _root = nullptr;
	};
}

namespace key_value
{

	template<class K,class V>
	struct BSTreeNode
	{
		BSTreeNode<K,V>* _left;
		BSTreeNode<K,V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key,const V& value)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
	public:
		
		bool Insert(const K& key, const V& value)
		{
			// 如果是空树的话，就创建新的节点
			if (_root == nullptr)
			{
				_root = new Node(key,value);//新建一个节点，并且初始化为key
				return true;
			}

			Node* cur = _root;// 拷贝一份用来寻找位置
			Node* parent = nullptr;// 定义一个父节点指针，为了以后链接做准备
			// 二叉搜索树 -- 左子树小于根节点，右子树大于根节点
			while (cur)
			{
				if (cur->_key > key)// 要插入的值小于当前节点，往左走
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)// 要插入的值大于当前节点，往右走
				{
					parent = cur;
					cur = cur->_right;
				}
				else // 相等 -- 无法插入
				{
					return false;
				}
			}
			// cur为空走出循环，说明找到了要插入的位置
			cur = new Node(key, value);// 创建新节点，将指针赋值给cur
			// 走到这里说明可以插入，还需判断大小，选择插入左右
			if (parent->_key > key)
			{
				parent->_left = cur;// -> 有解引用的操作
			}
			if (parent->_key < key)
			{
				parent->_right = cur;
			}

			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)//比当前节点小，往左走
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//比当前节点大，往右走
				{
					parent = cur;
					cur = cur->_right;
				}
				else// 相等，找到要删除的节点
				{
					// 删除，分两种情况，有一个节点为空（全为空也可以算在这里），两个节点全不为空
					// 1.左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)//根节点改动时，直接改
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						// 找要删除节点的 右树的最小节点 替代，也可以是左树最大节点替代
						Node* pminR = cur;
						Node* minRight = cur->_right;//先找到要删除节点的右树
						// 小的都在左边
						while (minRight->_left)
						{
							pminR = minRight;// 更新父节点
							minRight = minRight->_left;//找最小的节点，最左侧
						}
						// 将最小节点和要删除的节点的值互换
						swap(minRight->_key, cur->_key);
						// 删除之前找到的最小值的位置，因为是最小节点，所以没有左子树，最多又右子树，将父节点的左子树连接该节点的右子树
						if (pminR->_right == minRight)
						{
							// 特殊情况，要删除节点的右节点就是最小节点，没有进入循环，也就是找到的最小节点的父节点就是要删除的节点，这时只能连接父节点的右侧
							pminR->_right = minRight->_right;
						}
						else// 一般情况
						{
							pminR->_left = minRight->_right;
						}
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
	protected:
		
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key <<":"<< root->_value << " ";
			_InOrder(root->_right);
		}
		
	private:
		Node* _root = nullptr;
	};
}
