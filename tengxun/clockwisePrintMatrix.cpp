/*
Ë³Ê±Õë´òÓ¡¾ØÕó£¬
Èç:	1	2	3	4	5
		6	7	8	9	10
		11	12	13	14	15
		16	17	18	19	20
		21	22	23	24	25
		
output:	1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
 *
 * author:	dongbeibei
 * time:		2013/7/2
*/


#include <iostream>

using namespace std;

void print(int *a, int i_len, int j_len);

int main(void)
{
	const int i_len = 5;
	const int j_len = 5;
	int a[i_len][j_len] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

	print((int *)a, i_len, j_len);

	return 0;
}

void print(int *a, int i_len, int j_len)
{
	int i_start, i_end, j_start, j_end;
	int flag, i, j;

	i_start = j_start = 0;
	i_end = i_len - 1;
	j_end = j_len - 1;
	i = j = 0;

	flag = 1;
	while(i_start<=i_end || j_end<=j_end)
	{
		if(i==i_start && i==i_end && j==j_start && j==j_end)
		{
			cout<<a[i*j_len+j]<<endl;
			break;
		}
	
		switch(flag)
		{
			case 1:
				while(j<=j_end)
				{
					cout<<a[i*j_len+j]<<"  ";
					j++;
				}
				j--;
				
				i_start++;
				i++;
				flag = 2;
				break;
			case 2:
				while(i<=i_end)
				{
					cout<<a[i*j_len+j]<<"  ";
					i++;
				}
				i--;

				j_end--;
				j--;
				flag = 3;
				break;
			case 3:
				while(j>=j_start)
				{
					cout<<a[i*j_len+j]<<"  ";
					j--;
				}
				j++;

				i_end--;
				i--;
				flag = 4;
				break;
			case 4:
				while(i>=i_start)
				{
					cout<<a[i*j_len+j]<<"  ";
					i--;
				}
				i++;

				j_start++;
				j++;
				flag = 1;
				break;
			default:
				break;
		}
	}
}
