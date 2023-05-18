#pragma once
template<class K,class V>
class AVLTreeNode
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
	bool insert(const pair<K, V>& kv)
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

				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
private:
	Node* _root = nullptr;
};