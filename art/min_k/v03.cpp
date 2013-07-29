/*
 * 借助堆，查找最小的K个数
 */


#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

void MaxHeap(int heap[], int i, int len);
void BuildHeap(int heap[], int len);

int main(void)
{
	int k;
	cin>>k;
	int *heap = new int[k+1];
	FILE *fp = fopen("data.txt", "r");
	assert(fp);

	for(int i=1 ; i<=k ; ++i)
		fscanf(fp, "%d ", &heap[i]);

	BuildHeap(heap, k);

	int newData;
	while(fscanf(fp, "%d", &newData) != EOF)
	{
		if(newData < heap[1])
		{
			heap[1] = newData;
			MaxHeap(heap, 1, k);
		}
	}

	cout<<"result:\t";
	for(int j=1 ; j<=k ; ++j)
		cout<<heap[j]<<" ";
	cout<<endl;

	fclose(fp);

	return 0;
}

void MaxHeap(int heap[], int i, int len)
{
	int largeIndex = -1;
	int left = i * 2;
	int right = left + 1;

	if(left<=len && heap[left]>heap[i])
		largeIndex = left;
	else
		largeIndex = i;

	if(right<len && heap[right]>heap[i])
		largeIndex = right;

	if(largeIndex != i)
	{
		swap(heap[i], heap[largeIndex]);
		MaxHeap(heap, largeIndex, len);
	}
}

void BuildHeap(int heap[], int len)
{
	if(heap == NULL)
		return;

	int index = len/2;
	for(int i=index ; i>=1 ; i--)
		MaxHeap(heap, i, len);
}
