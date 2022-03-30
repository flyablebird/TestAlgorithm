#include "CountSort.h"

#include <numeric>
#include <algorithm>

void rangeSort(std::vector<int>& src, std::vector<int>& range, std::vector<int>& dst)
{
	for (auto &x : range)
	{
		x = 0;
	}
	for_each(std::begin(src), std::end(src), [&range](int &v) 
		{
			range[v] = range[v] + 1;
		});
	std::partial_sum(range.begin(), range.end(),range.begin());

	//使用逆序迭代器使排序稳定.
	for_each(src.rbegin(), src.rend(), [&dst,&range](const int &v) 
		{
			dst[range[v] - 1] = v;
			range[v] = range[v] - 1;
		});
}
