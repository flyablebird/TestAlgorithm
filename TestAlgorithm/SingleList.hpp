#ifndef __SINGLELIST__H
#define __SINGLELIST__H
#pragma once

template <typename K,typename V>
class SingleListNode
{
public:
	SingleListNode(const K &k, const V &v)
		: key(k),value(v)
	{}
	SingleListNode() = default;
public:
	SingleListNode * m_next{};
	K key;
	V value;
};
template <typename K>
class SingleListNode<K,void>
{
public:
	SingleListNode() = default;
	SingleListNode(const K &k)
		: key(k)
	{}
public:
	SingleListNode *m_next{};
	K key;
};

template <typename K,typename V = void>
class SingleList
{
public:
	using node_type = SingleListNode<K, V>;

	void insert(node_type *pnode)
	{
		if (m_head)
		{
			pnode->m_next = m_head;
		}
		m_head = pnode;
	}
	//Ö»ÒÆ³ý±íÍ·
	void remove()
	{
		m_head = m_head->m_next;
	}
	bool remove(node_type *pnode)
	{
		bool ret{};
		node_type *p = m_head;
		node_type *prev = nullptr;
		while (p != nullptr && p != pnode)
		{
			prev = p;
			p = p->m_next;
		}
		if (p != nullptr)
		{
			if (prev == nullptr)
			{
				m_head = m_head->m_next;
			}
			else
			{
				prev->m_next = p->m_next;
			}
			ret = true;
		}
		return ret;
	}
	bool remove(const K &key)
	{
		bool ret{};
		node_type *p = search(key);
		if (p)
		{
			ret = remove(p);
		}
		return ret;
	}
	node_type * search(const K& key)
	{
		node_type *p = m_head;
		while (p != nullptr && p->key != key)
		{
			p = p->m_next;
		}
		return p;
	}
	void print()
	{
		node_type *p = m_head;
		while (p != nullptr)
		{
			std::cout << p->key << " ";
			p = p->m_next;
		}
		std::cout << std::endl;
	}
private:
	node_type *m_head{};
};

template <typename K,typename V = void>
class CircularSingleList
{
public:
	using node_type = SingleListNode<K, V>;

	CircularSingleList()
	{
		m_head.m_next = &m_head;
	}
	void insert(node_type *pnode)
	{
		pnode->m_next = m_head.m_next;
		m_head.m_next = pnode;
	}
	void remove()
	{
		m_head.m_next = m_head.m_next->m_next;
	}
	bool remove(node_type *pnode)
	{
		bool ret{};
		node_type *p = m_head.m_next;
		node_type *prev = &m_head;
		while (p != &m_head && p != pnode )
		{
			prev = p;
			p = p->m_next;
		}
		if (p != &m_head)
		{
			prev->m_next = p->m_next;
			ret = true;
		}
		return ret;
	}
	bool remove(const K &key)
	{
		bool ret{};
		node_type * p = search(key);
		if (p)
		{
			ret = remove(p);
		}
		return ret;
	}
	node_type * search(const K &key)
	{
		node_type *p = m_head.m_next;
		while ( p != &m_head && p->key != key)
		{
			p = p->m_next;
		}
		return p;
	}
	void print()
	{
		node_type * p = m_head.m_next;
		while (p != &m_head)
		{
			std::cout << p->key << " ";
			p = p->m_next;
		}
		std::cout << std::endl;
	}
private:
	node_type m_head;
};
#endif
