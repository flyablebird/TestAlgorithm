#ifndef __HEAP__H
#define __HEAP__H
#pragma once

class Heap
{
public:
	using value_type = unsigned int;
	value_type operator [](value_type i);
	value_type parentIndex(value_type i);
	value_type leftIndex(value_type i);
	value_type rightIndex(value_type i);
	void maxHeapify(value_type i);
	Heap(value_type* data, value_type size);
	void maxBuild();
	void maxSort();

	value_type* begin();
	value_type* end();

private:
	value_type* m_data{};
	value_type m_size{};
};

#endif

