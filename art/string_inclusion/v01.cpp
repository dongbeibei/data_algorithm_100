/*
 * À≥–Ú∆•≈‰
 */


#include <iostream>

using namespace std;

int CompareString(string LongString, string ShortString);

int main(void)
{
	string LongString = "ABCDEFGHLMNOPQRS";
	//string ShortString = "DCGSRQPOM";
	string ShortString = "DCGSRQPOMZ";

	CompareString(LongString, ShortString);

	return 0;
}

int CompareString(string LongString, string ShortString)
{
	for(int i=0; i<ShortString.length() ; ++i)
	{
		int j;
		for(j=0 ; j<LongString.length() ; ++j)
		{
			if(LongString[j] == ShortString[i])
				break;
		}

		if(j ==  LongString.length())
		{
			cout<<"false"<<endl;
			return 0;
		}
	}

	cout<<"true"<<endl;

	return 1;
}
