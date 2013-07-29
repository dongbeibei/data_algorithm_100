/*
n元的一维向量循环左移i个位置
 *
 * author:	dongbeibei
 * time:		2013/7/17
 */


#include <iostream>

using namespace std;

void print(const char *tmp, char *array, int len);
void run(char *array, int len, int i);
//开辟i个空间，用以缓存
void method1(char *array, int len, int i);
//i次调用可以移动一位的函数
void method2(char *array, int len, int i);
void helper(char *array, int len);
//0,x,2x,3x,......
void method3(char *array, int len, int i);
//块倒置
void method4(char *array, int len, int i);
void helper(char *array, int start, int end);

int main(void)
{
	char array[] = "abcdefg";
	int len = sizeof(array)/sizeof(char);
	int i = 3;

	run(array, len-1, i);

	return 0;
}

void print(const char *tmp, char *array, int len)
{
	cout<<tmp<<" array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}

void run(char *array, int len, int i)
{
	print("origin", array, len);
	method4(array, len, i);
	print("result", array, len);
}

void method1(char *array, int len, int i)
{
	char *temp = new char[i];
	for(int j=0 ; j<i ; j++)
		temp[j] = array[j];
	for(int j=0, k=i ; k<len ; )
		array[j++] = array[k++];
	for(int j=len-i, k=0 ; k<i ;)
		array[j++] = temp[k++];
}

void method2(char *array, int len, int i)
{
	for(int j=0 ; j<i ; j++)
		helper(array, len);
}

void helper(char *array, int len)
{
	char temp;

	temp = array[0];
	for(int i=0 ; i<len-1 ; i++)
		array[i] = array[i+1];
	array[len-1] = temp;
}

void method3(char *array, int len, int i)
{
	char temp;

	temp = array[0];
	for(int j=0 ; j<len-1 ; j++)
	{
		array[j*i%len] = array[(j+1)*i%len];
	}
	array[(len-1)*i%len] = temp;
}

void method4(char *array, int len, int i)
{
	helper(array, 0, i-1);
	helper(array, i, len-1);
	helper(array, 0, len-1);
}

void helper(char *array, int start, int end)
{
	char temp;

	while(start < end)
	{
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;

		start++;
		end--;
	}
}
