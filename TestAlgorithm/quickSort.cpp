#include "quickSort.h"

#include <algorithm>
#include <iostream>


//����end���������ݳ���������֮ǰ
int partition(int* arr, int start, int end)
{
	int j = start;
	for (int i = start; i < end ; ++i)
	{
		if (arr[i] < arr[end])
		{
			std::swap(arr[i],arr[j]);
			++j;
		}
	}
	std::swap(arr[j],arr[end]);
	return j;
}

//����start���������ݳ�������������֮��
int backOrderedPartition(int* arr, int start, int end)
{
	int j = end;
	for (int i = end; i > start; --i)
	{
		if (arr[i] < arr[start])
		{
			std::swap(arr[i], arr[j]);
			--j;
		}
	}
	std::swap(arr[j],arr[start]);
	return j;
}

void quickSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int pos = partition(arr,start,end);
		quickSort(arr,start,pos-1);
		quickSort(arr,pos+1,end);
	}
}
