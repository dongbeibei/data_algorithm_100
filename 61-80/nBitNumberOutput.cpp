/*
输出1 到最大的N 位数
题目：输入数字n，按顺序输出从1 最大的n 位10 进制数。比如输入3，
则输出1、2、3 一直到最大的3 位数即999。

分析：这是一道很有意思的题目。看起来很简单，
其实里面却有不少的玄机。

 * author:	dongbeibei
 * time:		2013/6/21
 */


#include <iostream>

using namespace std;

//method 1: the simplest one
void print1ToMaxofNDigits1(int n);
//method 2: use a char array to display the number
void print1ToMaxofNDigit2(int n);
void Increment(char *number);
void print(char *number);
//method 3: use full array to display
void PrintNumber(char* number);
void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index);
void Print1ToMaxOfNDigit3(int n);

int main(void)
{
	int n;
	cin>>n;

	//print1ToMaxofNDigits1(n);
	print1ToMaxofNDigit2(n);
	Print1ToMaxOfNDigit3(n);

	return 0;
}

void print1ToMaxofNDigits1(int n)
{
	int end = 1;
	int i, j;

	while(n--)
		end *= 10;

	cout<<"result:\n";
	for(i=1, j=0 ; i<end ; i++)
	{
		cout<<i<<"\t";
		j++;
		if(j == 10)
		{
			cout<<endl;
			j = 0;
		}
	}
	cout<<endl;
}

void print1ToMaxofNDigit2(int n)
{
	if(n <= 0)
		return;

	char *number = new char[n+1];

	for(int i=0 ; i<n ;i++)
		number[i] = 0;
	number[n] = '\0';

	while(!Increment(number))
		print(number);

	cout<<endl;

	delete []number;
}

void Increment(char *number)
{
	bool 	isOverflow = false;
	int		nTakeover = 0;
	int		nLength = strlen(number);

	for(int i=nLength-1 ; i>=0 ; i--)
	{
		int nNum = number[i] - '0' + nTakeover;

		if(i == nLength-1)
			nNum++;

		if(nNum >= 10)
		{
			if(i == 0)
				isOverflow = true;
			else
			{
				nNum -= 10;
				nTakeover = 1;
				number[i] = '0' + nNum;
			}
		}
		else
		{
			number[i] = '0' + nNum;
			break;
		}
	}

	return isOverflow;
}

void print(char *number)
{
	bool	isBeginning0 = true;
	int		nLength = strlen(number);

	for(int i=0 ; i<nLength ; i++)
	{
		if(isBeginning0 && number[i] != 0)
			isBeginning0 = false;

		if(!isBeginning0)
			cout<<number[i];
	}

	cout<<"  ";
}

void PrintNumber(char* number)
{
	bool isBeginning0=true;
	int nLength=strlen(number);

	for(int i=0; i<nLength; i++)
	{
		if(isBeginning0 && number[i]!='0')
			isBeginning0=false;

		if(!isBeginning0)
		{
			cout<<number[i];
		}
	}
	cout<<" ";
}

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if(index==length-1)
	{
		PrintNumber(number);
		return;
	}

	for(int i=0; i<10; i++)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number, length, index+1);
	}
}

void Print1ToMaxOfNDigit3(int n)
{
	if(n<0)
		return;

	char *number=new char[n+1];
	number[n]='\0';

	for(int i=0; i<10; i++)
	{
		number[0]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
}
