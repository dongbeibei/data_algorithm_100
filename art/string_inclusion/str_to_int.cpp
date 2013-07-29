/*
 * string to int
 */


#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int str_to_int(string str);

int main(void)
{
	string str = "-1024";

	int num = str_to_int(str);
	cout<<"num:\t"<<num<<endl;

	return 0;
}

int str_to_int(string str)
{
	assert(str.size() > 0);

	int pos = 0;
	int sym = 1;

	if(str[pos] == '+')
		++pos;
	else if(str[pos] == '-')
	{
		++pos;
		sym = -1;
	}

	int num = 0;
	while(pos < str.length())
	{
		assert(str[pos] >= '0');
		assert(str[pos] <= '9');

		num = num * 10 + (str[pos] - '0');

		assert(num >= 0);
		++pos;
	}

	num *= sym;

	return num;
}

/*
char *strcpy(char *strDest, const char *strSrc)
{
	assert((strDest!=NULL) && (strSrc!=NULL));
	char *address = strDest;
	while((*strDest++ = *strSrc++) != '\0');
	return address;
}
*/
