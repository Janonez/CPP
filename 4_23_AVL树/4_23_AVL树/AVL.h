#pragma once
template<class K,class V>
class AVLTreeNode
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
	bool insert(const pair<K, V>& kv)
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