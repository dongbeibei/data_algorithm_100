/*
 * ¼ÆËã1234567891011121314151617181920*2019181716151413121110987654321
 *
 * author:	dongbeibei
 * time:		2013/7/8
 */


#include <iostream>
#include <cstring>

using namespace std;

bool traverse(const char *num, int *&test, int &len);

int main(void)
{
	const char *num1 = "1234567891011121314151617181920";
	const char *num2 = "2019181716151413121110987654321";
	//const char *num1 = "12";
	//const char *num2 = "12";
	int *test1, *test2, *result;
	int len1, len2, len;
	int temp;

	traverse(num1, test1, len1);
	traverse(num2, test2, len2);

	//cout<<len1<<endl;
	cout<<"test1:\t";
	for(int i=0 ; i<len1 ; i++)
		cout<<test1[i];
	cout<<endl;
	//cout<<len2<<endl;
	cout<<"test2:\t";
	for(int i=0 ; i<len2 ; i++)
		cout<<test2[i];
	cout<<endl;

	len = len1 + len2;
	result = new int[len];
	if(!result)
	{
		cout<<"ERROR: the new method fails."<<endl;
		return 1;
	}
	for(int i=0 ; i<len ; i++)
		result[i] = 0;
	for(int i=0 ; i<len1 ; i++)
	{
		for(int j=0 ; j<len2 ; j++)
		{
			int k = i + j;
			temp = test1[i] * test2[j];
			while(1)
			{
				temp += result[k];
				if(temp/10)
				{
					result[k] = temp%10;
					temp = temp/10;
				}
				else
				{
					result[k] = temp;
					break;
				}
				k++;
			}
		}
	}

	cout<<"result:\t";
	int i = len - 1;
	if(result[i] == 0)
		i--;
	for( ; i>=0 ; i--)
		cout<<result[i];
	cout<<endl;

	return 0;
}

bool traverse(const char *num, int *&test, int &len)
{
	int i;

	len = strlen(num);
	test = new int[len];
	if(!test)
	{
		cout<<"ERROR: the new method fails."<<endl;
		return false;
	}

	for(i=0 ; i<len ; i++)
		if(num[i]>='0'&&num[i]<='9')
			test[len-i-1] = num[i] - '0';
		else
		{
			cout<<"ERROR: the num is error."<<endl;
			return false;
		}

	return true;
}
