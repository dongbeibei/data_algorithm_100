/*
��������˳��ʹ����λ��ż��ǰ�档
��Ŀ������һ���������飬�������������ֵ�˳��ʹ����������
λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
Ҫ��ʱ�临�Ӷ�ΪO(n)��
 *
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>

using namespace std;

void swap(int &i, int &j);
void arrange(int *array, int len);

int main(void)
{
	int array[] = {1,2,3,4,5,6,7};
	int len = sizeof(array)/sizeof(int);

	arrange(array, len);

	cout<<"result:\n\t";
	for(int i=0 ; i<len ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;

	return 0;
}

void arrange(int *array, int len)
{
	if(!array || len<=0)
		return;

	int i, j;

	i = 0;
	j = len - 1;

	while(i != j)
	{
		//if(array[i] % 2 == 1)
		if((array[i]&1)==1)
		{
			i++;
			continue;
		}
		if((array[j]&1)==0)
		//if(array[j] % 2 == 0)
		{
			j--;
			continue;
		}
		swap(array[i], array[j]);
	}
}

void swap(int &i, int &j)
{
	int temp;

	temp = i;
	i = j;
	j = temp;
}
