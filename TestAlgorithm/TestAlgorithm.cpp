// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>
#include <typeinfo>
#include <initializer_list>
#include <memory>
#include <functional>
#include <string>


#include "reverse.h"
#include "CountSort.h"
#include "list.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "heap.h"
#include "stack.hpp"
#include "queue.hpp"
#include "stackAndQueue.hpp"
#include "CircularDList.hpp"
#include "SingleList.hpp"



//还有问题
void splitStr(char * str)
{
    auto len = std::strlen(str);
    char* pBegin = str;
    char* pWordBegin = str;
    char* pWordEnd = str;
    while (*pBegin != '\0')
    {
        if (*pBegin != ' ')
        {
            ++pWordEnd;
        }
        else
        {
			std::string s(pWordBegin, pWordEnd - pWordBegin + 1);
			std::cout << s << std::endl;
            pWordBegin = pBegin;
        }
        ++pBegin;
    }
	std::string s(pWordBegin, pWordEnd - pWordBegin + 1);
	std::cout << s << std::endl;
    
}

void bubbleSort(std::vector<int> &arr)
{
    
    for(auto iterBegin = arr.begin(),iterEnd = arr.end() - 1,iterPos = iterEnd;iterBegin < iterEnd;++iterBegin)
    {
        for (;iterBegin < iterPos;--iterPos)
        {
            if (*iterPos < *(iterPos - 1))
            {
                std::swap(*iterPos,*(iterPos - 1));
            }
        }
        iterPos = iterEnd;
    }
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<int>& arr)
{
    for (auto pos = arr.begin(), iterEnd = arr.end(); pos < iterEnd; ++pos)
    {
        for (auto iterCompared = pos + 1;iterCompared < iterEnd;++iterCompared)
        {
            if (*pos > *iterCompared)
            {
                std::swap(*pos,*iterCompared);
            }
        }
    }

    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void recursiveLevel(int n)
{
    static int level = 0;
    if (n > 0)
    {
		++level;
		std::cout << "enter level\t"<<level <<"\t" <<n<< "\n";
		recursiveLevel(--n);
		--level;
		std::cout << "leave level\t" << level << "\n";
        if (level == 0)
        {
            std::cout << "\tlevel" << std::endl;
        }
    }
}


struct A
{
    ~A()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
struct APtr
{
public:
    APtr(A *p)
    {
        m_count = new int(1);
        m_p = p;
    }
    APtr(APtr& d)
    {
        m_p = d.m_p;
        ++(*d.m_count);
        m_count = d.m_count;
    }
    APtr& operator = (APtr& d)
    {
        m_p = d.m_p;
        ++(*d.m_count);
        m_count = d.m_count;
        return *this;
    }
    ~APtr()
    {
        --(*m_count);
        if (*m_count == 0)
        {
            delete m_p;
        }
    }
private:
    int *m_count{};
    A* m_p{};
};

struct C
{
public:
    C(int* d,int size) :m_data(d),m_size(size)
    {}
    int* begin()
    {
        return m_data;
    }
    int* end()
    {
        return m_data + m_size;
    }
private:
    int* m_data{};
    int m_size{};
};

template <typename T>
void printElement(const T& t)
{
    for (auto x : t)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    //std::cout << typeid(t).name() << std::endl;
}


template <typename T,unsigned int size>
void TA(const T(& t)[size] )
{
    printElement(t);
}

//template<typename C,typename T >
//class vectorInserter
//{
//public:
//    using value_type = T;
//    using container_type = C;
//    vectorInserter(C<T> &d)
//        : m_container(d)
//    {}
//private:
//    C<T> &m_container;
//};



template<typename T,template<typename> typename C >
class vectorInserter
{
public:
    using value_type = T;
    using container_type = C;
    vectorInserter(C<T> &d)
        : m_container(d)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
private:
    C<T> &m_container;
};

template<typename C>
class vectorInserter1
{
public:
    using value_type = typename C::value_type;
    using container_type = C;
    vectorInserter1(C &d)
        : m_container(d)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
private:
    C &m_container;
};







int main()
{
	{

	}
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
