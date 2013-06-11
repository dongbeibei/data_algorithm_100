/*
 * 题目：输入一个已经按升序排序过的数组和一个数字，
 * 在数组中查找两个数，使得它们的和正好是输入的那个数字。
 * 要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，
 * 输出任意一对即可。
 * 例如输入数组1、2、4、7、11、15 和数字15。由于4+11=15，因此输出4 和11。
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
