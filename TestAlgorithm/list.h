#ifndef __List__H
#define  __List__H
#pragma once

#include <initializer_list>

struct List
{
	int value;
	List* pnext;
};


void append2List(List** phead,List *pnode);
void append2List(List** phead, int value);
void printList(List* phead);
void initList(List **phead,const std::initializer_list<int> &ls);
void deleteList(List** head);


#endif
