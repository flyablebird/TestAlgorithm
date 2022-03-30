#include "heap.h"

#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>



Heap::value_type Heap::operator[](value_type i)
{
	assert(1<=i && i<=m_size);
	return m_data[i - 1];
}

Heap::value_type Heap::parentIndex(value_type i)
{
	return i / 2;
}

Heap::value_type Heap::leftIndex(value_type i)
{
	return 2 * i;
}

Heap::value_type Heap::rightIndex(value_type i)
{
	return 2 * i + 1;
}

void print(Heap* h)
{
	for (auto x : *h)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
void Heap::maxHeapify(value_type i)
{
	auto left = leftIndex(i);
	auto right = rightIndex(i);
	value_type largest = i;
	if (left <= m_size && m_data[left-1] > m_data[i-1])
	{
		largest = left;
	}
	if (right <= m_size && m_data[right-1] > m_data[largest-1])
	{
		largest = right;
	}
	if (largest != i)
	{
		std::swap(m_data[largest-1],m_data[i-1]);
		//print(this);
		maxHeapify(largest);
	}
}

Heap::Heap(value_type* data, value_type size)
	: m_data(data),m_size(size)
{
}

void Heap::maxBuild()
{
	for (int i = m_size / 2; i > 0; --i)
	{
		maxHeapify(i);
	}
}

void Heap::maxSort()
{
	maxBuild();
	for (auto i = m_size; i > 1; --i)
	{
		std::swap(m_data[0],m_data[i-1]);
		--m_size;
		maxHeapify(1);
	}
}

Heap::value_type* Heap::begin()
{
	return m_data;
}

Heap::value_type* Heap::end()
{
	return m_data + m_size;
}


