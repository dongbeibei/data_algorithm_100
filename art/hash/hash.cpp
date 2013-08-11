/*
 * 暴雪hash
 */


#include <iostream>

using namespace std;

MPQHASHTABLE TestHashTable[nTableSize];
int TestHashCTable[nTableSize];
int TestHashDTable[nTableSize];
key_list test_data[nTableSize];

//生成一个长度为0x500(1280)的cryptTable[1280]
void prepareCryptTable();
//计算lpszkeyName字符串的hash值，其中dwHashType为hash的类型
unsigned long HashString(const char *lpszkeyName, unsigned long dwHashType);
//直接调用上面的HashString，nHashPos就是对应的HASH值
int insert_string(const char *string_in);



void prepareCryptTable()
{
	unsigned long seed = 0x00100001, index1 = 0, index2 = 0, i;

	for(index1=0 ; index1<0x100 ; ++index1)
	{
		for(index2=index1, i=0 ; i<5 ; ++i, index2 += 0x100)
		{
			unsigned long temp1, temp2;

			seed = (seed * 125 + 3) % 0x2AAAAB;
			temp1 = (seed & 0xFFFF)<<0x10;

			seed = (seed * 125 + 3) % 0x2AAAAB;
			temp2 = (seed & 0xFFFF);

			cryptTable[index2] = (temp1 | temp2);
		}
	}
}

unsigned long HashString(const char *lpszkeyName, unsigned long dwHashType)
{
	unsigned char *key = (unsigned char *)lpszkeyName;
	unsigned long seed1 = 0x7FED7FED;
	unsigned long seed2 = 0xEEEEEEEE;
	int ch;

	while(*key != 0)
	{
		ch = *key++;
		seed1 = cryptTable[(dwHashType<<8) + ch] ^ (seed1 + seed2);
		seed2 = ch + seed1 + seed2 + (seed2<<5) + 3;
	}

	return seed1;
}

int insert_string(const char *string_in)
{
	const int HASH_OFFSET = 0, HASH_C = 1, HASH_D = 2;

	unsigned int nHash = HashString(string_in, HASH_OFFSET);
	unsigned int nHashC = HashString(string_in, HASH_C);
	unsigned int nHashD = HashString(string_in, HASH_D);
	unsigned int nHashStart = nHash % nTableSize;
	unsigned int nHashPos = nHashStart;
	int ln, ires = 0;

	while(TestHashTable[nHashPos].bExists)
	{
		if(TestHashCTable[nHashPos] == (int)nHashC && TestHashDTable[nHashPos] == (int)nHashD)
			break;
		else
			nHashPos = (nHashPos + 1) % nTableSize;

		if(nHashPos == nHashStart)
			break;
	}

	ln = strlen(string_in);
	if(!TestHashTable[nHashPos].bExists && (ln < nMaxStrlen))
	{
		TestHashCTable[nHashPos] = nHashC;
		TestHashDTable[nHashPos] = nHashD;

		test_data[nHashPos] = (KEYNODE *)malloc(sizeof(KEYNODE) * 1);
		if(test_data[nHashPos] == NULL)
		{
			printf("10000 EMS ERROR !!!!\n");
			return 0;
		}

		test_data[nHashPos]->pkey = (char *)malloc(ln + 1);
		if(test_data[nHashPos]->pkey == NULL)
		{
			printf("10000 EMS ERROR !!!!\n");
			return 0;
		}

		memset(test_data[nHashPos]->pkey, 0, ln+1);
		strncpy(test_data[nHashPos]->pkey, string_in, ln);
		*((test_data[nHashPos]->pkey) + ln) = 0;
		test_data[nHashPos]->weight = nHashPos;

		TestHashTable[nHashPos].bExists = 1;	
	}
	else
	{
		if(TestHashCTable[nHashPos].bExists)
			printf("30000 in the hash table %s !!!\n", string_in);
		else
			printf("90000 strkey error !!!\n");
	}

	return nHashPos;
}
