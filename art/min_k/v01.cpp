/*
 * 先对元素数组原地建立最小堆，O(n)。然后提取K次，但是每次提取时，
 * 换到顶部的元素只需要向下移动顶多K次就足够了，下移次数逐次减少。
 * 此种方法的复杂度为O(n+k^2)。
 */


#include <iostream>

using namespace std;

#define MAXLEN 123456
#define K 100

void HeapAdjust(int array[], int i, int Length);
void Swap(int *a, int *b);
int GetMin(int array[], int Length, int k);
void Kmin(int array[], int Length, int k);

int main(void)
{
	int array[MAXLEN];
	for(int i=MAXLEN ; i>0 ; --i)
		array[MAXLEN-i] = i;

	cout<<"result:\t";
	Kmin(array, MAXLEN, K);
	cout<<endl;

	return 0;
}

void HeapAdjust(int array[], int i, int Length)
{
	int		child, temp;

	for(temp=array[i] ; 2*i+1<Length ; i=child)
	{
		child = 2 * i + 1;

		if(child<Length-1 && array[child+1]<array[child])
			child++;
		
		if(temp>array[child])
			array[i] = array[child];
		else
			break;
		array[child] = temp;
	}
}

void Swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int GetMin(int array[], int Length, int k)
{
	int min = array[0];

	Swap(&array[0], &array[Length-1]);

	int child, temp;
	int i=0, j=k-1;

	for(temp=array[0] ; j>0&&2*i+1<Length ; --j,i=child)
	{
		child = 2 * i + 1;

		if(child<Length-1 && array[child+1]<array[child])
			child++;

		if(temp>array[child])
			array[i] = array[child];
		else
			break;
		array[child] = temp;
	}

	return min;
}

void Kmin(int array[], int Length, int k)
{
	for(int i=Length/2-1 ; i>=0 ; --i)
		HeapAdjust(array, i, Length);

	int j=Length;
	for(int i=k ; i>0 ; --i,--j)
	{
		int min = GetMin(array, j, i);
		cout<<min<<",";
	}
}
