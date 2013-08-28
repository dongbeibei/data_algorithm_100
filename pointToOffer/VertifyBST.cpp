/*
 * function: vertify a sequence of BST
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */

#include <iostream>

using namespace std;

bool VertifyBST(int array[], int len)
{
	if(array==NULL || len<=0)
		return false;

	int temp = array[len - 1];
	int i, j;
	for(i=0 ; i<len-1 ; ++i)
		if(array[i] > temp)
			break;

	for(j=i ; j<len-1 ; ++j)
		if(array[j] < temp)
			return false;

	bool left, right;
	left = right = true;

	if(i>0)
		left = VertifyBST(array, i);
	if(i<len-1)
		right = VertifyBST(array+i, len-i-1);

	return (left && right);
}

//follow: Unit Test
//the correct input
void test1();
//the worng input
void test2();
//the invalid input
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();

	return 0;
}

void test1()
{
	cout<<"Test 1:\n";

	int array1[] = {1,3,2,5,7,6,4};
	int len = 7;

	cout<<"result:\t"<<VertifyBST(array1, len)<<endl;

	int array2[] = {1,2,3,4};
	len = 4;

	cout<<"result:\t"<<VertifyBST(array2, len)<<endl;

	int array3[] = {4,3,2,1};
	len = 4;

	cout<<"result:\t"<<VertifyBST(array3, len)<<endl;

	int array4[] = {5};
	len = 1;

	cout<<"result:\t"<<VertifyBST(array4, len)<<endl;
}

void test2()
{
	cout<<"Test 2:\n";

	int array1[] = {1,3,2,7,4,6,5};
	int len = 7;

	cout<<"result:\t"<<VertifyBST(array1, len)<<endl;
}

void test3()
{
	cout<<"Test 3:\n";

	int *array1 = NULL;
	int len = 3;

	cout<<"result:\t"<<VertifyBST(array1, len)<<endl;

	int array[] = {1, 2, 3, 4};
	len = 0;

	cout<<"result:\t"<<VertifyBST(array, len)<<endl;
}
