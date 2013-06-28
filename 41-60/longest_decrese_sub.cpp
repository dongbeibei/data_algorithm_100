/*

 *
 * author:	dongbeibei
 * time:		2013/6/27
 */


#include <iostream>

using namespace std;

int longest_decrese_sub(int *array, int len);

int main(void)
{
	int data[] = {9,8,6,5,7,5};
	int len = sizeof(data)/sizeof(int);

	longest_decrese_sub(data, len);

	return 0;
}

int longest_decrese_sub(int *array, int len)
{
	int *size = new int[len];
	int *p = new int[len];

	size[len-1] = 1;
	for(int i=len-1 ; i>=0 ; i--)
	{
		int max = 0;
		int index = 0;

		for(int j=i ; j<len ;j++)
		{
			if(array[i]>array[j] && max<size[j])
			{
				max = size[j];
				index = j;
			}
		}

		if(max == 0)
		{
			size[i] = 1;
			p[i] = -1;
		}
		else
		{
			size[i] = max + 1;
			p[i] = index;
		}
	}

	int max = 0;
	int max_index = 0;

	for(int i=0 ; i<len ; i++)
	{
		if(size[i] > max)
		{
			max = size[i];
			max_index = i;
		}
	}

	cout<<"result length:\t"<<size[max_index]<<"\nresult:\t";

	for(int i=max_index ; i!=-1 ; i=p[i])
		cout<<array[i]<<"  ";
	cout<<endl;

	delete []p;
	delete []size;
}
