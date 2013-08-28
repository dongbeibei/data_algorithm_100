/*
 * function: print the matrix in clockwise
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */


#include <iostream>

using namespace std;

void PrintMatrix(int *matrix, int rows, int columns)
{
	int row_start, row_end, column_start, column_end;
	int per_row, row, column;

	row_start = column_start = 0;
	row_end = rows - 1;
	column_end = columns - 1;
	per_row = columns;
	row = column = 0;

	while(row_start<=row_end || column_start<=column_end)
	{
		for(column=column_start ; column<=column_end ; ++column)
			cout<<*(matrix + row * per_row + column)<<" ";
		++row_start;
		--column;
		//if(row_start>=row_end && column_start>=column_end)
		if(row_start>row_end && column_start>column_end)
			break;
		
		for(row=row_start ; row<=row_end ; ++row)
			cout<<*(matrix + row * per_row + column)<<" ";
		--column_end;
		--row;
		//if(row_start>=row_end && column_start>=column_end)
		if(row_start>row_end && column_start>column_end)
			break;

		for(column=column_end ; column>=column_start ; --column)
			cout<<*(matrix + row * per_row + column)<<" ";
		--row_end;
		++column;
		//if(row_start>=row_end && column_start>=column_end)
		if(row_start>row_end && column_start>column_end)
			break;

		for(row=row_end ; row>=row_start ; --row)
			cout<<*(matrix + row * per_row + column)<<" ";
		++column_start;
		++row;
	}
}

//follow: Unit Test
//Matrix has m rows and n columns: m > 1 and n > 1
void test1();
//Matrix has m rows and 1 colums
void test2();
//Matrix has 1 row and n columns
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

	int rows = 4;
	int columns = 4;
	int matrix1[4][4] = { {1,2,3,4}, {6,7,8,9}, {11,12,13,14}, {16,17,18,19}};

	PrintMatrix((int*)matrix1, rows, columns);
	cout<<endl;

	rows = 4;
	columns = 5;
	int matrix2[4][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}};

	PrintMatrix((int*)matrix2, rows, columns);
	cout<<endl;

	rows = 5;
	columns = 5;
	int matrix3[5][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

	PrintMatrix((int*)matrix3, rows, columns);
	cout<<endl;

	rows = 5;
	columns = 4;
	int matrix4[5][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

	PrintMatrix((int*)matrix4, rows, columns);
	cout<<endl;
}

void test2()
{
	cout<<"Test 2:\n";


}

void test3()
{
	cout<<"Test 3:\n";


}
