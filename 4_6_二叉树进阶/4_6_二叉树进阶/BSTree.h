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
		BSTree() = default; // ָ��ǿ������Ĭ�Ϲ���
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
			// ����ǿ����Ļ����ʹ����µĽڵ�
			if (_root == nullptr)
			{
				_root = new Node(key);//�½�һ���ڵ㣬���ҳ�ʼ��Ϊkey
				return true;
			}

			Node* cur = _root;// ����һ������Ѱ��λ��
			Node* parent = nullptr;// ����һ�����ڵ�ָ�룬Ϊ���Ժ�������׼��
			// ���������� -- ������С�ڸ��ڵ㣬���������ڸ��ڵ�
			while (cur)
			{
				if (cur->_key > key)// Ҫ�����ֵС�ڵ�ǰ�ڵ㣬������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)// Ҫ�����ֵ���ڵ�ǰ�ڵ㣬������
				{
					parent = cur;
					cur = cur->_right;
				}
				else // ��� -- �޷�����
				{
					return false;
				}
			}
			// curΪ���߳�ѭ����˵���ҵ���Ҫ�����λ��
			cur = new Node(key);// �����½ڵ㣬��ָ�븳ֵ��cur
			// �ߵ�����˵�����Բ��룬�����жϴ�С��ѡ���������
			if (parent->_key > key)
			{
				parent->_left = cur;// -> �н����õĲ���
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
				if (key < cur->_key)//�ȵ�ǰ�ڵ�С��������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//�ȵ�ǰ�ڵ��������
				{
					parent = cur;
					cur = cur->_right;
				}
				else// ��ȣ��ҵ�Ҫɾ���Ľڵ�
				{
					// ɾ�����������������һ���ڵ�Ϊ�գ�ȫΪ��Ҳ������������������ڵ�ȫ��Ϊ��
					// 1.��Ϊ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)//���ڵ�Ķ�ʱ��ֱ�Ӹ�
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
						// ��Ҫɾ���ڵ�� ��������С�ڵ� �����Ҳ�������������ڵ����
						Node* pminR = cur;
						Node* minRight = cur->_right;//���ҵ�Ҫɾ���ڵ������
						// С�Ķ������
						while (minRight->_left)
						{
							pminR = minRight;// ���¸��ڵ�
							minRight = minRight->_left;//����С�Ľڵ㣬�����
						}
						// ����С�ڵ��Ҫɾ���Ľڵ��ֵ����
						swap(minRight->_key, cur->_key);
						// ɾ��֮ǰ�ҵ�����Сֵ��λ�ã���Ϊ����С�ڵ㣬����û����������������������������ڵ�����������Ӹýڵ��������
						if (pminR->_right == minRight)
						{
							// ���������Ҫɾ���ڵ���ҽڵ������С�ڵ㣬û�н���ѭ����Ҳ�����ҵ�����С�ڵ�ĸ��ڵ����Ҫɾ���Ľڵ㣬��ʱֻ�����Ӹ��ڵ���Ҳ�
							pminR->_right = minRight->_right;
						}
						else// һ�����
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
					// �ٴεݹ飬��Ϊɾ����ʱ���Ѿ���ֵ���н�����Ҫɾ����ֵ�������������������ڵ��������������С�ڵ㣬���������������һ�������һ�����������������ɾ�����
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
			// ����ǿ����Ļ����ʹ����µĽڵ�
			if (_root == nullptr)
			{
				_root = new Node(key,value);//�½�һ���ڵ㣬���ҳ�ʼ��Ϊkey
				return true;
			}

			Node* cur = _root;// ����һ������Ѱ��λ��
			Node* parent = nullptr;// ����һ�����ڵ�ָ�룬Ϊ���Ժ�������׼��
			// ���������� -- ������С�ڸ��ڵ㣬���������ڸ��ڵ�
			while (cur)
			{
				if (cur->_key > key)// Ҫ�����ֵС�ڵ�ǰ�ڵ㣬������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)// Ҫ�����ֵ���ڵ�ǰ�ڵ㣬������
				{
					parent = cur;
					cur = cur->_right;
				}
				else // ��� -- �޷�����
				{
					return false;
				}
			}
			// curΪ���߳�ѭ����˵���ҵ���Ҫ�����λ��
			cur = new Node(key, value);// �����½ڵ㣬��ָ�븳ֵ��cur
			// �ߵ�����˵�����Բ��룬�����жϴ�С��ѡ���������
			if (parent->_key > key)
			{
				parent->_left = cur;// -> �н����õĲ���
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
				if (key < cur->_key)//�ȵ�ǰ�ڵ�С��������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//�ȵ�ǰ�ڵ��������
				{
					parent = cur;
					cur = cur->_right;
				}
				else// ��ȣ��ҵ�Ҫɾ���Ľڵ�
				{
					// ɾ�����������������һ���ڵ�Ϊ�գ�ȫΪ��Ҳ������������������ڵ�ȫ��Ϊ��
					// 1.��Ϊ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)//���ڵ�Ķ�ʱ��ֱ�Ӹ�
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
						// ��Ҫɾ���ڵ�� ��������С�ڵ� �����Ҳ�������������ڵ����
						Node* pminR = cur;
						Node* minRight = cur->_right;//���ҵ�Ҫɾ���ڵ������
						// С�Ķ������
						while (minRight->_left)
						{
							pminR = minRight;// ���¸��ڵ�
							minRight = minRight->_left;//����С�Ľڵ㣬�����
						}
						// ����С�ڵ��Ҫɾ���Ľڵ��ֵ����
						swap(minRight->_key, cur->_key);
						// ɾ��֮ǰ�ҵ�����Сֵ��λ�ã���Ϊ����С�ڵ㣬����û����������������������������ڵ�����������Ӹýڵ��������
						if (pminR->_right == minRight)
						{
							// ���������Ҫɾ���ڵ���ҽڵ������С�ڵ㣬û�н���ѭ����Ҳ�����ҵ�����С�ڵ�ĸ��ڵ����Ҫɾ���Ľڵ㣬��ʱֻ�����Ӹ��ڵ���Ҳ�
							pminR->_right = minRight->_right;
						}
						else// һ�����
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
