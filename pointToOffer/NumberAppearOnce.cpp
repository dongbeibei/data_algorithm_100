/*
 * function: 
 *		given a array, only one number appear once, the other numbers appear twice
 *		given a array, only two numbers appear once, the other numbers appear twice
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

bool isInputInvalid = false;

//find one number appear once
//input:
// 		data:	the array address
//		length:	the length of the array
//output:
//		0: 		check isInputInvalid is true or false, identify the return value is a flag or a result
//		others:	the result
int Find1NumAppearOnce(int *data, int length)
{
	isInputInvalid = false;

	if(data==NULL || length<=0)
	{
		isInputInvalid = true;
		return 0;
	}

	int result = 0;

	for(int i=0 ; i<length ; ++i)
		result ^= data[i];

	return result;
}

int FindFirstBitIs1(int result)
{
	int index = 0;
	while(((result&1) == 0) && index < 8 * sizeof(int))
	{
		num = num>>1;
		++index;
	}

	return index;
}

bool IsBit1(int num, int index)
{
	num = num>>index;

	return (num&1);
}

void Find2NumsAppearOnce(int *data, int length, int *num1, int *num2)
{
	isInputInvalid = false;

	if(data==NULL || length<2)
	{
		isInputInvalid = true;
		return;
	}

	int result = 0;
	for(int i=0 ; i<length ; ++i)
		result ^= data[i];

	int indexOf1 = FindFirstBitIs1(result);

	*num1 = *num2 = 0;
	for(int i=0 ; i<length ; ++i)
	{
		if(IsBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}
