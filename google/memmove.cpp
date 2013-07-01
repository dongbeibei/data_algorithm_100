/*
用C语言实现函数void *memmove(void *dest, const void *src, size_t n)。
memmove函数的功能是拷贝src所指的内存内容前n个字节到dest所指的地址上。
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
