/*
 * 连续子数组最大和
 */


#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
	//int array[] = {2, 3, -6, 2, 4, -3, 5, 7, -2, 1};
	int array[] = {-2, -3, -4, -1, 3, 4, -2, 3};
	int len = sizeof(array)/sizeof(array[0]);
	int max, temp;
	int start, end;

	max = INT_MIN;
	temp = start = 0;
	for(int i=0 ; i<len ; ++i)
	{
		if(temp >= 0)
			temp += array[i];
		else
		{
			start = i;
			end = i;
			temp = array[i];
		}

		if(temp > max)
		{
			max = temp;
			end = i;
		}
	}

	cout<<"result:\t"<<max<<endl;
	cout<<"start:\t"<<start<<"\t"<<array[start]<<endl;
	cout<<"end:\t"<<end<<"\t"<<array[end]<<endl;

	return 0;
}
