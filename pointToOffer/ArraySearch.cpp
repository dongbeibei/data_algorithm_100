/*
 * function: find the key in two-dimensional array
 *			 the array satify two condition: arrary[i][j] < array[i+1][j] ; array[i][j] < array[i][j+1]
 *
 * author:	dongbeibei
 * time:	2013/8/26
 */

#include <iostream>

using namespace std;

bool find(int *matrix, const int rows, const int columns, int key)
{
	bool found = false;

	if(matrix!=NULL && rows>0 && columns>0)
	{
		int row = 0;
		int column = columns - 1;

		while(row<rows && column>=0)
		{
			int temp = matrix[row*columns+row];
			if(temp == key)
			{
				found = true;
				break;
			}
			else if(temp < key)
				++row;
			else
				--column;
		}
	}

	return found;
}

//the follow: Unit Test
void test();

int main(void)
{
	test();

	return 0;
}

void test()
{
	const int rows = 4, columns = 4;
	int use[columns][rows] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int *matrix = &(use[0][0]);
	int key;

	cout<<"Test 1:"<<endl;
	key = 7;
	cout<<"except result:\t1"<<endl;
	cout<<"real result:\t"<<find(matrix, rows, columns, key)<<endl<<endl;

	cout<<"Test 2:"<<endl;
	key = 5;
	cout<<"except result:\t0"<<endl;
	cout<<"real result:\t"<<find(matrix, rows, columns, key)<<endl<<endl;

	cout<<"Test 3:"<<endl;
	key = 7;
	cout<<"except result:\t0"<<endl;
	cout<<"real result:\t"<<find(NULL, rows, columns, key)<<endl<<endl;
}
