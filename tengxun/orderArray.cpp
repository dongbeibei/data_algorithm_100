/*
һ���������У������е�ÿ��ֵ���ܹ���2����3����5��������
1��������еĵ�һ��Ԫ�ء����1500��ֵ�Ƕ��٣�
 *
 * author:	dongbeibei
 * time:		2013/7/2
 */


#include <iostream>

using namespace std;

int minValue(int a, int b, int c);
int orderArray(int num);

int main(void)
{
	int num;

	cout<<"input the number:\t";
	cin>>num;

	cout<<"result:\t"<<orderArray(num)<<endl;

	return 0;
}

int minValue(int a, int b, int c)
{
	if(a>b)
		a = b;
	if(a>c)
		a = c;

	return a;
}

int orderArray(int num)
{
	int *array;
	int i, j, k, m, max, temp;

	i = 0;
	array = new int[num];
	array[i++] = 1;
	array[i++] = 2;
	array[i++] = 3;
	array[i++] = 4;
	array[i++] = 5;
	max = 5;
	for(j=3, k=m=2 ; i<num ; )
	{
		temp = minValue(j*2, k*3, m*5);
		if(temp == j*2)
			j++;
		else if(temp == k*3)
			k++;
		else
			m++;
		
		if(temp <= max)
			continue;
		else
		{
			array[i++] = temp;
			max = temp;
		}
	}

	return array[num-1];
}
