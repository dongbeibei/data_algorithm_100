/*
 * function: reorder the array, put the odd in the first part, the even in the second part
 *
 * author:	donebeibei
 * time:	feng
 */

#include <iostream>
#include <queue>

using namespace std;

void ReorderArray1(int array[], int len)
{
	if(array==NULL || len<=0)
		return;

	queue<int> odd;
	queue<int> even;
	int i;
	for(i=0 ; i<len ; ++i)
	{
		int temp = array[i];
		if((temp & 0x1) == 1)
			odd.push(temp);
		else
			even.push(temp);
	}

	//cout<<"i:"<<i<<endl;
	i = 0;
	while(!odd.empty())
	{
		//cout<<"odd:"<<odd.front()<<endl;
		array[i++] = odd.front();
		odd.pop();
	}
	while(!even.empty())
	{
		//cout<<"even:"<<even.front()<<endl;
		array[i++] = even.front();
		even.pop();
	}
}

void ReorderArray2(int array[], int len)
{
	if(array==NULL || len<=0)
		return;

	int start, end;

	start = 0;
	end = len -1;
	while(true)
	{
		while((array[start] & 0x1) == 1)
			++start;
		while((array[end] & 0x1) == 0)
			--end;
		if(start < end)
			swap(array[start], array[end]);
		else
			break;
	}
}

//follow: Unit Test
void display(int *array, int len);
void test1(void (*method)(int *, int));
void test2(void (*method)(int *, int));
void test3(void (*method)(int *, int));

int main(void)
{
	test1(ReorderArray1);
	cout<<endl;
	test2(ReorderArray1);
	cout<<endl;
	test3(ReorderArray1);

	return 0;
}

void display(int *array, int len)
{
	for(int i=0 ; i<len ; ++i)
		cout<<array[i]<<" ";
	cout<<endl;
}

void test1(void (*method)(int *, int))
{
	int array1[] = {1, 2, 3, 4, 5, 6};
	int array2[] = {1, 2, 3, 4, 5, 6, 7};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int len2 = sizeof(array2)/sizeof(array2[0]);

	cout<<"Test 1:\n";
	cout<<"except result: "<<"1 5 3 4 2 6 "<<endl;
	cout<<"real result: ";
	method(array1, len1);
	display(array1, len1);
	cout<<"except result: "<<"1 7 3 5 4 6 2 "<<endl;
	cout<<"real result: ";
	method(array2, len2);
	display(array2, len2);
}

void test2(void (*method)(int *, int))
{
	int array1[] = {1, 3, 5, 7, 9};
	int array2[] = {2, 4, 6, 8, 10};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int len2 = sizeof(array2)/sizeof(array2[0]);

	cout<<"Test 2:\n";
	cout<<"except result: "<<"1 3 5 7 9 "<<endl;
	cout<<"real result: ";
	method(array1, len1);
	display(array1, len1);
	cout<<"except result: "<<"2 4 6 8 10 "<<endl;
	cout<<"real result: ";
	method(array2, len2);
	display(array2, len2);
}

void test3(void (*method)(int *, int))
{
	int array1[0];
	int len1 = 0;

	cout<<"Test 3:\n";
	cout<<"except result: "<<""<<endl;
	cout<<"real result: ";
	method(array1, len1);
	display(array1, len1);
}
