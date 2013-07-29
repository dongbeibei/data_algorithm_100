/*
 * hashÊý×é
 */


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "ABCDEFGHLMNOPQRS";
	//string str2 = "DCGSRQPOM";
	string str2 = "DCGSRQPOMZ";
	int hash[26] = {0};
	int num = 0;

	for(int j=0 ; j<str2.length() ; ++j)
	{
		int index = str2[j] - 'A';

		if(hash[index] == 0)
		{
			hash[index] = 1;
			++num;
		}
	}

	for(int k=0 ; k<str1.length() ; ++k)
	{
		int index = str1[k] - 'A';

		if(hash[index] == 1)
		{
			hash[index] = 0;
			--num;
			if(num == 0)
				break;
		}
	}

	if(num == 0)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}
