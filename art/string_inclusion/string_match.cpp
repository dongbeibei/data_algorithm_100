/*
 * 假设两个字符串中所含有的字符和个数都相同我们就叫这两个字符串
 * 匹配，比如：abcda和adabc, 由于出现的字符个数都是相同，只是顺序不同
 * ，所以这两个字符串是匹配的。
 */


#include <iostream>
#include <cstring>

using namespace std;

bool Is_Match(const char *strOne, const char *strTwo);

int main(void)
{
	string strOne = "ABBA";
	string strTwo = "BBAA";

	bool flag = Is_Match(strOne.c_str(), strTwo.c_str());

	if(flag == true)
		cout<<"Match"<<endl;
	else
		cout<<"No Match"<<endl;

	return 0;
}

bool Is_Match(const char *strOne, const char *strTwo)
{
	int lenOfOne = strlen(strOne);
	int lenOfTwo = strlen(strTwo);

	if(lenOfOne != lenOfTwo)
		return false;

	int hash[26] = {0};

	for(int i=0 ; i<lenOfOne ; ++i)
	{
		int index = strOne[i] - 'A';

		++hash[index];
	}

	for(int j=0 ; j<lenOfTwo ; ++j)
	{
		int index = strTwo[j] - 'A';

		if(hash[index] != 0)
			--hash[index];
		else
			return false;
	}

	return true;
}
