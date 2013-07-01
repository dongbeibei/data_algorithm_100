/*
 * 在排序数组中，找出给定数字的出现次数
 * 比如[1, 2, 2, 2, 3]中2的出现次数为3.
 *
 * author:	dongbeibei
 * time:		2013/6/30
 */


#include <iostream>

using namespace std;

int NumTimes(int *array, int len, int num);

int main(void)
{
	int array[] = {2, 2, 2, 3, 4, 4, 5, 7, 7, 8, 9, 9};
	int len = sizeof(array)/sizeof(int);

	cout<<"result:\t"<<NumTimes(array, len, 2)<<endl;
	cout<<"result:\t"<<NumTimes(array, len, 4)<<endl;
	cout<<"result:\t"<<NumTimes(array, len, 9)<<endl;

	return 0;
}

int NumTimes(int *array, int len, int num)
{
	int start, end, mid;
	int times;
	int front, rear;

	start = 0;
	end = len - 1;
	times = 0;

	while(start <= end)
	{
		mid = start + (end - start)/2;
		if(array[mid] < num)
			start = mid + 1;
		else if(array[mid] > num)
			end = mid - 1;
		else
		{
			front = start + (mid - start)/2;
			while(1)
			{
				if(front - start < 2)
					front = start;
				else
					front = start + (front - start)/2;

				if(array[front] < num)
					start = front + 1;
				else
					if(!front || array[front-1] < num)
					{
						break;
					}
					else
						front = start + (front - start)/2;
			}
			

			rear = mid + (end - mid)/2;
			while(1)
			{
				if(end - rear < 2)
					rear = end;
				else
					rear = rear + (end - rear)/2;
				
				if(array[rear] > num)
					end = rear - 1;
				else
					if(rear==len-1 || array[rear+1] > num)
					{
						break;
					}
					else
						rear = rear + (end - rear)/2;
			}

			times = rear - front + 1;
			break;
		}
	}

	return times;
}
