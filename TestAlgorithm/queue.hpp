#ifndef __QUEUE__H
#define __QUEUE__H
#pragma once

#include <memory>
#include <initializer_list>
#include <iostream>

template <typename T>
class Queue;

template <typename T>
class QueueIterator
{
	using container_type = Queue<T>;
	using value_type = T;
	using pointer = T * ;
	using reference = T & ;

	friend class Queue<T>;

public:
	QueueIterator(container_type & container)
		:m_container(container),m_pos(container.m_head)
	{
	}
	reference operator *()
	{
		return m_container.m_p[m_pos];
	}
	QueueIterator & operator ++()
	{
		//没处理越界
		m_container.fixIndex(m_pos);
		return *this;
	}
	QueueIterator operator ++(int)
	{
		QueueIterator ret(*this);
		m_container.fixIndex(m_pos);
		return ret;
	}
	pointer operator ->()
	{
		return &m_container.m_p[m_pos];
	}
	bool operator == (QueueIterator &iter)
	{
		return &m_container == &iter.m_container && m_pos == iter.m_pos;
	}
	bool operator !=(QueueIterator &iter)
	{
		return !(*this == iter);
	}

private:
	container_type &m_container;
	unsigned int m_pos = 0;
};

template <typename T>
class Queue
{
	using iterator = QueueIterator<T>;

	friend class QueueIterator<T>;

public:
	Queue()
	{
		m_p = new T[m_size];
	}
	Queue(const std::initializer_list<T>& datas)
	{
		m_p = new T[m_size];
		for (auto& x : datas)
		{
			enqueue(x);
		}
	}
	~Queue()
	{
		if (m_p)
		{
			delete[] m_p;
			m_p = nullptr;
		}
	}
	void enqueue(const T& data)
	{
		if (full())
		{
			std::cout << "the queue is full!" << std::endl;
			return;
		}
		m_p[m_tail] = data;
		if (m_tail == m_size - 1)
		{
			m_tail = 0;
		}
		else
		{
			++m_tail;
		}
		++m_count;
	}
	T dequeue()
	{
		if (empty())
		{
			std::cout << "the queue is empty!" << std::endl;
			return T();
		}
		T ret = m_p[m_head];
		if (m_head == m_size - 1)
		{
			m_head = 0;
		}
		else
		{
			++m_head;
		}
		--m_count;
		return ret;
	}
	unsigned int size()
	{
		unsigned int ret{};
		if (m_head < m_tail)
		{
			ret = m_tail - m_head;
		}
		else
		{
			ret = m_size - m_head + m_tail;
		}
		return ret;
	}
	bool empty()
	{
		return m_head == m_tail;
	}
	bool full()
	{
		bool ret{};
		if (m_tail == m_size - 1)
		{
			ret = m_head == 0;
		}
		else
		{
			ret = m_head == m_tail + 1;
		}
		return ret;
	}

	iterator begin()
	{
		iterator ret(*this);
		return ret;
	}
	iterator end()
	{
		iterator ret(*this);
		ret.m_pos = m_tail;
		return ret;
	}
	void print()
	{
		if (m_head < m_tail)
		{
			for (unsigned int i = m_head; i < m_tail; ++i)
			{
				std::cout << m_p[i] << " ";
			}
			std::cout << std::endl;
		}
		else if(m_tail < m_head)
		{
			for (unsigned int i = m_head; i < m_size; ++i)
			{
				std::cout << m_p[i] << " ";
			}
			for (unsigned int i = 0; i < m_tail; ++i)
			{
				std::cout << m_p[i] << " ";
			}
			std::cout << std::endl;
		}
	}

private:
	void fixIndex(unsigned int &index)
	{
		if (index == m_size - 1)
		{
			index = 0;
		}
		else
		{
			++index;
		}
	}

private:
	unsigned int m_size = 1024;
	T* m_p{};
	unsigned int m_head = 0;
	unsigned int m_tail = m_head;
	unsigned int m_count = 0;

};

#endif
