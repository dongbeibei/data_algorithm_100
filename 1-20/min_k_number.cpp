/*
 * find the minimum k numbers in n numbers
 * author: dongbeibei
 * time: 2013/6/10
 */


#include <iostream>
#include <set>

using namespace std;

void find_1(int *, int);

void swap(int &a, int &b);
int partion(int array[], int length, int start, int end);
void GetKLeastNumbers(int array[], int length, int result[], int k);

void find_3(int array[], int length, multiset<int, greater<int> > &result, int k);

int main(void)
{
	int test[] = {2, 1, 7, 8, 3};
	int k = 3;

	cout<<"-----------method 1-------------\n";
	find_1(test, sizeof(test)/sizeof(int));
	cout<<"result:\t";
	for(int i=0 ; i<k ; i++)
		cout<<test[i]<<"  ";
	cout<<endl;

	cout<<"-----------method 2-------------\n";
	int result[k];
	GetKLeastNumbers(test, sizeof(test)/sizeof(int), result, k);
	cout<<"result:\t";
	for(int i=0 ; i<k ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;

	cout<<"-----------method 3-------------\n";
	multiset<int, greater<int> > min_k;
	find_3(test, sizeof(test)/sizeof(int), min_k, k);
	cout<<"result:\t";
	multiset<int, greater<int> >::iterator iter;
	for(iter=min_k.begin() ; iter!=min_k.end() ; iter++)
		cout<<*iter<<"  ";
	cout<<endl;

	return 0;
}

void find_1(int *array, int length)
{
	int i, j, min, key=0;

	for(i=0 ; i<length ; i++)
	{
		min = array[i];
		for(j=i ; j<length ; j++)
		{
			if(array[j] < min)
			{
				key = j;
				min = array[j];
			}
		}
/*
		cout<<"min:"<<min<<"  "<<key<<endl;
		cout<<"i: "<<i<<endl;
		cout<<"array[key]:"<<array[key]<<endl;
		cout<<"array[i]:"<<array[i]<<endl;
*/
		array[key] = array[i];
		array[i] = min;

	//	cout<<"array[key]:"<<array[key]<<endl;
	//	cout<<"array[i]:"<<array[i]<<endl<<endl;
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partion(int array[], int length, int start, int end)
{
	if(array==NULL || length<=0)
		return -1;

	int index = start - 1;
	for(int i=start ; i<end ; i++)
	{
		if(array[i] < array[end])
		{
			++index;
			swap(array[i], array[index]);
		}
	}
	
	++index;
	swap(array[index], array[end]);
	
	return index;
}

void GetKLeastNumbers(int array[], int length, int result[], int k)
{
	if(array==NULL || length<=0 || result==NULL || k<=0)
		return;

	int start = 0, end = length-1;
	int index = partion(array, length, start, end);

	if(index > k-1)
		partion(array, length, start, index-1);
	else if(index < k-1)
		partion(array, length, index+1, end);

	for(int i=0; i<k ; i++)
		result[i] = array[i];
}

void find_3(int array[], int length, multiset<int, greater<int> > &result, int k)
{
	if(array==NULL || k<1 || k>length)
		return;

	result.clear;
	multiset<int, greater<int> >::iterator iter;
	for(int i=0 ; i<length ; i++)
	{
		if(result.size() < k)
			result.insert(array[i]);
		else
		{
			iter = result.begin();
			if(*iter < *(result.begin()))
			{
				result.erase(iter);
				result.insert(array[i]);
			}
		}
	}
}
