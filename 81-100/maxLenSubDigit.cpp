/*
求最大连续递增数字串（如"ads3sl456789DF3456ld345AA"中的"456789"）
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>

using namespace std;

int maxSubDigit(const char *array, char *sub);

int main(void)
{
	const char *array = "ads3sl45678791234567DF3456ld345AA";
	char sub[20];

	cout<<maxSubDigit(array, sub)<<endl;
	cout<<sub<<endl;

	return 0;
}

int maxSubDigit(const char *array, char *sub)
{
	int maxlen, len;
	const char *start, *end;
	const char *front, *rear;
	bool flag;

	maxlen = len = 0;
	flag = false;
	while(*array != '\0')
	{
		if(*array>'9' || *array<'0')
		{
			flag = false;
			//array++;
		}
		else
		{
			if(!flag)
			{
				len = 1;
				start = array;
				flag = true;
			}
			else
			{
				if(*array >= *(array-1))
				{
					len++;
					end = array;
				}
				else
				{
					flag = false;
					array--;
				}
			}
		}

		if(!flag && len>maxlen)
		{
			maxlen = len;
			front = start;
			rear = end;
		}

		array++;
	}

	if(front)
	{
		int i = 0;
		while(front != rear+1)
		{
			sub[i] = *front;
			i++;
			front++;
		}
		sub[i] = '\0';
	}

	return maxlen;
}
