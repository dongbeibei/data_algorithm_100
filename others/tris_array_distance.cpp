/*
 * function: given a[l],b[m],c[n],  obtain i,j,k which distance=max(|a[i]-b[j]|,|a[i]-c[k]|,|b[j]-c[k]|) is the minimum
 *
 * author: feng
 * time:   2013/9/22
 */


#include <iostream>
#include <climits>

using namespace std;

int min_distance(int *a, int a_len, int *b, int b_len, int *c, int c_len, int &a_index, int &b_index, int &c_index)
{
	if(a==NULL || b==NULL || c==NULL)
		return -1;
	if(a_len<=0 || b_len<=0 || c_len<=0)
		return -1;

	int i, j, k;
	int distance, temp, index_min;
	i = j = k = temp = index_min =0;
	distance = INT_MAX;
	while(!(i==a_len||j==b_len||k==c_len))
	{
		if(a[i] < b[j])
		{
			if(a[i] < c[k])
			{
				if(b[j] < c[k])
				{
					temp = c[k] - a[i];
				}
				else
				{
					temp = b[j] - a[i];
				}
				index_min = 1;
				++i;
			}
			else
			{
				temp = b[j] - c[k];
				index_min = 3;
				++k;
			}
		}
		else
		{
			if(a[i] < c[k])
			{
				temp = c[k] - b[j];
				index_min = 2;
				++j;
			}
			else
			{
				if(b[j] < c[k])
				{
					temp = a[i] - b[j];
					index_min = 2;
					++j;
				}
				else
				{
					temp = a[i] - c[k];
					index_min = 3;
					++k;
				}
			}
		}

		if(temp < distance)
		{
			distance = temp;
			a_index = i;
			b_index = j;
			c_index = k;
			if(index_min == 1)
				--a_index;
			else if(index_min == 2)
				--b_index;
			else
				--c_index;
		}
		if(distance == 0)
			return 0;
	}

	return distance;
}

//Unit Test
void test(int *a, int a_len, int *b, int b_len, int *c, int c_len);
void test1();
void test2();
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

void test(int *a, int a_len, int *b, int b_len, int *c, int c_len)
{
	int a_index, b_index, c_index;

	int result = min_distance(a, a_len, b, b_len, c, c_len, a_index, b_index, c_index);
	if(result == -1)
		cout<<"Input is invalid!"<<endl;
	else
	{
		cout<<"The min distance:\t"<<result<<endl;
		cout<<"a["<<a_index<<"] = "<<a[a_index]<<endl;
		cout<<"b["<<b_index<<"] = "<<b[b_index]<<endl;
		cout<<"c["<<c_index<<"] = "<<c[c_index]<<endl;
	}
}

void test1()
{
	int a[] = {1,2,3};
	int b[] = {4,5,6};
	int c[] = {7,8,9};
	int a_len = sizeof(a)/sizeof(int);
	int b_len = sizeof(b)/sizeof(int);
	int c_len = sizeof(c)/sizeof(int);
	int a_index, b_index, c_index;

	test(a, a_len, b, b_len, c, c_len);
}

void test2()
{
	int a[] = {1,2,3};
	int b[] = {3,5,6};
	int c[] = {3,8,9};
	int a_len = sizeof(a)/sizeof(int);
	int b_len = sizeof(b)/sizeof(int);
	int c_len = sizeof(c)/sizeof(int);

	test(a, a_len, b, b_len, c, c_len);
}

void test3()
{
	int a[] = {1,1,1};
	int b[] = {2,2,2};
	int c[] = {3,3,3};
	int a_len = sizeof(a)/sizeof(int);
	int b_len = sizeof(b)/sizeof(int);
	int c_len = sizeof(c)/sizeof(int);

	test(a, a_len, b, b_len, c, c_len);
}
