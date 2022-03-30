#ifndef __STACK__H
#define __STACK__H
#pragma once 

#include <initializer_list>
#include <typeinfo>
#include <iostream>

template<typename T>
class ArrStack;

template<typename T>
class StackIterator
{
	friend class ArrStack<T>;
public:
	using container_type = ArrStack<T>;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	StackIterator(container_type& t)
		: m_container(t)
	{}
	T & operator *()
	{
		return m_container.m_pData[m_pos];
	}
	StackIterator &operator ++()
	{
		++m_pos;
		return *this;
	}
	StackIterator operator ++(int)
	{
		StackIterator ret(*this);
		++m_pos;
		return ret;
	}
	pointer operator ->()
	{
		return &m_container.m_pData[m_pos];
	}
	bool operator == (const StackIterator &iter)
	{
		//bool b1 = &m_container == &iter.m_container;
		//bool b2 = m_pos == iter.m_pos;
		//return b1 && b2;
		return &m_container == &iter.m_container && m_pos == iter.m_pos;
	}
	bool operator != (const StackIterator& iter)
	{
		return !(* this == iter);
	}

	//没处理越界访问
	StackIterator operator + (unsigned int n)
	{
		StackIterator ret(*this);
		ret.m_pos += n;
		return ret;
	}
private:
	container_type& m_container;
	// 堆的实现使用序号从1开始
	unsigned int m_pos = 1;
};

template<typename T>
class ArrStack
{
	friend class StackIterator<T>;

public:
	using value_type = T;
	using iterator = StackIterator<T>;

	iterator begin()
	{
		iterator iter(*this);
		return iter;
	}
	iterator end()
	{
		iterator iter(*this);
		//没处理越界
		iter.m_pos = iter.m_container.pos + 1;
		return iter;
	}

	ArrStack();
	ArrStack(const std::initializer_list<T> & t)
	{
		m_pData = new T[m_size];
		for (auto x : t)
		{
			push(x);
		}
	}
	~ArrStack();
	void push(const T& d)
	{
		if (full())
		{
			std::cout << "this arrstack is full!." << std::endl;
			return;
		}
		++pos;
		m_pData[pos] = d;
	}
	T pop()
	{
		if (empty())
		{
			std::cout << "this arrstack is empty!." << std::endl;
			return T();
		}
		T ret = m_pData[pos];
		--pos;
		return ret;
	}
	bool empty()
	{
		return pos == 0;
	}
	bool full()
	{
		return pos == m_size - 1;
	}
	void print()
	{
		for (int i = 1; i <= pos; ++i)
		{
			std::cout << m_pData[i] << " ";
		}
		std::cout << std::endl;
	}
private:
	unsigned int m_size = 1024;
	unsigned int pos = 0;
	T *m_pData;
};



template<typename T>
inline ArrStack<T>::ArrStack()
{
	m_pData = new T[m_size];
}

template<typename T>
inline ArrStack<T>::~ArrStack()
{
	if (m_pData)
	{
		delete [] m_pData;
		m_pData = nullptr;
	}
}

template<typename T>
using Stack = ArrStack<T>;

#endif
