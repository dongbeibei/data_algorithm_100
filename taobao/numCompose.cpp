/*
 * 求一个组合函数：如p([1,2,3]),输出：[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3].
 *
 * author:	dongbeibei
 * time:		2013/7/8
 */


#include <iostream>
#include <queue>

#define MAXLEN 1000

using namespace std;

void output(int *array, int len);

int main(void)
{
	int test[] = {1,2,3,4};
	int len = sizeof(test)/sizeof(test[0]);

	output(test,len);

	return 0;
}

void output(int *array, int len)
{
	int *result = new int[MAXLEN];
	int *front, *rear;
	int j;

	for(int i=0 ; i<MAXLEN ; i++)
		result[i] = 0;

	j = 0;
	result[j++] = array[0];
	result[j++] = 0;
	front = result;
	rear = &(result[j]);
	for(int i=1 ; i<len ; i++)
	{
		while(front<rear)
		{		
			if(*front)
			{
				//cout<<*front;
				result[j++] = *front;
				front++;
			}
			else
			{
				result[j++] = array[i];
				result[j++] = 0;
				front++;
				//cout<<endl;
			}
		}
		result[j++] = array[i];
		result[j++] = 0;
		rear = &(result[j]);
		front = result;
	}

	for(int i=0 ; i<=j ; i++)
		if(result[i])
			cout<<result[i];
		else if(result[i-1])
			cout<<endl;
		else
			break;
}
