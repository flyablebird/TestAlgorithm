#ifndef __CIRCULARDLIST__H
#define __CIRCULARDLIST__H
#pragma once

#include <iostream>

template <typename K,typename V = void>
class DListNode
{
public:
	using key_type = K;
	using value_type = V;

	DListNode(const K &k,const V &v)
	{
		key = k;
		value = v;
	}
	DListNode() = default;
public:
	DListNode* m_prev{};
	DListNode* m_next{};
	K key;
	V value;
};

template <typename K>
class DListNode<K,void>
{
public:
	using key_type = K;

	DListNode() = default;
	DListNode(const K &k)
	{
		key = k;
	}
public:
	DListNode* m_prev{};
	DListNode* m_next{};
	K key;
};

template<typename K,typename V = void>
class DList
{
public:
	using node_type = DListNode<K,V>;

	void insert(node_type *pnode)
	{
		pnode->m_next = m_head;
		if (m_head)
		{
			m_head->m_prev = pnode;
		}
		m_head = pnode;
		pnode->m_prev = nullptr;
	}
	node_type* search(K k)
	{
		node_type* p = m_head;
		while (p != nullptr && k != p->key)
		{
			p = p->m_next;
		}
		return p;
	}
	void remove(node_type* pnode)
	{
		if (pnode->m_prev)
		{
			pnode->m_prev->m_next = pnode->m_next;
		}
		else
		{
			m_head = pnode->m_next;
		}
		if (pnode->m_next)
		{
			pnode->m_next->m_prev = pnode->m_prev;
		}
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
class CircularDList
{
public:
	using node_type = DListNode<K,V>;
	using size_type = unsigned int;

	CircularDList()
	{
		// 链表空时，形成自环
		m_nil.m_next = &m_nil;
		m_nil.m_prev = &m_nil;
	}
	void insert(node_type *pnode)
	{
		pnode->m_next = m_nil.m_next;
		m_nil.m_next = pnode;
		pnode->m_prev = &m_nil;
		pnode->m_next->m_prev = pnode;

	}
	node_type* search(K k)
	{
		node_type *p = m_nil.m_next;
		while (p != &m_nil && k != p->key)
		{
			p = p->m_next;
		}
		return p;
	}
	void remove(node_type* pnode)
	{
		// 使用哨兵后，确保了每个内部节点的属性节点都不为空，从而无需判断前后边界
		pnode->m_prev->m_next = pnode->m_next;
		pnode->m_next->m_prev = pnode->m_prev;

	}
	void print()
	{
		node_type * p = m_nil.m_next;
		while (p != &m_nil)
		{
			std::cout << p->key << " ";
			p = p->m_next;
		}
		std::cout << std::endl;
	}
private:
	node_type m_nil;
};

#endif
