/*
 * ×Ö·û´®Ô­µØÑ¹Ëõ
 * ÀýÈç: ×Ö·û´®"eeeeeaaaff"Ñ¹ËõÎª"e5a3f5"
 *
 * author:	dongbeibei
 * time:		2013/7/4
 */


#include <iostream>

using namespace std;

void strCompress(char *str);

int main(void)
{
	char str[] = "eeeeeaaaff";

	cout<<"origin:\t"<<str<<endl;
	strCompress(str);
	cout<<"result:\t"<<str<<endl;

	return 0;
}

void strCompress(char *str)
{
	if(!str)
	{
		cout<<"the string is empty!"<<endl;
		return;
	}

	int i, j, k, sum;

	for(i=j=k=0 ;  ; i++)
	{
		if(str[i] == '\0')
		{
			if(sum > 1)
				str[++k] = sum + '0';
			break;
		}
	
		if(i == j)
		{
			sum = 1;
			continue;
		}

		if(str[i] == str[j])
		{
			sum++;
			continue;
		}
		else
		{
			if(sum == 1)
			{
				j = i;
				i--;
			}
			else
			{
				str[++k] = sum + '0';
				str[++k] = str[i]; 
				j = i;
				i--;
			}
		}
	}
	str[k+1] = '\0';
}