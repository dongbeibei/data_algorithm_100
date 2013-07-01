/*
1024!末尾有多少个0 ?
 * 
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

int zeroNum(int num);

int main(void)
{
	int num;

	cout<<"input the number:\t";
	cin>>num;
	cout<<"result:\t"<<zeroNum(num)<<endl;

	return 0;	
}

int zeroNum(int num)
{
	int result, i, temp;

	result = 0;
	for(i=1 ; i*5<=num ; i++)
	{
		temp = 1;
		int j = i;
		while(j%5 == 0)
		{
			temp++;
			j = j/5;
		}
		result += temp;
	}

	return result;
}
