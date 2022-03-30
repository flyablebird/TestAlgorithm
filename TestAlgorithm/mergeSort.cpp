#include "mergeSort.h"

#include <algorithm>
#include <cmath>

namespace
{
	int* temp{};
}
void merge(int*arr,const int start,const int mid,const int end)
{
	//int* front = new int[mid - start + 1 + 1];
	//int* back = new int[end - mid + 1];

	int* front = temp;
	int* back = temp + mid - start + 2;

	for (int i = start; i <= mid; ++i)
	{
		front[i - start] = arr[i];
	}
	for (int i=mid +1;i<=end;++i)
	{
		back[i - mid -1] = arr[i];
	}
	int max = arr[mid] > arr[end] ? arr[mid] : arr[end];
	front[mid - start + 1] = max;
	back[end - mid] = max;

	int j = 0;
	int k = 0;
	for (int i = start; i <= end; ++i)
	{
		if (front[j] < back[k])
		{
			arr[i] = front[j];
			++j;
		}
		else
		{
			arr[i] = back[k];
			++k;
		}
	}

	//delete[]front;
	//delete[]back;
}

void __mergeSort(int* arr, const int start, const int end)
{
	if (start < end)
	{
		int pos = std::floor((start + end)/2);
		__mergeSort(arr,start,pos);
		__mergeSort(arr,pos + 1,end);
		merge(arr,start,pos,end);
	}
}

void mergeSort(int* arr, const int start, const int end)
{
	temp = new int[end - start +1 + 2];
	__mergeSort(arr,start,end);
	delete[] temp;
}
