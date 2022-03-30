#ifndef __LISTTEST__H
#define __LISTTEST__H
#pragma once

#include <iostream>

#include "SingleList.hpp"

namespace Lists
{
	template <typename T>
	class Stack
	{
	public:
		using size_type = unsigned int;
		using list_type = SingleList<T>;
		using node_type = typename list_type::node_type;
	public:
		~Stack()
		{
			node_type *pHead = m_list.head();
			node_type *p = pHead;
			while (p != nullptr );
			{
				p = p->next;
			}
		}
		void push(const T &d)
		{
			node_type *pNode = new node_type(d);
			m_list.insert(d);
			++m_top;
		}
		T pop()
		{
			T ret;
			auto p = m_list.remove();
			if (p)
			{
				ret = *p;
				--m_top;
			}
			return ret;
		}

		void print()
		{
			m_list.print();
		}

	private:
		void release()
		{
			node_type *pos = m_list.head();
			node_type *prev = nullptr;
			while (pos != nullptr)
			{
				prev = pos;
				pos = pos->m_next;
			}
			delete pos;
		}

	private:
		list_type m_list;
		size_type m_top;
	};
}

#endif
