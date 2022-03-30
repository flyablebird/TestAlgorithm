#ifndef __STACKANDQUEUE__H
#define __STACKANDQUEUE__H
#pragma once 

#include <initializer_list>

#include "Stack.hpp"
#include "Queue.hpp"

// 根据栈的LIFO,使用两个栈（两次翻转）来维持顺序。
template<typename T>
class QueueOnStack
{
public:
	QueueOnStack(const std::initializer_list<T> &datas)
	{
		for (auto &x : datas)
		{
			enqueue(x);
		}
	}
	QueueOnStack() = default;
	void enqueue(const T &d)
	{
		maintainEnter();
		m_entered.push(d);
	}
	T dequeue()
	{
		T ret;
		maintainDelete();
		ret = m_deleted.pop();
		return ret;
	}
	void print()
	{
		maintainDelete();
		for (auto & x : m_deleted)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
private:
	// maintain m_entered's order.
	void maintainEnter()
	{
		while (!m_deleted.empty())
		{
			m_entered.push(m_deleted.pop());
		}
	}
	// maintain m_deleted's order.
	void maintainDelete()
	{
		while (!m_entered.empty())
		{
			m_deleted.push(m_entered.pop());
		}
	}
private:
	// the datas in this is the same order as they append.
	Stack<T> m_entered;
	// the datas in this is the reverse order as they append.
	Stack<T> m_deleted;
};

template <typename T>
class StackOnQueue
{
public:
	StackOnQueue(const std::initializer_list<T> &datas)
	{
		for (auto & x : datas)
		{
			m_container1.enqueue(x);
		}
	}
	StackOnQueue() = default;
	void push(const T & d)
	{
		if (m_validQueueNumer == Queue1)
		{
			m_container1.enqueue(d);
		}
		else
		{
			m_container2.enqueue(d);
		}
		//std::cout << "m_container1: " << std::endl;
		//m_container1.print();
		//std::cout << "m_container2: " << std::endl;
		//m_container2.print();

	}
	T pop()
	{
		T ret{};
		if (m_validQueueNumer == Queue1)
		{
			ret = getTop(m_container2,m_container1);
			m_validQueueNumer = Queue2;
		}
		else
		{
			ret = getTop(m_container1,m_container2);
			m_validQueueNumer = Queue1;
		}
		//std::cout << "m_container1: " << std::endl;
		//m_container1.print();
		//std::cout << "m_container2: " << std::endl;
		//m_container2.print();
		return ret;
	}
private:
	T getTop(Queue<T> & dst, Queue<T> &src)
	{
		//while (dst.empty() && src.size() > 1)
		while ( src.size() > 1)
		{
			dst.enqueue(src.dequeue());
		}
		return src.dequeue();
	}
private:
	enum ValidQueueNumber
	{
		Queue1,Queue2
	};
private:
	Queue<T> m_container1;
	Queue<T> m_container2;
	// 0:init;1: m_container1;2:m_container2.
	ValidQueueNumber m_validQueueNumer = Queue1;
};

#endif
