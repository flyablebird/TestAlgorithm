#ifndef __LISTTEST__H
#define __LISTTEST__H 
#pragma once

template <typename K,typename V = void>
class ListNode
{
public:
	ListNode * m_next{};
	K key;
	V value;
};

template <typename K,typename V>
class List
{

};

#endif
