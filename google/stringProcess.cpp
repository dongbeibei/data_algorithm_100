/*
有一个有大小写组成的字符串，现在需要对他进行修改，将其中的所有
小写字母排在大写字母的前面（大写或小写之间不要求保持原来次序），
如果有可能尽量选择时间和空间效率高的算法
c语言函数原型void proc（char *str）。
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

void myswap(char *a, char *b);
void proc(char *str);

int main(void)
{
	char str[] = "abaDFGdfDSsB";

	cout<<str<<endl;
	proc(str);
	cout<<str<<endl;

	return 0;
}

void proc(char *str)
{
	char *temp;
	int i, j, len;

	temp = str;
	len = 0;
	while(*temp != '\0')
	{
		len++;
		temp++;
	}

	for(i=0, j=len-1 ; i<j ; )
	{
		while(str[i]>='a' && str[i]<='z')
			i++;
		while(str[j]>='A' && str[j]<='Z')
			j--;
		if(i<j)
			myswap(&str[i], &str[j]);
	}
}

void myswap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
