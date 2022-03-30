#include "List.h"

#include <iostream>

void append2List(List** phead, List* pnode)
{
	List* head = *phead;
	if (*phead == nullptr)
	{
		*phead = pnode;
	}
	else
	{
		//List*& pos = (*phead)->pnext;
		//while(pos != nullptr)
		//{
		//	pos = pos->pnext;
		//}
		//pos = pnode;



		List* pos = *phead;
		while (pos->pnext != nullptr)
		{
			pos = pos->pnext;
		}
		pos->pnext = pnode;
	}
}

void append2List(List** phead, int value)
{
	List* pnew = new List();
	pnew->pnext = nullptr;
	pnew->value = value;
	append2List(phead, pnew);
}

void printList(List* phead)
{
	List* pos = phead;
	while (pos != nullptr)
	{
		std::cout << pos->value << " ";
		pos = pos->pnext;
	}
	std::cout << std::endl;
}

void deleteList(List** head)
{
	static int level = 0;
	List* phead = *head;
	if (*head != nullptr)  
	{
		if (head[0]->pnext != nullptr)
		{
			while (head[0]->pnext->pnext != nullptr)
			{
				++level;
				deleteList(&(head[0]->pnext));
				--level;
			}
			std::cout << head[0]->pnext << "\t" <<head[0]->pnext->value << std::endl;
			delete head[0]->pnext;
			head[0]->pnext = nullptr;
		}
		if (level == 0)
		{
			std::cout << head[0] << "\t" << head[0]->value << std::endl; 
			delete head[0];
			head[0]= nullptr;

		}
	}
}

void initList(List **phead,const std::initializer_list<int>& ls)
{
	for (auto v : ls)
	{
		append2List(phead,v);
	}
}
