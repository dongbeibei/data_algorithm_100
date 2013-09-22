/*
 * function: realize sqrt function
 *
 * author: feng
 * time:   2013/9/18
 */


#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

float mySqrt(int num, int bits)
{
	if(num<=0 || bits<=0)
		return -1;

	int i = 1;
	while(true)
	{
		int temp = i * i;
		if(temp == num)
			return i;
		else if(temp > num)
			break;
		else
			i = i<<1;
	}

	int j = i;
	i = i>>1;
	while(j-i > 1)
	{
		int mid = i + (j-i)/2;
		int temp = mid * mid;

		if(temp == num)
			return mid;
		else if(temp < num)
			i = mid;
		else
			j = mid;
	}

	assert(j == i+1);

	int front = i, rear = i+1;
	int k = 1;
	int flag = 1;
	while(bits--)
		flag = flag * 10;

//	cout<<"flag: "<<flag<<endl;

	while(k <= flag)
	{
		front = front<<1;
		rear = rear<<1;
		k = k<<1;

		int mid = front + 1;
		float temp = (float)mid*mid/k/k;

		if(temp < num)
			front = mid;
		else
			rear = mid;
	}
/*
	cout<<"front: "<<front<<endl;
	cout<<"rear: "<<rear<<endl;
	cout<<"k: "<<k<<endl<<endl;
	cout<<"first: "<<(float)front/k<<endl;
	cout<<"second: "<<(float)rear/k<<endl;
*/
	float first = (float)front/k;
	float second = (float)rear/k;

	i = first * flag * 10;
	j = second * flag * 10;

//	cout<<"i:"<<i<<"  "<<(float)i/flag<<endl;
//	cout<<"j:"<<j<<"  "<<(float)j/flag<<endl;

	if(i == j)
	{
		float result = (float)(i/10)/flag;

//		cout<<"result:\t"<<(float)(i/10)/flag<<endl;
		return result;
	}
	else
	{
		float mid = (float)(i+5)/flag/10;
		float result;

		if(mid * mid < num)
		{
			result = (float)(i/10+1)/flag;
//			cout<<"000"<<endl;
		}
		else
		{
			result = (float)(i/10)/flag;
//			cout<<"111"<<endl;
		}

		return result;
	}
}

int main(void)
{
	int n = 7, bits = 2;

	cout<<mySqrt(n, bits)<<endl;
	cout<<sqrt(n)<<endl;

	cout<<mySqrt(8, 2)<<endl;
	cout<<sqrt(8)<<endl;

	cout<<mySqrt(19, 3)<<endl;
	cout<<sqrt(19)<<endl;

	cout<<mySqrt(250, 2)<<endl;
	cout<<sqrt(250)<<endl;

	cout<<mySqrt(1024, 3)<<endl;
	cout<<sqrt(1024)<<endl;

	return 0;
}
