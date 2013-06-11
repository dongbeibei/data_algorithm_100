/*
 * input: 		the first array is fixed
 * output:	the second array, the second array's number is the counts of it apper in the second array.
 * example:	a[] = {0,1,2,3,4,5,6,7,8,9}
 *			b[] = {6,2,1,0,0,0,1,0,0,0}
 *			0 apper 6 times in the b[], 1 apper 2 times, 2 apper 1 time, 6 apper 1 time
 *
 *author:		dongbeibei
 *building time:	2013/6/10
 *modifing time:	
 */


#include <iostream>

using namespace std;

int main(void)
{
	int length = 10;
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[10];
	bool tag, result;
	int count;

	while(!result)
	{
		tag = true;
		for(int i=0 ; i<length ; i++)
		{
			count = 0;
			for(int j=0 ; j<length ; j++)
			{
				if(b[j] == a[i])
					count++;
			}

			if(count != b[i])
			{
				tag = false;
				b[i] = count;
			}
		}

		result = tag;
	}

	cout<<"result:\t";
	for(int i=0 ; i<length ; i++)
		cout<<b[i]<<"  ";
	cout<<endl;

	return 0;
}
