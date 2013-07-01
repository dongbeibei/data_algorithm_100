/*
判断某个自然数是否是一个数的平方
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

bool sqrtValue(int num);

int main(void)
{
	int num;

	cout<<"input the number:\t";
	cin>>num;
	cout<<"\n"<<num<<" result:\t"<<sqrtValue(num)<<endl;

	return 0;
}

bool sqrtValue(int num)
{
	int i, j, mid;
	bool flag;

	flag = false;
	for(i=1 ; i*i<num ; i *= 2);
	j = i;
	i = i/2;
	//cout<<"i:"<<i<<endl;
	//cout<<"j:"<<j<<endl;
	while(i < j)
	{
		mid = i + (j - i)/2;
		if(mid == i)
		{
			if(j*j == num)
				flag = true;
			break;
		}
		
		if(mid*mid < num)
			i = mid;
		else if(mid*mid > num)
			j = mid;
		else
		{
			flag = true;
			break;
		}
	}

	return flag;
}
