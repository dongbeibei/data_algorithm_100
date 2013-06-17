/*
题目：输入一个整数n，求从1 到n 这n 个整数的
十进制表示中1 出现的次数。

例如输入12，从1 到12 这些整数中包含1 的数字有1，10，11 和12，
1 一共出现了5 次。
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
