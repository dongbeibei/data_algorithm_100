/*
 * 先快速排序，再匹配
 */


#include <iostream>
#include <string>

using namespace std;

int partition(string &str, int lo, int hi);
void quicksort(string &str, int lo, int hi);
void compare(string str1, string str2);

int main(void)
{
	string LongString = "ABCDEFGHLMNOPQRS";
	string ShortString = "DCGSRQPOM";
	//string ShortString = "DCGSRQPOMZ";

	quicksort(LongString, 0 , LongString.length() - 1);
	quicksort(ShortString, 0, ShortString.length() - 1);

	compare(LongString, ShortString);

	return 0;
}

int partition(string &str, int lo, int hi)
{
	int key = str[hi];
	int i = lo - 1;

	for(int j=lo ; j<hi ; ++j)
	{
		if(str[j] < key)
		{
			swap(str[++i], str[j]);
		}
	}
	swap(str[++i], str[hi]);

	return i;
}

void quicksort(string &str, int lo, int hi)
{
	if(lo < hi)
	{
		int k = partition(str, lo, hi);
		quicksort(str, lo, k-1);
		quicksort(str, k+1, hi);
	}
}

void compare(string str1, string str2)
{
	int posOne = 0;
	int posTwo = 0;

	while(posTwo<str2.length() && posOne<str1.length())
	{
		while(str1[posOne] < str2[posTwo] && posOne < str1.length()-1)
			++posOne;

		if(str1[posOne] != str2[posTwo])
			break;

		++posTwo;
	}

	if(posTwo == str2.length())
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
