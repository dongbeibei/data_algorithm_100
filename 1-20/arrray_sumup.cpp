/*
 * ��Ŀ������һ���Ѿ�������������������һ�����֣�
 * �������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
 * Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣�
 * �������һ�Լ��ɡ�
 * ������������1��2��4��7��11��15 ������15������4+11=15��������4 ��11��
 *
 * author:	dongbeibei
 * building time:	2013/6/11
 */


#include <iostream>

using namespace std;

int main(void)
{
	int	test[] = {1, 2, 4, 7, 10, 15};
	int len, i, j, key, temp;
	bool result;

	key = 15;
	len = sizeof(test)/sizeof(int);
	result = false;

	for(i=0,j=len-1 ; i<j ; )
	{
		temp = test[i] + test[j];
		if(temp == 15)
		{
			result = true;
			break;
		}
		else if(temp < 15)
			i++;
		else
			j--;
	}

	if(result)
		cout<<"result:\n\ttest["<<i<<"]:\t"<<test[i]<<"\ttest["<<j<<"]:\t"<<test[j]<<endl;
	else
		cout<<"the fixed number doesn't exist!"<<endl;

	return 0;
}
