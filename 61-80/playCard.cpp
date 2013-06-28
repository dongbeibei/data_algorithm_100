/*
扑克牌的顺子
从扑克牌中随机抽5 张牌，判断是不是一个顺子，即这5 张牌是不是
连续的。2-10 为数字本身，A 为1，J 为11，Q 为12，K 为13，
而大小王可以看成任意数字。
 *
 * author:	dongbeibei
 * time:		2013/6/22
 */


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sort(int *array, int len);
bool iscontinue(int *array, int len);

int main(void)
{
	int test[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,
				  1,2,3,4,5,6,7,8,9,10,11,12,13,
				  1,2,3,4,5,6,7,8,9,10,11,12,13,
				  1,2,3,4,5,6,7,8,9,10,11,12,13,
				  0,0};
	int choice[5], result[5];
	int len;

	srand((unsigned)time(NULL));
	for(int i=0 ; i<5 ; i++)
	{
		choice[i] = rand()%52;
		result[i] = test[choice[i]];
	}
/*
	cout<<"choice:\t";
	for(int i=0 ; i<5 ; i++)
		cout<<choice[i]<<"  ";
	cout<<endl;
	cout<<"result:\t";
	for(int i=0 ; i<5 ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;
*/
	len = 5;
	sort(result, len);
/*
	cout<<"result:\t";
	for(int i=0 ; i<5 ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;

	result[0] = 0;
	result[1] = 0;
	result[2] = 1;
	result[3] = 4;
	result[4] = 6;

	cout<<"result:\t";
	for(int i=0 ; i<5 ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;
*/
	if(iscontinue(result, len))
		cout<<"The result is continuing."<<endl;
	else
		cout<<"The result is not continuing."<<endl;

	return 0;
}

void sort(int *array, int len)
{
	int i, j, temp;

	for(i=0 ; i<len-1 ; i++)
	{
		for(j=0 ; j<len-i-1 ; j++)
		{
			if(array[j+1] < array[j])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

bool iscontinue(int *array, int len)
{
	int king, i;
	bool flag = true;

	king = 0;
	i = 0;
	while(!array[i])
	{
		king++;
		i++;
	}

	for( ; i<len ; )
	{
		if(array[i+1] == array[i] + 1)
		{
			i++;
			if(i == len-1)
				break;
			continue;
		}
		else
		{
			if(king)
			{
				king--;
				array[i]++;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}

	return flag;
}
