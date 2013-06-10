/*
 *  输入一个整数数组，判断该数组是不是
 *  某二元查找树的后序遍历的结果。如果是返回true，否则返回false。
 *
 * author:	dongbeibei
 * building time:	2013/6/10
 */


#include <iostream>

using namespace std;

void IsPostVisit(int a[], int left, int right, bool &flag);

int main(void)
{
	int a[] = {5, 7, 6, 9, 11, 10, 8};
	int b[] = {7, 5, 6, 9, 11, 10, 8};

	int left=0, right=6;
	bool flag;

	flag = true;
	IsPostVisit(a, left, right, flag);
	cout<<"result_1:\t"<<flag<<endl;

	flag = true;
	IsPostVisit(b, left, right, flag);
	cout<<"result_2:\t"<<flag<<endl;

	return 0;
}

void IsPostVisit(int a[], int left, int right, bool &flag)
{
	if(flag && left<right)
	{
		int i = left;
		while(a[i] < a[right])
			i++;

		for(int j=i ; j<right ; j++)
			if(a[j] < a[right])
			{
				flag = false;
				return;
			}

		IsPostVisit(a, 0, i-1, flag);
		IsPostVisit(a, i, right-1, flag);
	}
}
