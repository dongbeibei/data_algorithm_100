/*
 * 
 */


#include <iostream>
#include <cstring>

using namespace std;

void Swap(char *a, char *b);
void ReverseString(char *pStart, char *pEnd);
char *LeftRotateString(char *pStr, unsigned int n);

int main(void)
{
	char a[15] = "hello July";
	char *ps = a;

	LeftRotateString(ps, 7);
	for( ; *ps!='\0' ; ++ps)
		cout<<*ps;
	cout<<endl;

	ps = NULL;

	return 0;
}

void Swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void ReverseString(char *pStart, char *pEnd)
{
	if(*pStart!='\0' && *pEnd!='\0')
	{
		while(pStart <= pEnd)
		{
			Swap(pStart, pEnd);

			++pStart;
			--pEnd;
		}
	}
}

char *LeftRotateString(char *pStr, unsigned int n)
{
	if(pStr != NULL)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if(nLength>0 && n!=0 && n<nLength)
		{
			char *pFirstStart = pStr;
			char *pFirstEnd = pStr + n - 1;
			char *pSecondStart = pStr + n;
			char *pSecondEnd = pStr + nLength - 1;

			ReverseString(pFirstStart, pFirstEnd);
			ReverseString(pSecondStart, pSecondEnd);
			ReverseString(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}
