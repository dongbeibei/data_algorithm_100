/*
��Ŀ������һ������n�����1 ��n ��n ��������
ʮ���Ʊ�ʾ��1 ���ֵĴ�����

��������12����1 ��12 ��Щ�����а���1 ��������1��10��11 ��12��
1 һ��������5 �Ρ�
 *
 * author:	dongbeibei
 * time:		2013/6/13
 */


#include <iostream>

using namespace std;  
	
int num_of_1(int n)  
{	
/*it should cover all powers of 10 within int range*/	
	int pow1 = 1;	
	int pow2 = 10*pow1;  
	int  count = 0;  
	while(n >= pow1)
	{   
		int pow2 = 10*pow1;  
		switch((n % pow2) / pow1)
		{  
			case 0:  
				count += (n / pow2) * pow1;  
				break;  
			case 1:  
				count += (n / pow2) * pow1;  
				count += n % pow1 + 1;  
				break;  
			default:  
				count += (n / pow2 + 1) * pow1;  
		}
		pow1 *= 10;
	}

	return count;
}	

int main()  
{	
	cout<<num_of_1(12)<<endl;

	return 0;
}
