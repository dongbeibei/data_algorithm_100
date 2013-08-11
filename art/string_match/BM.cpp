/*
 * BM
 * 
 * author:	feng
 * time:		2013/8/11
 */


#include <iostream>
#include <cstring>

using namespace std;

void BuildBadCharacterShift(const char *pattern, int plen, int *shift);
void BuildGoodSuffixShift(const char *pattern, int plen, int *shift);
int BMSearch(const char *src, int slen, const char *ptrn, int plen, const int *bad_shift, int *good_shift);

int main(void)
{
	const char *source = "ababababcedf";
	const char *pattern = "ababc";
	int slen = strlen(source);
	int plen = strlen(pattern);
	int *good_shift = new int[plen];
	int *bad_shift = new int[256];

	BuildBadCharacterShift(pattern, plen, bad_shift);
	BuildGoodSuffixShift(pattern, plen, good_shift);

	cout<<"result:\t"<<BMSearch(source, slen, pattern, plen, bad_shift, good_shift)<<endl;

	delete []good_shift;
	delete []bad_shift;

	return 0;
}

void BuildBadCharacterShift(const char *pattern, int plen, int *shift)
{
	for(int i=0 ; i<256 ; ++i)
		*(shift+i) = plen;

	while(plen > 0)
	{
		*(shift+(unsigned char)*pattern++) = --plen;
	}
}

void BuildGoodSuffixShift(const char *pattern, int plen, int *shift)
{
	shift[plen-1] = 1;
	char end_val = pattern[plen-1];
	char const *p_prev, *p_next, *p_temp;
	char const *p_now = pattern + plen - 2;
	bool isgoodsuffixfind = false;

	for(int i=plen-2 ; i>=0 ; --i, --p_now)
	{
		p_temp = pattern + plen - 1;
		isgoodsuffixfind = false;
		while(true)
		{
			while(p_temp>=pattern && *p_temp-- != end_val);

			p_prev = p_temp;
			p_next = pattern + plen - 2;

			if(p_prev<pattern && *(p_temp+1)!=end_val)
				break;

			bool match_flag = true;
			while(p_prev>=pattern && p_next>p_now)
			{
				if(*p_prev-- != *p_next--)
				{
					match_flag = false;
					break;
				}
			}

			if(!match_flag)
				continue;
			else
			{
				if(p_prev<pattern || *p_prev != *p_next)
				{
					isgoodsuffixfind = true;
					break;
				}
			}
		}

		shift[i] = plen - i + p_next - p_prev;
		if(isgoodsuffixfind)
			shift[i]--;
	}
}

int BMSearch(const char *src, int slen, const char *ptrn, int plen, const int *bad_shift, int *good_shift)
{
	int s_idx = plen;

	if(plen == 0)
		return 1;

	while(s_idx <= slen)
	{
		int p_idx=plen, bad_stride, good_stride;

		while(src[--s_idx] == ptrn[--p_idx])
		{
			if(p_idx == 0)
				return s_idx;
		}

		bad_stride = bad_shift[(unsigned char)src[s_idx]];
		good_stride = good_shift[p_idx];
		s_idx += ((good_stride > bad_stride) ? good_stride : bad_stride) + 1;
	}

	return -1;
}
