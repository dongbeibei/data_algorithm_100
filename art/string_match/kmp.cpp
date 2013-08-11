/*
 * KMP
 * 
 * author:	feng
 * time:		2013/8/11
 */



#include <iostream>
#include <cstring>

using namespace std;

void get_nextval(char const *ptrn, int plen, int *nextval);
int kmp_search(char const *src, int slen, char const *patn, int plen, int const *nextval, int pos);

int main(void)
{
	const char *source = "ababcababcedf";
	const char *pattern = "ababc";
	int slen = strlen(source);
	int plen = strlen(pattern);
	int *nextval = new int[plen];

	get_nextval(pattern, plen, nextval);

	cout<<"result:\t"<<kmp_search(source, slen, pattern, plen, nextval, 1)<<endl;

	return 0;
}

void get_nextval(char const *ptrn, int plen, int *nextval)
{
	int i = 0, j = -1;
	
	nextval[i] = -1;
	while(i < plen-1)
	{
		if(j==-1 || ptrn[i]==ptrn[j])
		{
			++i;
			++j;
			if(ptrn[i] != ptrn[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int kmp_search(char const *src, int slen, char const *patn, int plen, int const *nextval, int pos)
{
	int i = pos, j = 0;

	while(i<slen && j<plen)
	{
		if(j==-1 || src[i]==patn[j])
		{
			++i;
			++j;
			
		}
		else
			j = nextval[j];
	}

	if(j >= plen)
		return i-plen;
	else
		return -1;
}
