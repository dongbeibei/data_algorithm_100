/*
 * a1a2...anb1b2...bn	->	a1b1a2b2...anbn
 * time: O(n)		space:O(1)
 *
 * author:	feng
 * time:		2013/8/13
 */


#include <iostream>

using namespace std;

void display(int result[], int len, const char *str);
void arraySwitch(int A[], int B[], int len);
void innerSwitch(int result[], int from, int end, int len);
void myswap(int &a, int &b);

int main(void)
{
	int A[] = {1, 3, 5, 7, 9, 11};
	int B[] = {2, 4, 6, 8, 10, 12};
	int len = sizeof(A)/sizeof(A[0]);

	arraySwitch(A, B, len);

	return 0;
}

void display(int result[], int len, const char *str)
{
	cout<<str;
	for(int i=0 ; i<len ; ++i)
		cout<<result[i]<<" ";
	cout<<endl;
}

void arraySwitch(int A[], int B[], int len)
{
	int *result = new int[len*2];

	int i = 0, j = 0;
	for( ; i<len ; ++i)
		result[i] = A[i];
	for(; i<len*2 ; ++i,++j)
		result[i] = B[j];

	display(result, len*2 , "origin: ");

	innerSwitch(result, 0, len*2-1, len);

	delete []result;
}

void innerSwitch(int result[], int from, int end, int len)
{
	if((end-from+1) <= 4)
	{
		myswap(result[from+1], result[end-1]);
		display(result, len*2, "result: ");
		
		return;
	}

	bool flag = false;

	if((end-from+1)/2%2)
		flag = true;

	int i, j, step;
	int mid = from + (end - from)/2 + 1;
	for(i=from,j=mid,step=0 ; i+2<mid ; )
	{
		myswap(result[i+1], result[j]);
		display(result, len*2, "switch1: ");
		++i;
		++step;
		if(step == 2)
		{
			++j;
			step = 0;
		}
	}
	if(i+2>j)
		cout<<"error\n";

	if(flag)
	{
		myswap(result[i+1], result[mid]);
		display(result, len*2, "switch2: ");
		innerSwitch(result, i+1, end, len);
	}
	else
	{
		myswap(result[i+1], result[mid+1]);
		display(result, len*2, "switch3: ");
		innerSwitch(result, mid, end, len);
	}

	return;
}

void myswap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
