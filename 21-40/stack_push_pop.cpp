/*
��Ŀ�����������������С�����һ�����б�ʾջ��push ˳��
�ж���һ��������û�п����Ƕ�Ӧ��pop ˳��
Ϊ�˼���������Ǽ���push ���е����������������ǲ���ȵġ�
���������push ������1��2��3��4��5��
��ô4��5��3��2��1 ���п�����һ��pop ϵ�С�
��Ϊ���������µ�push ��pop ���У�
push 1��push 2��push 3��push 4��pop��push 5��pop��pop��pop��pop��
�����õ���pop ���о���4��5��3��2��1��
������4��3��5��1��2 �Ͳ�������push ����1��2��3��4��5 ��pop ���С�
 *
 * author:	dongbeibei
 * time:		2013/6/13
 */


#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int input[] = {1,2,3,4,5};
	int output[] = {1,2,3,4,5};
	int len_in, len_out, i, j;
	stack<int>	test;
	bool flag;

	flag = true;
	len_in = sizeof(input)/sizeof(int);
	len_out = sizeof(output)/sizeof(int);

	for(i=0,j=0 ; j<len_out ; j++)
	{
		while(test.empty())
			test.push(input[i++]);

		while(test.top() != output[j])
			if(i < len_in)
				test.push(input[i++]);
			else
			{
				flag = false;
				break;
			}

		test.pop();
	}

	if(flag)
		cout<<"the output[] can be the right order"<<endl;
	else
		cout<<"the bad order"<<endl;

	return 0;
}
