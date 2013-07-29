/*
 * XY -> X(T)Y(T) -> (X(T)Y(T))(T) -> YX
 *
 * author:	dongbeibei
 * time:		2013/7/29
 */

#include <iostream>
#include <cstring>

using namespace std;

char *invert(char *start, char *end);
char *left(char *s, int pos);

int main(void)
{
	char s[] = "abcdefghij";
	left(s, 3);
	cout<<"result:\t"<<s<<endl;

	return 0;
}

char *invert(char *start, char *end)
{
	char tmp, *ptmp = start;

	while(start!=NULL && end!=NULL && start<end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}

	return ptmp;
}

char *left(char *s, int pos)
{
	int len = strlen(s);

	invert(s, s + (pos-1));
	invert(s + pos, s + (len-1));
	invert(s, s + (len-1));

	return s;
}
