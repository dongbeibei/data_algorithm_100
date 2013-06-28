/*
实现strstr 功能，即在父串中寻找子串首次出现的位置
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>

using namespace std;

const char *my_strstr(const char *str, const char *sub);

int main(void)
{
	const char *str = "absxbsc";
	const char *sub = "bs";

	const char *p = my_strstr(str, sub);
	
	cout<<"str:\t"<<str<<endl;
	cout<<"sub:\t"<<sub<<endl;
	cout<<"p:\t"<<p<<endl;

	return 0;
}

const char *my_strstr(const char *str, const char *sub)
{
	const char 	*p, *q;
	int		i;
	bool	flag;

	flag = false;
	for(p=str ; *p!='\0' ; p++)
	{
		for(i=0,q=sub ; *q!='\0' ; q++, i++)
		{
			if(*(p+i) == *q)
			{
				if(*(q+1)=='\0')
				{
					flag = true;
					break;
				}
				else
					continue;
			}
			else
				break;
		}

		if(flag)
			break;
	}

	return p;
}
