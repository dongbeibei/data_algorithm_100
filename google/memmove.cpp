/*
��C����ʵ�ֺ���void *memmove(void *dest, const void *src, size_t n)��
memmove�����Ĺ����ǿ���src��ָ���ڴ�����ǰn���ֽڵ�dest��ָ�ĵ�ַ�ϡ�
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

void *memmove(void *dest, const void *src, size_t n);

int main(void)
{
	
	char arr[] = "abbcccddddefffh";
	char src[] = "mmmmmm";
	
	memmove(src,arr,3);

	cout<<src<<endl;

	return 0;
}

void *memmove(void *dest, const void *src, size_t n)
{
	if(!dest || !src)
		return NULL;

	if(dest < src)
	{
		for(int i=0 ; i<n ; i++)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else if(dest == src)
		return (void *)src;
	else if(dest < src + n)
		for(int i=n ; i>0 ; i--)
			((char *)dest)[i] = ((char *)src)[i];
	else
		for(int i=0 ; i<n ; i++)
			((char *)dest)[i] = ((char *)src)[i];

	return dest;
}
