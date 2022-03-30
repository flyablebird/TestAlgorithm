#include "reverse.h"

#include <cstring>

void  reverseStr(char* src)
{
	auto len = std::strlen(src);
	char* pForward = const_cast<char *>(src);
	char* pBack = const_cast<char *>(src) + len - 1;
	while (pForward < pBack)
	{
		char temp = *pBack;
		char t = *pForward;
		*pBack = *pForward;
		*pForward = temp;
		++pForward;
		--pBack;
	}
}
