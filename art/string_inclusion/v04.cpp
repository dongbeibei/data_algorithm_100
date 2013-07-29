/*
 * bitmap
 */


#include <iostream>
#include <cstring>

using namespace std;

#define getbit(x) (1<<(x-'a'))

void a_has_b(const char *a, const char *b);

int main(void)
{
	const char *str1 = "abcdefghijklmnopqrstuvwxyz";
	const char *str2 = "akjsdfasdfiasdflasdfjklffhasdfasdfjklasdfjkasdf";
	const char *str3 = "asdffaxcfsf";
	const char *str4 = "asdfai";

	a_has_b(str1, str2);
	a_has_b(str1, str3);
	a_has_b(str3, str4);

	return 0;
}

void a_has_b(const char *a, const char *b)
{
	int i = 0;
	int dictionary = 0;
	int alen = strlen(a);
	int blen = strlen(b);

	for(i=0 ; i<alen ; ++i)
		dictionary |= getbit(a[i]);

	for(i=0 ; i<blen ; ++i)
	{
		if(dictionary != (dictionary|getbit(b[i])))
			break;
	}

	if(i == blen)
		cout<<"YES! A has B!\n";
	else
		cout<<"NO! char at "<<i+1<<" is not found in dictionary!\n";
}
